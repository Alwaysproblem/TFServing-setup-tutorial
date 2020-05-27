import numpy as np
import pandas as pd
import tensorflow as tf

from deepctr.models import DeepFM, WDL, xDeepFM, AutoInt
from deepctr.inputs import SparseFeat, VarLenSparseFeat, get_feature_names

class FeatureLayer(object):
    def __init__(self,

                 globalSparsePara=None,
                 globalVarlenPara=None,
                 globalNumericPara=None,
                 sparse_features=None,
                 varlen_features=None,
                 numeric_features=None,
                 combiner='mean'
                 ):
        self.sparses = sparse_features
        self.varlens = varlen_features
        self.numerics = numeric_features
        self.globalSparsePara = globalSparsePara
        self.globalVarlenPara = globalVarlenPara
        self.globalNumericPara = globalNumericPara
        self.combiner = combiner
        self.varlen_feature_columns = self.DealWithvarlenFeatureCols()
        self.sparse_feature_columns = self.DealWithSparseFeatureCols()
        self.numerics_feature_columns = self.DealWithNumericFeatureCols()
        self.feature_names = None

    def _DealWithvarlenFeatureCol(self, FeatureName, key2index, max_len):
        return VarLenSparseFeat(SparseFeat(FeatureName, len(key2index) + 1, dtype=tf.int64), max_len, self.combiner)

    def DealWithvarlenFeatureCols(self):
        if self.globalVarlenPara == None:
            return []

        varlen_feature_columns = []
        for vara in self.varlens:
            key2index, max_len = self.globalVarlenPara[vara]
            varlen_feature_columns.append(
                self._DealWithvarlenFeatureCol(vara, key2index, max_len))

        return varlen_feature_columns

    def DealWithSparseFeatureCols(self):
        if self.globalSparsePara == None:
            return []
        return [SparseFeat(feat, len(self.globalSparsePara[feat]) + 2, dtype=tf.int64) for feat in sparse_features]

    def DealWithNumericFeatureCols(self):
        if self.globalNumericPara == None:
            return []

    def __call__(self):
        linear_feature_columns = self.sparse_feature_columns + \
            self.varlen_feature_columns + self.numerics_feature_columns
        dnn_feature_columns = self.sparse_feature_columns + \
            self.varlen_feature_columns + self.numerics_feature_columns

        # feature_names = get_feature_names(linear_feature_columns+dnn_feature_columns)

        return linear_feature_columns, dnn_feature_columns

# import resource
# class MemoryCallback(tf.keras.callbacks.Callback):
#     def on_epoch_end(self, batch, logs={}):
#         with open(os.path.join(os.path.split(__file__)[0], 'Analysis', 'MEM.txt'), 'w+') as f:
#             print(f"The use of mem per epoch is {resource.getrusage(resource.RUSAGE_SELF).ru_maxrss //1024 // 1024}MB.", file=f)

# class SaveModel_Exit(tf.keras.callbacks.Callback):
#     def on_epoch_end(self, batch, logs={}):



if __name__ == "__main__":
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
    train_files_dir = '/home/ubuntu/MyFiles/train/*.tfrecord'
    valid_files_dir = '/home/ubuntu/MyFiles/test/*.tfrecord'

    batchsize = 512  # it should not be 1
    # batchsize = 16384  # it should not be 1
    # chunksize = 1000
    epochs = 20

    # len_train = 6775180
    # len_valid = 2404703
    len_train = 95000
    len_valid = 5000

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

    # def split_target(Dic):
    #     new_x = {}
    #     y = Dic.pop(target)
    #     for f in sparse_features + varlen_features:
    #         new_x[f] = Dic[f]
    #     return (new_x, y)

    # D_train = D_train.map(split_target, num_parallel_calls=num_para)
    # D_valid = D_valid.map(split_target, num_parallel_calls=num_para)

    # for i in D_train.take(1):
    #     print(i)

    # D_train = D_train.shuffle(batchsize)
    D_train = D_train.repeat()
    D_valid = D_valid.repeat()

    # D_train = D_train.cache()
    # D_valid = D_valid.cache()

    D_train = D_train.prefetch(buffer_size=num_para)
    D_valid = D_valid.prefetch(buffer_size=num_para)

    # D_train = D_train.apply(tf.data.experimental.prefetch_to_device('gpu:0', buffer_size=num_para))
    # D_valid = D_valid.apply(tf.data.experimental.prefetch_to_device('gpu:0', buffer_size=num_para))


    # D_train = D_train.map(split_target, num_parallel_calls=num_para)
    # D_valid = D_valid.map(split_target, num_parallel_calls=num_para)

    # for i in D_train.take(1):
    #     print(i)

    strategy = tf.distribute.MirroredStrategy()

    # D_train_dist = strategy.experimental_distribute_dataset(D_train)
    # D_valid_dist = strategy.experimental_distribute_dataset(D_valid)

    D_train_dist = D_train
    D_valid_dist = D_valid


    feature = FeatureLayer(
        globalSparsePara=globalSparsePara,
        globalVarlenPara=globalVarlenPara,
        sparse_features=sparse_features,
        varlen_features=varlen_features
    )

    linear_feature_columns, dnn_feature_columns = feature()

    # model = DeepFM(linear_feature_columns, dnn_feature_columns,
    #                dnn_hidden_units=(32, 16))
    # model = AutoInt(dnn_feature_columns,
    #                dnn_hidden_units=(32, 16))

    # model.compile("adam", loss=tf.losses.BinaryCrossentropy(),
    #               metrics=[tf.keras.metrics.AUC()], )

    with strategy.scope():
        # model = AutoInt(dnn_feature_columns,
        #             dnn_hidden_units=(32, 16))
        model = DeepFM(linear_feature_columns, dnn_feature_columns,
                   dnn_hidden_units=(32, 16))

        model.compile("adam", loss=tf.losses.BinaryCrossentropy(),
                    metrics=[tf.keras.metrics.AUC()], )

    # tf.keras.utils.plot_model(model, "aa.png", show_shapes = True)
    print("model fitting...")
    # model.build(input_shape=(None, len(model.input)))
    # print(model.get_layer(name='input').output_shape)

    # print(model.summary())


    history = model.fit(D_train_dist, epochs=1, verbose=1, validation_data=D_valid_dist,
                        steps_per_epoch=max(len_train // batchsize, 1), validation_steps=max(len_valid // batchsize, 1),)
    #                   use_multiprocessing = True, max_queue_size = num_para, workers = num_para)
    #                   callbacks = [MemoryCallback()])

    print()

    # savedir = './save/xdeepFM/1'
    # savedir = './TFServing-setup-review/save/AutoInt/1'
    # tf.saved_model.save(model, savedir)

    # loaded = tf.saved_model.load(savedir)
    # print(loaded(next(iter(D_valid))))