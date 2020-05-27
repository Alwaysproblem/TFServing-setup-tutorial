#%%
import numpy as np
import tensorflow as tf

from tensorflow import feature_column
from tensorflow.keras import layers
from tensorflow.keras.experimental import SequenceFeatures

from DataLoader import CSVLoader
import pandas as pd
#%%
col_type = {
    "aid": "string",
    "click_adid": "stringv",
    "age": "int64",
    # "sex": ,
    "cp": "int64",
    # "trestbps": "int64",
    "chol": "int64",
    # "fbs": "int64",
    # "restecg": "int64",
    # "thalach": "int64",
    # "exang": "int64",
    "oldpeak": "float32",
    # "slope": "int64",
    # "ca": "int64",
    # "thal": "string",
    "target": "int64",
}

#%%
ds = CSVLoader("data/*.csv", col_type, 
            batch_size=2, shuffle=False,
            num_epochs=None,
            varlen_ragged=False,
            varlen_max_len=8,
            label_name='target').load()
#%%
dspd = pd.read_csv('data/toy.csv', usecols=list(col_type))
dspd
#%%
example_batch, label = next(iter(ds))
def demo_dense(feature_column):
  feature_layer = layers.DenseFeatures(feature_column)
  print(feature_layer(example_batch).numpy())

def demo_seq(feature_column):
  feature_layer = SequenceFeatures(feature_column)
  # SequenceFeatures(feature_column) return 2 tensor (sequence_value, sequence_length)
  print(feature_layer(example_batch)[0].numpy())

def demo_seq_in(example_batch, feature_column):
  feature_layer = SequenceFeatures(feature_column)
  print(feature_layer(example_batch))

example_batch
#%%
embedding_size = 3
cp_backets = 5
aid_backets = 5
# %%
# int map to [0, 400) and embedding
cp = feature_column.embedding_column(
    feature_column.categorical_column_with_identity(
      "cp", cp_backets), embedding_size)

demo_dense(cp)
# %%
aid = feature_column.indicator_column(
    feature_column.categorical_column_with_hash_bucket(
      "aid", aid_backets), )

demo_dense(aid)
# %%
aid = feature_column.embedding_column(
    feature_column.categorical_column_with_hash_bucket(
      "aid", aid_backets), embedding_size)

demo_dense(aid)
#%%
age = feature_column.numeric_column('age')
demo_dense(age)
#%%
age = feature_column.indicator_column(
            feature_column.bucketized_column(
                feature_column.numeric_column('age')
                , boundaries = [0, 50, 60, 100]), )

demo_dense(age)
#%%
age_bucket = feature_column.bucketized_column(
                feature_column.numeric_column('age')
                , boundaries = [0, 50, 60, 100])

bucket_size = 100

cross = feature_column.indicator_column(
            feature_column.crossed_column(
                ["aid", age_bucket],
                bucket_size
            ), )

demo_dense(cross)
#%%
backet_seq = 10
click_adid = feature_column.sequence_categorical_column_with_hash_bucket(
    'click_adid',
    backet_seq
)
click_adid = feature_column.embedding_column(click_adid, embedding_size)

demo_seq(click_adid)

#%% 
# start to build linear model
varlen_max_len = 8
embedding_size = 3
backet_click_adid = 10
aid_backets = 10
cp_backets = 5

sparses = [f for f in col_type if col_type[f] in ["int32", "int64"]]
varlens = [feat for feat in col_type
                        if col_type[feat] in ('stringv', 'int32List', 'int64List', 
                                                'float32List', 'float64List')]
dense = [f for f in col_type if col_type[f] in ["float32", "float64"]]
#%%
sparse_feature_columns = []
varlen_feature_columns = []
dense_feature_columns = []

aid = feature_column.embedding_column(
    feature_column.categorical_column_with_hash_bucket(
      "aid", aid_backets), embedding_size)
sparse_feature_columns += [aid]

click_adid = feature_column.sequence_categorical_column_with_hash_bucket(
    'click_adid',
    backet_click_adid
)
click_adid = feature_column.embedding_column(click_adid, embedding_size)
varlen_feature_columns += [click_adid]

age = feature_column.embedding_column(
            feature_column.bucketized_column(
                feature_column.numeric_column('age')
                , boundaries = [0, 50, 60, 100]), embedding_size)
sparse_feature_columns += [age]

cp = feature_column.embedding_column(
    feature_column.categorical_column_with_identity(
      "cp", cp_backets), embedding_size)
sparse_feature_columns += [cp]

chol = feature_column.embedding_column(
    feature_column.categorical_column_with_hash_bucket(
      "chol", aid_backets, dtype=tf.dtypes.int64), embedding_size)
sparse_feature_columns += [chol]

oldpeak = feature_column.numeric_column('oldpeak')
dense_feature_columns += [oldpeak]


#%%
class SumPooling(tf.keras.layers.Layer):
  def __init__(self, **kwargs):
    super(SumPooling, self).__init__(**kwargs)
  
  def build(self, input_shape):
    super(SumPooling, self).build(input_shape)

  def call(self, x, mask=None):
    if mask is None:
      raise ValueError("No mask")
    seq = tf.sequence_mask(mask, maxlen=x.shape[1])
    sum_mask = tf.tile(tf.expand_dims(seq, -1), [1, 1, x.shape[-1]])
    sum_mask = tf.cast(sum_mask, tf.dtypes.float32)
    sum_mask *= x

    res = tf.math.reduce_sum(sum_mask, axis = 1)
    return res
#%%
inputs = {
  "aid": layers.Input(name="aid", shape=(1,), dtype=tf.dtypes.string),
  "click_adid": layers.Input(name="click_adid", 
          shape=(varlen_max_len, ), dtype=tf.dtypes.string),
  "age": layers.Input(name="age", shape=(1,), dtype=tf.dtypes.int64),
  "cp": layers.Input(name="cp", shape=(1,), dtype=tf.dtypes.int64),
  "chol": layers.Input(name="chol", shape=(1,), dtype=tf.dtypes.int64),
  "oldpeak": layers.Input(name="oldpeak", shape=(1,), dtype=tf.dtypes.float32),
}
dense_f_ = layers.DenseFeatures(sparse_feature_columns \
                                  + dense_feature_columns)(inputs)
varlen_f_, seq_len = tf.keras.experimental \
                .SequenceFeatures(varlen_feature_columns)(inputs)
sumpooling = SumPooling()(varlen_f_, mask=seq_len)
# sumpooling = layers.Flatten()(varlen_f_)
concats = tf.keras.layers.Concatenate()([dense_f_, sumpooling])
outputs = layers.Dense(1, activation='sigmoid')(dense_f_)
model = tf.keras.Model(inputs = inputs, outputs=outputs)

# model = tf.keras.Sequential([
#   layers.DenseFeatures(chol),
#   layers.Dense(1, activation='sigmoid')
# ])

model.compile(optimizer='adam', loss=tf.losses.BinaryCrossentropy(), )
# model.build(input_shape = (None, None))
model.summary()
# tf.keras.utils.plot_model(model, "./aa.png", show_shapes=True)
# model.fit(x = example_batch, y=label, epochs = 1)

# %%
model.fit(ds, epochs = 100, steps_per_epoch = 10)

# %%
model.predict(example_batch)

# %%
save_path = 'save/FC/1'
model.save(save_path)

# %%
