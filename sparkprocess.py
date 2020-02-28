
#%%
import pyspark as spark
import pyspark.sql.functions as F
from IPython.display import display
from pyspark.sql import DataFrame, Row, SparkSession
from pyspark.sql.types import IntegerType, LongType, StringType, StructField

# path_train = '../item2vec_20200119'
path_train = '../week02'
#%%
sparkv = SparkSession.builder \
        .master("local[4]") \
        .appName("item2vec") \
        .config("spark.some.config.option", "some-value") \
        .getOrCreate()

sc = sparkv.sparkContext

#%%
orc_df = sparkv.read.orc(f'{path_train}/*')
# %%
dd=orc_df.select('hashedOperaId', 'materialId', )\
         .rdd.groupBy(lambda x: x[0]).collect()

with open('./train_new.txt', mode='w+') as f:
    for usr, mid in dd:
        print(f"{usr}: {' '.join([k[-1] for k in mid ])}", file=f)