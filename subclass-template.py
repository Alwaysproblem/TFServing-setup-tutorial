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
class Logistic(tf.keras.models.Model):
    def __init__(self, hidden_size = 5, output_size=1, dynamic=False, **kwargs):
        '''
        name: String name of the model.
        dynamic: (Subclassed models only) Set this to `True` if your model should
            only be run eagerly, and should not be used to generate a static
            computation graph. This attribute is automatically set for Functional API
            models.
        trainable: Boolean, whether the model's variables should be trainable.
        dtype: (Subclassed models only) Default dtype of the model's weights (
            default of `None` means use the type of the first input). This attribute
            has no effect on Functional API models, which do not have weights of their
            own.
        '''
        super().__init__(dynamic=dynamic, **kwargs)
        self.InputLayer = tf.keras.Input(shape=(2,))
        # self.InputLayer = {"a": tf.keras.Input(shape=(2,)), "b": tf.keras.Input(shape=(2,))}
        self.hidden_size = hidden_size
        self.dense = layers.Dense(hidden_size, name = "linear")
        self.outlayer = layers.Dense(output_size, 
                        activation = 'sigmoid', name = "out_layer")
        
        # add this method, it will build model automatically as TF says. 
        # this _set_inputs is like tf.keras.Model(inputs=...)
        self._set_inputs(self.InputLayer)

    # for 2.2 there is no need to think about signature definination name.
    # @tf.function(input_signature=[tf.TensorSpec(shape=(None, 2), dtype=tf.float32)])
    # @tf.function
    def call(self, X):
        X = self.dense(X)
        Y = self.outlayer(X)
        return Y

#%%
model = Logistic()
model.summary()

# %%
optimizer=tf.keras.optimizers.Adam()
loss=tf.keras.losses.BinaryCrossentropy()
metrics=tf.keras.metrics.AUC()

#%%
# @tf.function # in graph mode
def losses(y_true, y_pred, sample_weight=None, loss_obj=loss):
    return loss_obj(y_true, y_pred, sample_weight)

#%%
# @tf.function # in graph mode
def Metrics(y_true, y_pred, sample_weight=None, metrics=metrics):
    metrics.update_state(y_true, y_pred, sample_weight)
    return metrics.result()
#%%
# @tf.function # in graph mode
def grad(model, inputs, labels):
    
    with tf.GradientTape() as tape:
        pred = model(inputs)
        loss_value = losses(labels, pred)
        labels = tf.expand_dims(labels, axis=1)
        metr = Metrics(labels, pred)
    
    return loss_value, tape.gradient(loss_value, model.trainable_variables), metr

# %%
# @tf.function # in graph mode
def train_on_batch(model, inputs, labels, opt=optimizer):
    closs, cgrad, cmetric = grad(model, inputs, labels)
    opt.apply_gradients(zip(
        cgrad,
        model.trainable_variables
    ))
    return closs, cmetric

#%%
for e in range(epochs):
    for ind in range(len(X_train)):
        loss_value, cmetric = train_on_batch(model, X_train[ind][None, :], 
                np.expand_dims(y_train[ind], axis=0))
    # tf.print(f"Epochs {e}: loss {loss_value.numpy()}, metric:{cmetric.numpy()}") # in graph mode
    print(f"Epochs {e}: loss {loss_value.numpy()}, metric:{cmetric.numpy()}")

#%%
model.save("save/subclass/1")