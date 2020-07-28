# Golang in loading tensorflow model  and predict

Prerequisite: [TensorFlow-1.12.0](https://github.com/tensorflow/tensorflow/tree/v1.12.0) higher version might not be compatible.

Prerequisite: [libtensorflow](https://www.tensorflow.org/install/lang_c)

we provide a easy way to call tensorflow models in golang

of course, there are too many unexpected problems while trying to do this. 

Fortunately, we solve them all.

And there are some examples about loading tensorflow models in different ways, if you are interested in this, never hesitate to read more about the code.

Here are more details about the whole process.

## Two methods to load tensorflow model

### Method one  

loading model from a dir with a model file named saved_model.pb and a variables dir of the model

### Method two

loading model from a freezed graph file `.pbtxt`

## Using TF_Serving

### TF_Serving

we start a tf_serving grpc server serving tensorflow models, we just need to write a grpc client to connect tf_serving service and call method we use predict to get result
   [rpc proto we used](http://github.com/bigchange/go-pro/tensorflow_serving/prediction_service.proto)  

## How to save and deploy your model with tf_serving

### Tensorflow-Model-Server

we need to install `tensorflow-model-server`, we can install by using [bazel](https://github.com/tensorflow/serving.git) or just downloading compiled binary 

```把Serving的发行URI添加为package源
echo "deb [arch=amd64] http://storage.googleapis.com/tensorflow-serving-apt stable tensorflow-model-server tensorflow-model-server-universal" | sudo tee /etc/apt/sources.list.d/tensorflow-serving.list
curl https://storage.googleapis.com/tensorflow-serving-apt/tensorflow-serving.release.pub.gpg | sudo apt-key add -
安装更新，之后即可通过tensorflow_model_server命令调用
sudo apt-get update && sudo apt-get install tensorflow-model-server
```

### Saving model

首先需要在MetaGraphDef里加入SignatureDef部分的内容，SignatureDef详细的定义见tensorflow源码 tensorflow/core/protobuf/meta_graph.proto，下面介绍如何在python代码中加入SignatureDef内容。
假如模型有两个节点A和B是所需要的输入，A和B的名字分别为"a:0", "b:0"， 需要的输出节点C的名字是"c:0",  保存模型代码如下：

```python
import tensorflow as tf


sess=tf.Session()  
# 如果训练后直接保存，跳过restore的过程  
saver = tf.train.import_meta_graph('./model.ckpt-106437.meta')
saver.restore(sess, './model.ckpt-106437')
graph = tf.Graph()
# 获取节点
A = graph.get_tensor_by_name('a:0')
B = graph.get_tensor_by_name('b:0')
C = graph.get_tensor_by_name('c:0')

# build info

A_info = tf.saved_model.utils.build_tensor_info(A)
B_info = tf.saved_model.utils.build_tensor_info(B)
C_info = tf.saved_model.utils.build_tensor_info(C)

# 生成signature
pred_signature = (tf.saved_model.signature_def_utils.build_signature_def(inputs={'A': A_info, 'B': B_info}, outputs={'C':C_info}, method_name=tf.saved_model.signature_constants.PREDICT_METHOD_NAME))

# build & save
builder = tf.saved_model.builder.SavedModelBuilder('/your/path/to/export/version') # version为代表版本的正整数
builder.add_meta_graph_and_variables(sess, [tf.saved_model.tag_constants.SERVING], signature_def_map={'your_name': pred_signature}, main_op=tf.tables_initializer(), strip_default_attrs=True)

build.saver()
```

export result is in `/your/path/to/export/version`, with a model file named saved_model.pb and a variables dir of the model, same as `methond one` we talk about before in loading tensorflow model.

### Deploy your model

```tensorflow_model_server --model_name='model_name_you_can_define' --model_base_path=/your/path/to/export --port=9099 --per_process_gpu_memory_fraction=1.0 --enable_model_warmup```

Let's have fun! More issues and pull requests are welcomed.
