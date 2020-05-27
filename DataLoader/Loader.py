import tensorflow as tf
import multiprocessing as mlp

class FileTypeLoader(object):
    def __init__(self, **kwargs):
        """
        base class for FIleloader.
        """
        pass

    def _loadfiles(self, file_path):
        """
        load a file
        """
        raise NotImplementedError()

    def _loadfile(self, file_paths):
        """
        load files or load files with regular expression.
        """
        raise NotImplementedError()

    def load(self, path):
        """
        load dataset api

        return tensorflow dataset object.
        """
        raise NotImplementedError()

class TFRecordLoader(FileTypeLoader):
    def __init__(self, file_paths: list, col_type: dict, batch_size: int, label_name=None,
                 num_parallel_calls=None, block_length=1, cycle_length=None,
                 omit_label = False, **kwargs):
        """
        Args:
            file_pattern: List of files or patterns of file paths containing TFrecords. See tf.io.gfile.glob for pattern rules.
            col_type: An dictionary of each column data type.
            batch_size: An int representing the number of records to combine in a single batch.
            label_name: An optional string corresponding to the label column. If provided, the data for this column is returned as a separate Tensor from the features dictionary.
            omit_label: An optional string corresponding to eliminating the label from dataset.
            cycle_length: (Optional.) The number of input elements that will be processed concurrently. If not specified, the value will be derived from the number of available CPU cores. If the num_parallel_calls argument is set to tf.data.experimental.AUTOTUNE, the cycle_length argument also identifies the maximum degree of parallelism.
            block_length: (Optional.) The number of consecutive elements to produce from each input element before cycling to another input element.
            num_parallel_calls: (Optional.) If specified, the implementation creates a threadpool, which is used to fetch inputs from cycle elements asynchronously and in parallel. The default behavior is to fetch inputs from cycle elements synchronously with no parallelism. If the value tf.data.experimental.AUTOTUNE is used, then the number of parallel calls is set dynamically based on available CPU.
        
        Returns:
            A dataset, where each element is a (features, labels) tuple or feature dictionary that corresponds to a batch of batch_size TFRecord. 
        """
        self.file_paths = file_paths
        self.col_type = col_type
        self.label_name = label_name
        self.batch_size = batch_size
        self.num_parallel_calls = num_parallel_calls if num_parallel_calls else mlp.cpu_count()
        self.block_length  = block_length
        self.cycle_length = cycle_length
        self.sparses = [feat for feat in col_type
                        if col_type[feat] in ['int32', 'int64']]
        self.varlens = [feat for feat in col_type
                        if col_type[feat] in ['stringv', 'int32List', 'int64List', 'float32List', 'float64List']]
        self.numerics = [feat for feat in col_type
                        if col_type[feat] in ['float32', 'float64']]
        self.omit_label = omit_label
        self._opdic = {
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
        self.feature_key_value_pair = {col: self._opdic[col_type[col]] for col in col_type}

    def load(self):
        """
        load dataset api

        return tensorflow dataset object.
        """
        def map_decoder(serialized_example):
            #TODO: string to hash id or decode bytes
            sample = tf.io.parse_example(serialized_example, self.feature_key_value_pair)

            if len(self.varlens) != 0:
                for v in self.varlens:
                    sample[v] = tf.sparse.to_dense(sample[v])
                    # sample[v].set_shape((tf.newaxis, globalVarlenPara[v]))
            
            if self.label_name:
                y = sample.pop(self.label_name)
                if self.omit_label == True:
                    return sample
                else:
                    return (sample, y)
            else:
                return sample
        
        files = tf.data.Dataset.list_files(self.file_paths)
        if self.cycle_length is not None:
            datasetV = files.interleave(lambda x: 
                            tf.data.TFRecordDataset(x).batch(self.batch_size)\
                            .map(map_decoder, num_parallel_calls=self.num_parallel_calls),
                            cycle_length=self.cycle_length,
                            block_length=self.block_length,
                            num_parallel_calls=self.num_parallel_calls)
        else:
            datasetV = files.interleave(lambda x: 
                            tf.data.TFRecordDataset(x).batch(self.batch_size)\
                            .map(map_decoder, num_parallel_calls=self.num_parallel_calls),
                            block_length=self.block_length,
                            num_parallel_calls=self.num_parallel_calls)

        return datasetV

    @property
    def Sparses(self):
        return self.sparses
    
    @property
    def Varlens(self):
        return self.varlens

    @property
    def label(self):
        return self.label_name


class CSVLoader(FileTypeLoader):
    def __init__(self,
                file_pattern,
                col_type,
                batch_size,
                column_names=None,
                column_defaults=None,
                label_name=None,
                select_columns=None,
                field_delim=',',
                varlen_field_delim='|',
                varlen_ragged=True,
                varlen_filld_value=None,
                varlen_max_len=None,
                use_quote_delim=True,
                na_value='',
                header=True,
                num_epochs=None,
                shuffle=True,
                shuffle_buffer_size=10000,
                shuffle_seed=None,
                prefetch_buffer_size=None,
                num_parallel_reads=None,
                sloppy=False,
                num_rows_for_inference=100,
                compression_type=None,
                ignore_errors=False,
                use_hash=False,
                **kwargs):
        """
        Args:
            file_pattern: List of files or patterns of file paths containing CSV records. See tf.io.gfile.glob for pattern rules.
            col_type: An dictionary of each column data type.
            batch_size: An int representing the number of records to combine in a single batch.
            column_names: An optional list of strings that corresponds to the CSV columns, in order. One per column of the input record. If this is not provided, infers the column names from the first row of the records. These names will be the keys of the features dict of each dataset element.
            column_defaults: A optional list of default values for the CSV fields. One item per selected column of the input record. Each item in the list is either a valid CSV dtype (float32, float64, int32, int64, or string), or a Tensor with one of the aforementioned types. The tensor can either be a scalar default value (if the column is optional), or an empty tensor (if the column is required). If a dtype is provided instead of a tensor, the column is also treated as required. If this list is not provided, tries to infer types based on reading the first num_rows_for_inference rows of files specified, and assumes all columns are optional, defaulting to 0 for numeric values and "" for string values. If both this and select_columns are specified, these must have the same lengths, and column_defaults is assumed to be sorted in order of increasing column index.
            label_name: A optional string corresponding to the label column. If provided, the data for this column is returned as a separate Tensor from the features dictionary, so that the dataset complies with the format expected by a tf.Estimator.train or tf.Estimator.evaluate input function.
            select_columns: An optional list of integer indices or string column names, that specifies a subset of columns of CSV data to select. If column names are provided, these must correspond to names provided in column_names or inferred from the file header lines. When this argument is specified, only a subset of CSV columns will be parsed and returned, corresponding to the columns specified. Using this results in faster parsing and lower memory usage. If both this and column_defaults are specified, these must have the same lengths, and column_defaults is assumed to be sorted in order of increasing column index.
            field_delim: An optional string. Defaults to ",". Char delimiter to separate fields in a record.
            varlen_field_delim: An optional string. Defaults to "|". Char delimiter to separate variant length feature fields in a record.
            use_quote_delim: An optional bool. Defaults to True. If false, treats double quotation marks as regular characters inside of the string fields.
            na_value: Additional string to recognize as NA/NaN.
            header: A bool that indicates whether the first rows of provided CSV files correspond to header lines with column names, and should not be included in the data.
            num_epochs: An int specifying the number of times this dataset is repeated. If None, cycles through the dataset forever.
            shuffle: A bool that indicates whether the input should be shuffled.
            shuffle_buffer_size: Buffer size to use for shuffling. A large buffer size ensures better shuffling, but increases memory usage and startup time.
            shuffle_seed: Randomization seed to use for shuffling.
            prefetch_buffer_size: An int specifying the number of feature batches to prefetch for performance improvement. Recommended value is the number of batches consumed per training step. Defaults to auto-tune.
            num_parallel_reads: Number of threads used to read CSV records from files. If >1, the results will be interleaved. Defaults to 1.
            sloppy: If True, reading performance will be improved at the cost of non-deterministic ordering. If False, the order of elements produced is deterministic prior to shuffling (elements are still randomized if shuffle=True. Note that if the seed is set, then order of elements after shuffling is deterministic). Defaults to False.
            num_rows_for_inference: Number of rows of a file to use for type inference if record_defaults is not provided. If None, reads all the rows of all the files. Defaults to 100.
            compression_type: (Optional.) A tf.string scalar evaluating to one of "" (no compression), "ZLIB", or "GZIP". Defaults to no compression.
            ignore_errors: (Optional.) If True, ignores errors with CSV file parsing, such as malformed data or empty lines, and moves on to the next valid CSV record. Otherwise, the dataset raises an error and stops processing when encountering any invalid records. Defaults to False.
        
        Returns:
            A dataset, where each element is a (features, labels) tuple that corresponds to a batch of batch_size CSV rows. The features dictionary maps feature column names to Tensors containing the corresponding column data, and labels is a Tensor containing the column data for the label column specified by label_name.
        """
        self.typedic = {
            'stringv': tf.string,
            'string': tf.string,
            'int32': tf.int32,
            'int64': tf.int64,
            'float32': tf.float32,
            'float64': tf.float64,
            'int32List': tf.int32,
            'int64List': tf.int64,
            'float32List': tf.float32,
            'float64List': tf.float64,
        }
        self.file_pattern=file_pattern
        self.col_type = col_type
        self.batch_size=batch_size
        self.column_names=column_names
        self.column_defaults= [self.typedic[col_type[fe]] for fe in col_type] if column_defaults is None else column_defaults
        self.label_name=label_name
        self.select_columns=select_columns if select_columns else list(col_type)
        self.field_delim=field_delim
        self.varlen_field_delim=varlen_field_delim
        self.varlen_ragged = varlen_ragged
        self.varlen_filld_value = varlen_filld_value
        self.varlen_max_len = varlen_max_len
        self.use_quote_delim=use_quote_delim
        self.na_value=na_value
        self.header=header
        self.num_epochs=num_epochs
        self.shuffle=shuffle
        self.shuffle_buffer_size=shuffle_buffer_size
        self.shuffle_seed=shuffle_seed
        self.prefetch_buffer_size=prefetch_buffer_size
        self.num_parallel_reads=num_parallel_reads
        self.sloppy=sloppy
        self.num_rows_for_inference=num_rows_for_inference
        self.compression_type=compression_type
        self.ignore_errors=ignore_errors
        self.varlens=[feat for feat in col_type
                        if col_type[feat] in ['stringv', 'int32List', 'int64List', 
                                                        'float32List', 'float64List']]
        self.use_hash=use_hash
        super(CSVLoader, self).__init__(**kwargs)

    def load(self):
        datasetV = tf.data.experimental.make_csv_dataset(
                                        file_pattern= self.file_pattern,
                                        batch_size = self.batch_size,
                                        column_names = self.column_names,
                                        column_defaults = self.column_defaults,
                                        label_name = self.label_name,
                                        select_columns = self.select_columns,
                                        field_delim = self.field_delim,
                                        use_quote_delim = self.use_quote_delim,
                                        na_value = self.na_value,
                                        header = self.header,
                                        num_epochs = self.num_epochs,
                                        shuffle = self.shuffle,
                                        shuffle_buffer_size = self.shuffle_buffer_size,
                                        shuffle_seed = self.shuffle_seed,
                                        prefetch_buffer_size = self.prefetch_buffer_size,
                                        num_parallel_reads = self.num_parallel_reads,
                                        sloppy = self.sloppy,
                                        num_rows_for_inference = self.num_rows_for_inference,
                                        compression_type = self.compression_type,
                                        ignore_errors = self.ignore_errors,
                                        )

        def varlen_parse_fun(*example):
            if self.label_name:
                x, y = example
            else:
                x = example[0]

            if len(self.varlens):
                for v in self.varlens:
                    if not self.varlen_ragged:
                        ragged = tf.strings.split(x[v], self.varlen_field_delim)
                        x[v] = ragged.to_tensor(default_value=self.varlen_filld_value,
                                            name='pad_ragged', 
                                            shape=(None, self.varlen_max_len))
                    else:
                        x[v] = tf.strings.split(x[v], self.varlen_field_delim)

            if self.label_name:
                return x, y
            else:
                return x

        #TODO: hash function and feature_colmuns
        datasetV = datasetV.map(varlen_parse_fun, 
                                    num_parallel_calls= \
                                        self.num_parallel_reads if self.num_parallel_reads else 1)

        return datasetV
