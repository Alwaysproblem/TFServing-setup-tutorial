# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'
# %%
import json
import numpy as np
from DataLoader import TFRecordLoader, SPARSES, VARLENS
import tensorflow as tf
from tensorflow.keras import Input, layers
from tensorflow.keras.experimental import SequenceFeatures
from tensorflow.keras.utils import plot_model
feature_column = tf.feature_column

tf.config.experimental_run_functions_eagerly(True)
# %%
col_type = {
    'm1': 'int64',
    'bid': 'int64',
    'adid': 'int64',
    'adspaceid': 'int64',
    'adtype': 'int64',
    'nt': 'int64',
    'appid': 'int64',
    'osv': 'int64',
    'flag': 'int64',
    'p_city': 'int64',
    'install_pkgs': 'int64List',
    'click_adids': 'int64List'
}
label_name = 'flag'
batch_size = 3
embedding_size = 4
epochs = 2
train_path = 'Toydataset/Dataset/ProcessedDataset/train/*.tfrecord'
valid_path = 'Toydataset/Dataset/ProcessedDataset/valid/*.tfrecord'
sparses = [f for f in col_type if col_type[f] in SPARSES and f != label_name]
varlens = [f for f in col_type if col_type[f] in VARLENS and f != label_name]


# %%
with open("Config/config_toy.json") as f:
    sparse_len_dic, varlen_len_dic, varlen_maxlen_f, len_train, len_valid = json.load(f)


# %%
train = TFRecordLoader(train_path, col_type, label_name=label_name, batch_size=batch_size, 
                        block_length=batch_size,).load()
valid = TFRecordLoader(valid_path, col_type, label_name=label_name, batch_size=batch_size, 
                        block_length=batch_size,).load()


# %%
print(*train.take(1))


# %%
[(example, exmp_label)] = [*train.take(1)]
print(exmp_label)
print(example)


# %%
adid = feature_column.categorical_column_with_identity(
    "adid", num_buckets=sparse_len_dic['adid'])
adid_embedding = feature_column.embedding_column(adid, embedding_size, 
                        initializer=tf.keras.initializers.he_normal(seed=None))
adid_layer = layers.DenseFeatures(adid_embedding, name="adid_emb")
adid_layer(example)


# %%
def sparse_embeding_layer(key, embedding_size, vocab_size, name=None, initializer=None):
    cat_col = feature_column.categorical_column_with_identity(
                                    key, num_buckets=vocab_size)
    col_embedding = feature_column.embedding_column(
                        cat_col, embedding_size, initializer=initializer)
    emblayer = layers.DenseFeatures(col_embedding, name=name if name is not None else key + "_emb")
    return emblayer


# %%
adid_layer = sparse_embeding_layer('adid', embedding_size, sparse_len_dic['adid'])


# %%
adid_layer(example)


# %%
varlen_click = feature_column.sequence_categorical_column_with_identity("click_adids", varlen_len_dic["click_adids"])
varlen_click_emb = feature_column.embedding_column(varlen_click, embedding_size, initializer=None)
click_layer = SequenceFeatures(varlen_click_emb)
seq, seq_len = click_layer(example)
seq_mask = tf.sequence_mask(seq_len)
print(f"sequence:\n{seq}\nsequence_length:\n{seq_mask}")


# %%
def varlen_embedding_layer(key, embedding_size, vocab_size, name=None, initializer=None):
    varlen_col = feature_column.            sequence_categorical_column_with_identity(key, vocab_size)
    varlen_emb = feature_column.embedding_column(varlen_col, embedding_size, initializer=None)
    seq_layer = SequenceFeatures(varlen_emb, name = name if name is not None else key + '_seq_emb')
    return seq_layer


# %%
click_layer = varlen_embedding_layer("click_adids", embedding_size, varlen_len_dic["click_adids"])
seq, seq_len = click_layer(example)
seq_mask = tf.sequence_mask(seq_len)
print(f"sequence:\n{seq}\nsequence_length:\n{seq_mask}")


# %%
sparse_embedding_size_dic = {fe: 6 * int(pow(sparse_len_dic[fe], 0.25)) for fe in sparse_len_dic}
varlen_embedding_size_dic = {fe: 6 * int(pow(varlen_len_dic[fe], 0.25)) for fe in varlen_len_dic}
print(sparse_embedding_size_dic)
print(varlen_embedding_size_dic)

#%%
class SumPooling(layers.Layer):
    def __init__(self, mode = "sum", **kwargs):
        self.mode = mode
        super(SumPooling, self).__init__(**kwargs)
    
    def build(self, input_shape):
        super(SumPooling, self).build(input_shape)

    def call(self, x, mask=None, **kwargs):
        if mask is None:
            raise ValueError("No mask")
        seq = tf.sequence_mask(mask, maxlen=x.shape[1])
        sum_mask = tf.tile(tf.expand_dims(seq, -1), [1, 1, x.shape[-1]])
        sum_mask = tf.cast(sum_mask, tf.dtypes.float32)
        sum_mask *= x
        if self.mode == "sum":
            res = tf.math.reduce_sum(sum_mask, axis = 1)
        elif self.mode == "mean":
            res = tf.math.reduce_mean(sum_mask, axis = 1)
        elif self.mode == "max":
            res = tf.math.reduce_max(sum_mask, axis = 1)
        elif self.mode == "min":
            res = tf.math.reduce_min(sum_mask, axis = 1)
        else:
            raise ValueError()
        return res


