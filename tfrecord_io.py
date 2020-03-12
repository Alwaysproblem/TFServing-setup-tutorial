#%%
import tensorflow as tf
import os
import pandas as pd
import numpy as np


class FileIterator(object):
    def __init__(self, file_name, chunksize, col_type = None, batch=None, sep=',', NAN_fill = {}):
        self.file = file_name
        self.chunksize = chunksize
        self.FileSep = sep
        self.FileLen = 0
        self.batch = batch if batch != None else chunksize
        self.point = 0
        self.col_type = col_type
        self.NAN_fill = NAN_fill

    def __iter__(self):
        """
            Read data from the csv file and make it to generator.
        """
        read_gen = pd.read_csv(
            self.file, chunksize=self.chunksize, sep=self.FileSep, dtype=self.col_type)
        for df in read_gen:
            self._updateLen(len(df))
            # if you want to clean data, please do it here.
            df = df.fillna(value = self.NAN_fill)
            for one_batch in self.split_into_batch(df):
                yield one_batch

    def split_into_batch(self, data_frame):
        l = len(data_frame)
        for _ in range(l):
            b = data_frame.head(self.batch).copy()
            data_frame.drop(b.index, inplace=True)
            if len(b) < 1:
                break
            yield b

    def _updateLen(self, l):
        self.FileLen += l

    # def __next__(self):
    #     return next(self)

    def __len__(self):
        for _ in iter(self):
            pass
        return self.FileLen


class DataStatisticbyChunk(object):
    def __init__(self, 
                file_name, 
                chunksize,
                NAN_fill = {},
                col_type = {},
                SparseFeatures=[], 
                VarlenFeatures=[], 
                NumericFeatures=[], 
                FileSep=",", 
                VarLenSep="|"):
        """
            reading dataset based on pandas. 
        """
        self.file = file_name
        self.chunksize = chunksize
        self.sparses = SparseFeatures
        self.varlens = VarlenFeatures
        self.numerics = NumericFeatures
        self.col_type = col_type
        self.NAN_fill = NAN_fill
        self.file_gen = FileIterator(file_name, chunksize, col_type=col_type, sep=FileSep, NAN_fill=NAN_fill)
        self.varlenspara = {vfeat: [{}, 0] for vfeat in VarlenFeatures}
        # [(key2index dictionary, max length), ]
        self.sparsespara = {feat: {} for feat in SparseFeatures}
        # self.featureNames = NumericFeatures + SparseFeatures + VarlenFeatures
        #  [the number of unique elements, ]
        self.FileSep = FileSep
        self.VarLenSep = VarLenSep
        self.length = 0
        

    def _updataGlobalSparsepara(self, Rdata, featureName):
        """
            record the number of unique elements from one column(feature).
        """
        for item in Rdata[featureName].unique():
            if item not in self.sparsespara[featureName]:
                self.sparsespara[featureName][item] = len(self.sparsespara[featureName]) + 1

    def _updataGlobalVarLenpara(self, Rdata, featureName):
        pieces = Rdata[featureName]

        key2index, max_len = self.varlenspara[featureName]
        for p in pieces:
            keys4index = p.split(sep=self.VarLenSep)
            if max_len <= len(keys4index):
                max_len = len(keys4index)
            for k in keys4index:
                if k not in key2index:
                    # padding items with 0
                    key2index[k] = len(key2index) + 1

        self.varlenspara[featureName][-1] = max_len

    def _updataGlobalNumericpara(self, Rdata, featureName):
        raise NotImplementedError()

    def countLength(self, Rdata):
        self.length += len(Rdata)

    def ObtainGlobalParameters(self):
        """
            obtain the global parameters though reading file once.
        """
        for Rdata in self.file_gen:
            for feat in self.sparses:
                self._updataGlobalSparsepara(Rdata, feat)
            for feat in self.varlens:
                self._updataGlobalVarLenpara(Rdata, feat)
            self.countLength(Rdata)

    @property
    def GlobalSparsePara(self):
        return {feat: self.sparsespara[feat] for feat in self.sparsespara}

    @property
    def GlobalVarlenPara(self):
        return {feat: tuple(self.varlenspara[feat]) for feat in self.varlenspara}

    @property
    def GlobalNumiricPara(self):
        raise NotImplementedError()

    @property
    def FeatureNames(self):
        return self.numerics + self.sparses + self.varlens


