#%%
import json

import numpy as np
import tensorflow as tf
from tensorflow.keras import Input, layers
# from tensorflow.keras.experimental import SequenceFeatures
# from tensorflow.keras.utils import plot_model

from DataLoader import SPARSES, VARLENS, CSVLoader

feature_column = tf.feature_column

#%%
col_type = {
    "userid": "string",
    "adid": "string",
    "label": "int64"
}
batch_size = 8
path_train = "Toydataset/user2item.csv"
path_valid = "Toydataset/valid.csv"
embedding_size = 4
vector_size = 4
length = {
    "userid": 5,
    "adid": 27
}
epochs = 200
len_train = 130
len_valid = 40

#%%
userids = []
with open("Config/userid.txt") as uf:
    for line in uf:
        userids.append(line.strip())

adids = []
with open("Config/Vocab.txt") as vf:
    for line in vf:
        adids.append(line.strip())

vocab = {
    "userid": userids,
    "adid": adids
}
#%%
Data_train = CSVLoader(path_train, col_type, batch_size,
                        label_name="label", 
                        prefetch_buffer_size=tf.data.experimental.AUTOTUNE).load()
Data_valid = CSVLoader(path_valid, col_type, batch_size,
                        label_name="label", 
                        prefetch_buffer_size=tf.data.experimental.AUTOTUNE, ).load()

# print(*Data_train.take(2))

# %%
class Sigmoid(layers.Layer):
    def call(self, X):
        outcome = tf.nn.sigmoid(X)
        return outcome


#%%
def user2item(feature_name, target_name, vocablist, embedding_size):

    inputs = {
        feature_name: Input(name = feature_name, shape=(1,), dtype = tf.dtypes.string),
        target_name: Input(name = target_name, shape=(1,), dtype = tf.dtypes.string)
    }

    # user_emb_col = feature_column.embedding_column(feature_column.\
    #     categorical_column_with_vocabulary_list(
    #     feature_name, vocablist[feature_name]), embedding_size, 
    #     initializer = tf.keras.initializers.he_normal(seed=None)
    # )
    # target_emb_col = feature_column.embedding_column(feature_column.\
    #     categorical_column_with_vocabulary_list(
    #     target_name, vocablist[target_name]), embedding_size, 
    #     initializer = tf.keras.initializers.he_normal(seed=None)
    # )

    user_emb_col = feature_column.embedding_column(feature_column.\
        categorical_column_with_vocabulary_file(
        feature_name, vocabulary_file='Config/userid.txt', num_oov_buckets=5),
        embedding_size, 
        initializer = tf.keras.initializers.he_normal(seed=None)
    )
    target_emb_col = feature_column.embedding_column(feature_column.\
        categorical_column_with_vocabulary_file(
        target_name, vocabulary_file='Config/Vocab.txt', default_value=0), embedding_size, 
        initializer = tf.keras.initializers.he_normal(seed=None)
    )

    user_info = layers.DenseFeatures(user_emb_col, name="user_info")(inputs)
    target_info = layers.DenseFeatures(target_emb_col, name="target_info")(inputs)

    # user_info = layers.Dense(embedding_size, activation='elu')(user_info)
    # target_info = layers.Dense(embedding_size, activation='elu')(target_info)

    outputs = layers.Dot(axes=-1)([user_info, target_info])
    # outputs = layers.Dot(axes=-1, normalize = True)([user_info, target_info])
    outputs = layers.BatchNormalization(name="BN")(outputs)
    # sub = user_info - target_info
    # outputs = tf.sqrt(tf.reduce_sum(tf.square(sub), axis = 1, keepdims = True))
    outputs = Sigmoid()(outputs)
    # outputs = layers.Dense(1, activation='sigmoid')(outputs)
 
    model = tf.keras.Model(inputs=inputs, outputs=outputs)

    return model

#%%
model = user2item("userid", "adid", vocab, embedding_size)
model.summary()