#%%
def sparse_embed_layer(key, embedding_size, vocab_size, inputs_layer, name=None, initializer=None):
    col_embedding = feature_column.embedding_column(
                        feature_column.categorical_column_with_identity(
                                    key, num_buckets=vocab_size + 1), 
                        embedding_size, initializer=initializer)
    embedding = layers.DenseFeatures(col_embedding, name=name if name is not None else key + "_emb")(inputs_layer)
    return embedding

def varlen_embed_layer(key, embedding_size, vocab_size, inputs_layer, name=None, initializer=None):
    varlen_emb = feature_column.embedding_column(
                        feature_column.sequence_categorical_column_with_identity(
                                    key, vocab_size + 1), embedding_size, initializer=None)
    seq, seq_len = SequenceFeatures(varlen_emb, name = name if name is not None else key + '_seq_emb')(inputs_layer)
    return seq, seq_len

# %%
def DeepVec(sparse_feature_name, varlen_feature_name, target_item_name,
            sparse_len_dic, varlen_len_dic, varlen_maxlen, item_embedding_size = 8,
            hidden_unit_user_info = (80, 20), hidden_unit_target = (80, 20), embedding_size = "auto", combiner='sum'):
    
    # process the embedding size parameter.
    if embedding_size == "auto":
        sparse_embedding_size_dic = {fe: 6 * int(pow(sparse_len_dic[fe], 0.25)) \
                                        for fe in sparse_len_dic}
        varlen_embedding_size_dic = {fe: 6 * int(pow(varlen_len_dic[fe], 0.25)) \
                                        for fe in varlen_len_dic}
    elif isinstance(embedding_size, int):
        sparse_embedding_size_dic = {fe: embedding_size for fe in sparse_len_dic}
        varlen_embedding_size_dic = {fe: embedding_size for fe in varlen_len_dic}
    elif isinstance(embedding_size, dict):
        sparse_embedding_size_dic = {fe: embedding_size[fe] for fe in sparse_len_dic}
        varlen_embedding_size_dic = {fe: embedding_size[fe] for fe in varlen_len_dic}
    else:
        raise ValueError()
    
    if len(sparse_feature_name + varlen_feature_name) == 0:
        raise ValueError("sparse_feature_name and varlen_feature_name are not None.")

    # build the input layers.
    inputs_dic = {}
    for spa in sparse_feature_name:
        inputs_dic.update({spa: Input(shape=(1,), name = spa, dtype=tf.dtypes.int64)})
        
    for var in varlen_feature_name:
        inputs_dic.update({var: Input(shape=(varlen_maxlen[var],), 
                                name = var, dtype = tf.dtypes.int64)})

    # build the user and context info vector part.
    sparse_emb_layers = []
    for spa in sparse_feature_name:
        if spa != target_item_name:
            sparse_emb = sparse_embed_layer(spa, 
                                embedding_size=sparse_embedding_size_dic[spa],
                                vocab_size=sparse_len_dic[spa],
                                inputs_layer=inputs_dic
                                )

            sparse_emb_layers.append(sparse_emb)
    
    varlen_emb_layers = []
    for var in varlen_feature_name:
        varlen_seq, seq_len = varlen_embed_layer(var, 
                              embedding_size=varlen_embedding_size_dic[var],
                              vocab_size=varlen_len_dic[var],
                              inputs_layer=inputs_dic
                            )

        sumpooling_layer = SumPooling(name=f'{var}_sum_pooling', mode=combiner)(
                                    varlen_seq, mask=seq_len)
        varlen_emb_layers.append(sumpooling_layer)
    
    # concat = layers.Concatenate(axis=-1)(sparse_emb_layers + varlen_emb_layers)

    DNN_user = layers.Concatenate(axis=-1)(sparse_emb_layers + varlen_emb_layers)

    for i, u in enumerate(hidden_unit_user_info):
        DNN_user = layers.Dense(u, name=f"DNN_{i}_user_info")(DNN_user)
    # user_info = DNN_user

    DNN_target = sparse_embed_layer(
                            target_item_name, 
                            sparse_embedding_size_dic[target_item_name],
                            vocab_size = sparse_embedding_size_dic[spa],
                            inputs_layer=inputs_dic,
                            name="target_emb_layer")

    # DNN_target = target_vec
    for i, u in enumerate(hidden_unit_target):
        DNN_target = layers.Dense(u, name=f"DNN_{i}_target")(DNN_target)

    outputs = layers.Dot(axes=-1, normalize=True, name='dot_layer')([DNN_user, DNN_target])

    model = tf.keras.Model(inputs=inputs_dic, outputs=outputs)

    return model
#%%
model = DeepVec(sparses, varlens, "adid", sparse_len_dic, 
                varlen_len_dic, varlen_maxlen_f)
model.summary()
# plot_model(model, "DeepVec.png", show_shapes=True)

# %%
train = train.repeat()
model.compile("adam", loss=tf.losses.BinaryCrossentropy())
# print(model.predict(example))
model.fit(train, epochs=1, steps_per_epoch=4)

# %%
