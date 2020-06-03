# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'

#%%
import tensorflow as tf
from tensorflow.keras import Input, layers
import matplotlib.pyplot as plt
import numpy as np
import time
import os
from datetime import datetime
from sklearn.model_selection import train_test_split as tvsplit
# disable logging warning and error
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
tf.config.experimental_run_functions_eagerly(True)
#%%
sample_n = 100
epochs = 50
#%%
meana = np.array([1, 1])
cova = np.array([[0.1, 0],[0, 0.1]])

meanb = np.array([2, 2])
covb = np.array([[0.1, 0],[0, 0.1]])

x_red = np.random.multivariate_normal(mean=meana, cov = cova, size=sample_n)
x_green = np.random.multivariate_normal(mean=meanb, cov = covb, size=sample_n)

y_red = np.array([1] * sample_n)
y_green = np.array([0] * sample_n)

plt.scatter(x_red[:, 0], x_red[:, 1], c = 'red' , marker='.', s = 30)
plt.scatter(x_green[:, 0], x_green[:, 1], c = 'green', marker='.', s = 30)
# plt.show()

X = np.concatenate([x_red, x_green]).astype(np.float32)
y = np.concatenate([y_red, y_green]).astype(np.float32)

#%%
X_train, X_test, y_train, y_test = tvsplit(X, y)

#%%
def LinearModel(hidden=5, output=1):
    inputs = tf.keras.Input((2,), name="data_in")
    x = tf.keras.layers.Dense(hidden)(inputs)
    out = tf.keras.layers.Dense(output, activation="sigmoid")(x)

    model = tf.keras.Model(inputs= inputs, outputs=out)
    return model

#%%
loss = tf.losses.BinaryCrossentropy()
opt = tf.keras.optimizers.Adam()
metric = tf.metrics.AUC()

model = LinearModel()
model.compile(opt, loss=loss, metrics = [metric])

# %%
model.fit(x=X_train, y=y_train, validation_data=(X_test, y_test), batch_size = 3, epochs = 10)

# %%
model.save("save/monitor/1")

# %%