def DataProcess(rdata: pd.Series, 
                sparses=[],
                varlens=[],
                numerics=[],
                globalSparsePara={},
                globalVarlenPara={},
                globalNumericPara={}):
    feat = rdata.name
    if feat in sparses:
        rdata = rdata.map(globalSparsePara[feat])
    elif rdata.name in varlens:
        key2index, max_len = globalVarlenPara[feat]
        def split(x: str):
            key_ans = x.split('|')
            return list(map(lambda x: key2index[x], key_ans))
        def pad(x: list):
            return tf.keras.preprocessing.sequence.pad_sequences(
                            [x], maxlen=max_len, padding='post')[0]
        rdata = rdata.map(split)
        rdata = rdata.map(pad)
    elif rdata.name in numerics:
        raise NotImplementedError()

    return rdata


def Encode2File(
        datagen: pd.DataFrame,
        target_file: str,
        col_type: dict,
        NAN_dict: dict,
        chunksize: int,
        sparses=[],
        varlens=[],
        numerics=[],
        globalSparsePara={},
        globalVarlenPara={},
        globalNumericPara={}):

    op_dic = {
        'string': tf.train.BytesList,
        'stringv': tf.train.BytesList,
        'int32': tf.train.Int64List,
        'int64': tf.train.Int64List,
        'int32List': tf.train.Int64List,
        'int64List': tf.train.Int64List,
        'float32': tf.train.FloatList,
        'float64': tf.train.FloatList,
        'float32List': tf.train.FloatList,
        'float64List': tf.train.FloatList
    }

    feature_key_value_pair = {}
    ij = 1
    with tf.io.TFRecordWriter(target_file) as tfwriter:
        for datad in datagen:
            datad = datad.fillna(value = NAN_dict)
            datad = datad.transform(DataProcess, sparses = sparses, varlens=varlens, numerics = numerics,
                        globalSparsePara=globalSparsePara, globalVarlenPara=globalVarlenPara, globalNumericPara=globalNumericPara)
            ij = 1
            for _, rdata in datad.iterrows():
                print("*" * (ij // 1000 + 1), end='\r')
                ij += 1
                for col in col_type:
                    if col_type[col] in ["string", "stringv"]:
                        # rdata = rdata.fillna("#")
                        if isinstance(rdata[col], np.ndarray) or isinstance(rdata[col], list):
                            feature_key_value_pair[col] = tf.train.Feature(
                                                            bytes_list = \
                                                                op_dic[col_type[col]](value = [c.encode('utf-8') for c in rdata[col]])
                                                            )
                        else:
                            feature_key_value_pair[col] = tf.train.Feature(
                                                            bytes_list = \
                                                                op_dic[col_type[col]](value = [rdata[col].encode('utf-8')])
                                                            )
                    elif col_type[col] in ['float32', 'float64', 'float32List', 'float64List']:
                        # rdata = rdata.fillna(0)
                        tmp = [rdata[col]]
                        if isinstance(rdata[col], np.ndarray) or isinstance(rdata[col], list):
                            tmp = rdata[col]
                        feature_key_value_pair[col] = tf.train.Feature(
                                                            float_list = \
                                                                op_dic[col_type[col]](value = tmp)
                                                            )
                    elif col_type[col] in ['int32', 'int64', 'int32List', 'int64List']:
                        # rdata = rdata.fillna(0)
                        tmp = [rdata[col]]
                        if isinstance(rdata[col], np.ndarray) or isinstance(rdata[col], list):
                            tmp = rdata[col]
                        feature_key_value_pair[col] = tf.train.Feature(
                                                            int64_list = \
                                                                op_dic[col_type[col]](value = tmp)
                                                            )

                features = tf.train.Features(feature = feature_key_value_pair)
                sample = tf.train.Example(features = features)

                tfwriter.write(sample.SerializeToString())
        
            print()


def Decode(file_paths: list, col_type: dict, target: str, batchsize: int,
           num_parallel_calls=None, buffer_size=None, block_length=1, cycle_length=None,
           sparses=[], varlens=[], numerics=[],
           globalSparsePara={}, globalVarlenPara={}, globalNumericPara={}):
    op_dic = {
            'stringv': tf.io.VarLenFeature(tf.string),
            'string': tf.io.FixedLenFeature((), tf.string),
            'int32': tf.io.FixedLenFeature((), tf.int32),
            'int64': tf.io.FixedLenFeature((), tf.int64),
            'float32': tf.io.FixedLenFeature((), tf.float32),
            'float64': tf.io.FixedLenFeature((), tf.float64),
            'int32List': tf.io.VarLenFeature(tf.int32),
            'int64List': tf.io.VarLenFeature(tf.int64),
            'float32List': tf.io.VarLenFeature(tf.float32),
            'float64List': tf.io.VarLenFeature(tf.float64),
        }
    feature_key_value_pair = {}
    for col in col_type:
        feature_key_value_pair[col] = op_dic[col_type[col]]

    def map_decoder(serialized_example):
        
        sample = tf.io.parse_example(serialized_example, feature_key_value_pair)

        if len(varlens) != 0 and len(globalVarlenPara) != 0:
            for v in varlens:
                sample[v] = tf.sparse.to_dense(sample[v])
                # sample[v].set_shape((tf.newaxis, globalVarlenPara[v][-1]))

        y = sample.pop(target)
        return (sample, y)
        # return sample
    
    files = tf.data.Dataset.list_files(file_paths)
    def trans(x):
        return tf.data.TFRecordDataset(x).batch(batchsize)\
                        .map(map_decoder, num_parallel_calls=num_parallel_calls)
    if cycle_length is not None:
        dataset = files.interleave(trans,
                        cycle_length=cycle_length,
                        block_length=block_length,
                        num_parallel_calls=num_parallel_calls)
    else:
        dataset = files.interleave(trans,
                        block_length=block_length,
                        num_parallel_calls=num_parallel_calls)

    # dataset = dataset.batch(batchsize)
    # dataset = dataset.map(map_decoder, num_parallel_calls=num_parallel_calls)

    # for i in dataset.take(1):
    #     print(i)

    return dataset

# an another way to parse data from string.
# for raw_record in raw_dataset.take(1):
#     example = tf.train.Example()
#     example.ParseFromString(raw_record.numpy())
#     print(example)
#     a = example.features.feature
#     print(a)
#     raw_img = a['m1'].int64_list.value[0]

# col_name = \
#     ['m1','bid','adid','adspaceid','adspacetype','adtype','nt','appid','adname','mo',
#     'osv','reqtime','pdt','flag','p_city','install_pkgs','click_adids']

# samples = Decode(file_path, col_type)

# def fn(x):
#     x['m1'].numpy()
#     return x

# def py_fn(x):
#     return tf.py_function(fn, [x], [])

# s = samples.map(py_fn)
# # for i in samples:
# #     print(i['m1'].numpy())

if __name__ == "__main__":
    # from DeepCtrTryV3_3 import DataStatisticbyChunk

    sparse_features = ["m1", "bid", "adid", "adspaceid", "adtype", "nt",
                       "osv", "p_city", "appid"]
    varlen_features = ["click_adids", "install_pkgs"]
    target = 'flag'

    col_types = {
        'm1': np.object,
        'bid': np.object,
        'adid': np.object,
        'adspaceid': np.int64,
        'adtype': np.int64,
        'nt': np.int64,
        'appid':np.int64,
        # 'mo': np.object,
        'osv': np.object,
        'flag':np.int64,
        'p_city': np.object,
        'install_pkgs': np.object,
        'click_adids': np.object
    }

    col_type = {
        'm1': 'int64',
        'bid': 'int64',
        'adid': 'int64',
        'adspaceid': 'int64',
        'adtype': 'int64',
        'nt': 'int64',
        'appid':'int64',
        # 'mo': 'string',
        'osv': 'int64',
        'flag':'int64',
        'p_city': 'int64',
        'install_pkgs': 'int64List',
        'click_adids': 'int64List'
    }

    NAN_dict = {
        'm1': '#',
        'bid': '#',
        'adid': 0,
        'adspaceid': 0,
        'adspacetype': 0,
        'adtype': 0,
        'nt': 0,
        'appid':0,
        'adname': '#',
        'mo': '#',
        'osv': '#',
        'reqtime': '#',
        'pdt': 0,
        'flag':0,
        'p_city': '#',
        'install_pkgs': '#',
        'click_adids': '#'
    }

    # sep_sys = os.path.sep
    sep_sys = '/'
    chunksize = 100000

    config_base = '.'
    config_folder = 'config'
    config_name = 'globalpara.npy'
    
    datadir = 'data'
    global_file_name = 'train_10000.csv'
    source_file_name = 'corpus_520_1016_1018.csv'
    source_file_namev = 'corpus_520_1019.csv'
    tfr_file_name = "corpus_520_1016_1018.tfrecords"
    tfr_file_namev = "corpus_520_1019.tfrecords"
    # global_file_name = 'corpus_520_1016_1019.csv'
    # source_file_name = 'valid_1000.csv'

    train_tfr_dir = './records/train/*.tfrecord'
    valid_tfr_dir = './records/test/*.tfrecord'


    # print(__file__)
    base_paths = __file__.split(sep_sys)
    # print(base_paths)
    base_paths.pop()
    # base_paths.pop()
    base_paths = sep_sys.join([*base_paths, datadir])

    file_base_path = __file__.split(sep_sys)
    file_base_path.pop()
    # file_base_path.pop()

    tffile_base_path = __file__.split(sep_sys)
    tffile_base_path.pop()

    file_Global = sep_sys.join([base_paths, global_file_name])

    source_file = sep_sys.join([*file_base_path, datadir, source_file_name])
    source_filev = sep_sys.join([*file_base_path, datadir, source_file_namev])

    tfr_file_path = sep_sys.join([*tffile_base_path, "records", tfr_file_name])
    tfr_file_pathv = sep_sys.join([*tffile_base_path, "records", tfr_file_namev])

    config_path = os.path.join(config_base, config_folder, config_name)

    # get global parameter.
    Globals = DataStatisticbyChunk(
        file_Global, chunksize, SparseFeatures= sparse_features, VarlenFeatures= varlen_features, col_type=col_types, NAN_fill=NAN_dict)
    Globals.ObtainGlobalParameters()

    globalSparsePara, globalVarlenPara = Globals.GlobalSparsePara, Globals.GlobalVarlenPara

    np.save(config_path, (globalSparsePara, globalVarlenPara))

    globalSparsePara, globalVarlenPara = np.load(config_path, allow_pickle = True)

    datagen = pd.read_csv(source_file, dtype = col_types, chunksize=chunksize, 
                            encoding = 'utf-8', iterator=True, usecols=sparse_features + varlen_features + [target])

    datagenv = pd.read_csv(source_filev, dtype = col_types, chunksize=chunksize, 
                            encoding = 'utf-8', iterator=True, usecols=sparse_features + varlen_features + [target])

    Encode2File(datagen, tfr_file_path, col_type, NAN_dict, chunksize, 
                    sparses=sparse_features, varlens=varlen_features, 
                    globalSparsePara = globalSparsePara, globalVarlenPara = globalVarlenPara)

    Encode2File(datagenv, tfr_file_pathv, col_type, NAN_dict, chunksize, 
                    sparses=sparse_features, varlens=varlen_features, 
                    globalSparsePara = globalSparsePara, globalVarlenPara = globalVarlenPara)

    # dataset = Decode(tfr_file_path, col_type)
    # datasetv = Decode(tfr_file_pathv, col_type)
    batchsize = 16384
    num_para = tf.data.experimental.AUTOTUNE

    dataset = Decode(train_tfr_dir, col_type, target, batchsize, block_length=batchsize,
                        num_parallel_calls=num_para, varlens=varlen_features, globalVarlenPara=globalVarlenPara)

    datasetv = Decode(valid_tfr_dir, col_type, target, batchsize, block_length=batchsize,
                        num_parallel_calls=num_para, varlens=varlen_features, globalVarlenPara=globalVarlenPara)

    for i in dataset.take(1):
        print(i)

    for i in datasetv.take(1):
        print(i)
