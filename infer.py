#%%
import numpy as np
import tensorflow as tf

#%%
# 1
loaded = tf.saved_model.load("save/").signatures["serving_default"]
print(loaded(**{"userid": tf.constant([['0']]), 
        "adid": tf.constant([["Zootopia"]])}))
#%%
#2
km = tf.keras.models.load_model("save")
print(km.predict({"userid": tf.constant([['0']]), 
        "adid": tf.constant([["Zootopia"]])}))
