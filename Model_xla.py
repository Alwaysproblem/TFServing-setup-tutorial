#%%
import tensorflow as tf
from tensorflow.keras.layers import Dense, Input
# import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import time
import os
# %matplotlib inline

logdir = os.path.split(os.path.realpath(__file__))[0]
# %%
# generate some data 2-dimension. shape = (10, 2)

noise = np.random.randn(10, 1)
# print(noise.shape)
W = np.array([[5, 3]]).T
x = np.array(np.arange(10))[None, :].T
# print(x.shape)
x_ = np.ones((10, 1))
X = np.concatenate((x_, x), axis = 1)
X = np.array(X, dtype=np.float32)

# print(X.shape, W.shape)
y = X @ W + noise
y = np.array(y, dtype=np.float32)
# print(np.array(y, dtype=np.float32))

# plt.scatter(x, y, s = 10, marker='o', c = 'red')
# plt.show()

data = tf.data.Dataset.from_tensor_slices((2 * X, y))

def parse(x, y):
    
    # change the data type of variables
    x = tf.py_function(lambda z: z, [x], tf.float32)
    y = tf.py_function(lambda z: z, [y], tf.float32)

    # set shape on the dataset info.
    x.set_shape((2,))
    y.set_shape((1,))
    return (x, y)

data = data.map(parse)
data = data.shuffle(10)
data = data.repeat()
data = data.batch(10)

class ToyModel(tf.keras.Model):
    def __init__(self):
        super(ToyModel, self).__init__()
        self.lr = Dense(1)

    def call(self, x):
        x = self.lr(x)
        return x

tf.keras.backend.clear_session()
tf.config.optimizer.set_jit(True)
model = ToyModel()
model.compile('adam', loss = [tf.losses.Huber()], metrics=[tf.metrics.MeanSquaredError()])
# model.build(input_shape=(None, 2))
model.fit(data, epochs = 500, steps_per_epoch = 20)

# save the first version of model.
savedir = './save/Toy_double_xla/1'
tf.saved_model.save(model, savedir)

# check if saved model is correct.
new_model = tf.saved_model.load(savedir)
# print(new_model.summary())
print(new_model(np.array([[1., 1.], [1., 2.]])))