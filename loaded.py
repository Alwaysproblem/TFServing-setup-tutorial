import tensorflow as tf
import numpy as np

import json

from tfrecord_io import Decode
import os

# sparse_features = ["m1", "bid", "adid", "adspaceid", "adtype", "nt",
#                    "osv", "p_city", "appid"]
sparse_features = ["m1", "adid", "adspaceid", "adtype", "nt",
                    "osv", "p_city", "appid"]
varlen_features = ["click_adids", "install_pkgs"]
target = 'flag'

# train_files_dir = './records/Example/Train/*.tfrecord'
# valid_files_dir = './records/Example/Test/*.tfrecord'
train_files_dir = './records/RawData/Train/*.tfrecord'
valid_files_dir = './records/RawData/Test/*.tfrecord'

# batchsize = 512  # it should not be 1
batchsize = 200  # it should not be 1
# chunksize = 1000
epochs = 20

len_train = 6775180
len_valid = 2404703
# len_train = 9500
# len_valid = 500

globalSparsePara, globalVarlenPara = np.load(
    './config/globalpara.npy', allow_pickle=True)

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

num_para = tf.data.experimental.AUTOTUNE
# num_para = 16

D_train = Decode(train_files_dir, col_type, target, batchsize, cycle_length=None, block_length=batchsize,
                    num_parallel_calls=num_para, varlens=varlen_features, globalVarlenPara=globalVarlenPara, 
                    sparses=sparse_features, globalSparsePara=globalSparsePara)
D_valid = Decode(valid_files_dir, col_type, target, batchsize, cycle_length=None, block_length=batchsize,
                    num_parallel_calls=num_para, varlens=varlen_features, globalVarlenPara=globalVarlenPara, 
                    sparses=sparse_features, globalSparsePara=globalSparsePara)

# for i in D_train.take(1):
#     print(i)

# D_train = D_train.shuffle(batchsize)

D_train = D_train.repeat()
D_valid = D_valid.repeat()



#TODO: the batchsize can be change easily with dataset.batch()

savedir = './save/CTR/1'
loaded = tf.saved_model.load(savedir)
infer = loaded.signatures["serving_default"]

import timeit
for x, _ in D_valid.take(1):
    s = timeit.default_timer()
    print(infer(**x))
    e = timeit.default_timer()
    print(f"the time cost is {e - s}")

# tk = {}
# for x, _ in D_valid.take(200):
#     for f in sparse_features + varlen_features:
#         kk = x[f].numpy().tolist()[0]
#         # kk = np.squeeze(kk)
#         # if len(kk.shape) == 0:
#         #     ttt = [kk.tolist()]
#         # else:
#         #     ttt = kk.tolist()
#         tk[f] = kk
#     with open('a_200.json', 'a') as ff:
#         json.dump(tk, ff)
#         print(",", end='', file=ff)
#     # print(infer(**x))