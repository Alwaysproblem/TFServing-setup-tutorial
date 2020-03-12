#%%
import os
import json

import numpy as np
import tensorflow as tf

from tfrecord_io import Decode

#%%
sparse_features = ["m1", "adid", "adspaceid", "adtype", "nt",
                    "osv", "p_city", "appid"]
varlen_features = ["click_adids", "install_pkgs"]
target = 'flag'

train_files_dir = './records/Example/Train/*.tfrecord'
valid_files_dir = './records/Example/Test/*.tfrecord'

batchsize = 100

col_type = {
    'm1': 'int64',
    'bid': 'int64',
    'adid': 'int64',
    'adspaceid': 'int64',
    'adtype': 'int64',
    'nt': 'int64',
    'appid': 'int64',
    # 'mo': 'string',
    'osv': 'int64',
    'flag': 'int64',
    'p_city': 'int64',
    'install_pkgs': 'int64List',
    'click_adids': 'int64List'
}

globalSparsePara, globalVarlenPara = np.load(
    './Config/globalpara_toy.npy', allow_pickle=True)

#%%
D_train = Decode(train_files_dir, col_type, target, batchsize, cycle_length=None, block_length=batchsize,
                    num_parallel_calls=4, varlens=varlen_features, globalVarlenPara=globalVarlenPara, 
                    sparses=sparse_features, globalSparsePara=globalSparsePara)

print(*D_train.take(1))
# %%
X, y = next(iter(D_train.take(1)))

# %%
for k in X:
    X[k] = X[k].numpy()
    if len(X[k].shape) < 2:
        X[k] = np.expand_dims(X[k], axis = 1)
    X[k] = X[k].tolist()

# %%
with open("request/a_100_toy.json", "w+") as ff:
    json.dump(X, ff)

# %%