#%%
train_steps = max(len_train // batch_size + 1, 1)
valid_steps = max(len_valid // batch_size + 1, 1)
model.compile(optimizer=tf.optimizers.Adam(0.05),
                # loss = tf.keras.losses.MeanSquaredError(), 
                loss = tf.keras.losses.BinaryCrossentropy(), 
                metrics = [tf.keras.metrics.AUC()])
model.fit(Data_train, epochs = epochs, steps_per_epoch = train_steps,
          validation_data=Data_valid, validation_steps=valid_steps)
#%%
def userEmbedding(feature_name, vocablist, embedding_size):
    inputs = {
        feature_name: Input(name = feature_name, shape=(1,), dtype = tf.dtypes.string),
    }

    user_emb_col = feature_column.embedding_column(feature_column.\
        categorical_column_with_vocabulary_file(
        feature_name, vocabulary_file='Config/userid.txt', num_oov_buckets=5),
        embedding_size, 
    )
    # user_emb_col = feature_column.embedding_column(feature_column.categorical_column_with_vocabulary_list(
    #     feature_name, vocablist[feature_name]), embedding_size
    # )

    user_info = layers.DenseFeatures(user_emb_col, name="user_info")(inputs)

    model = tf.keras.Model(inputs=inputs, outputs=user_info)
    return model

uidModel = userEmbedding("userid", vocab, embedding_size)
uidModel.get_layer("user_info").set_weights(model.get_layer("user_info").get_weights())

#%%
def adidEmbedding(target_name, vocablist, embedding_size):
    inputs = {
        target_name: Input(name = target_name, shape=(1,), dtype = tf.dtypes.string)
    }

    # target_emb_col = feature_column.embedding_column(feature_column.categorical_column_with_vocabulary_list(
    #     target_name, vocablist[target_name]), embedding_size)

    target_emb_col = feature_column.embedding_column(feature_column.\
        categorical_column_with_vocabulary_file(
        target_name, vocabulary_file='Config/Vocab.txt', default_value=0), embedding_size, 
    )

    target_info = layers.DenseFeatures(target_emb_col, name="target_info")(inputs)

    model = tf.keras.Model(inputs=inputs, outputs=target_info)
    return model

adidModel = adidEmbedding("adid", vocab, embedding_size)
adidModel.get_layer("target_info").set_weights(model.get_layer("target_info").get_weights())

#%%
def Cosdis(a, b):
    a /= np.sqrt(np.sum(a ** 2))
    b /= np.sqrt(np.sum(b ** 2))
    # b = np.exp(b)

    return a @ b.T

def sigmoidDis(a, b):
    return 1 / (1 + np.exp(- a @ b.T))

# %%
# a0 = uidModel(np.array([['0'.encode()]])).numpy()
# b0 = adidModel(np.array([['Hang_Over'.encode()]])).numpy()
# c0 = adidModel(np.array([['Harry_Potter'.encode()]])).numpy()
# dsp = Cosdis(a0, b0)
# dsn = Cosdis(a0, c0)
# print(Cosdis(a0, b0))
# print(Cosdis(a0, c0))
# print(sigmoidDis(a0, b0))
# print(sigmoidDis(a0, c0))
# print(Cosdis(np.exp(a0), np.exp(b0)))
# print(Cosdis(np.exp(a0), np.exp(c0)))

#%%
def getOfflineWeights(feature_name, model, normalize = True):
    inp = np.array([[feature_name.encode()]])
    if normalize :
        out = model.predict(inp)
        out /= np.sqrt(np.sum(out ** 2))
        return out.squeeze().tolist()
    else:
        return model.predict(inp).squeeze().tolist()

getOfflineWeights("0", uidModel)
#%%
userW = {fe: getOfflineWeights(fe, uidModel) for fe in userids}
adidW = {fe: getOfflineWeights(fe, adidModel) for fe in adids}

#%%
with open("Weights/uid.json", "w+") as uf:
    json.dump(userW, uf)

with open("Weights/aid.json", "w+") as af:
    json.dump(adidW, af)

# %%
# model.save("save/")
tf.saved_model.save(model, "save/Toy/1")

#%%

# %%
