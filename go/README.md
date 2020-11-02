# GO API

## Build your own go TFclient (optional) (new version)

- Thanks to [Maxim Khitrov](https://gist.github.com/mxk) and [datainq](https://github.com/datainq/go-mnist-client). Here is [reference](https://gist.github.com/mxk/b86769306037c9dc49b44d52764cbbdc)

- requirement
  - [go installation](https://golang.org/doc/install)

  ```text
  go >= 1.12.7
  protoc >= 3.12.4
  tensorflow == 2.3
  tensorflow_serving == 2.3
  ```

  - note that we run this under `GO111MODULE=off`

## Run

- build your tfclient docker

```bash
# under go directory
$ docker build -t golang/tfclient -f grpcgo.dockerfile .
```

- enter `golang/tfclient` and check `protobuf` and `go` version

```bash
$ docker run --rm -ti golang/tfclient /bin/bash
root@2fd0578f8c39:~/tfclient/src$  go version
# go version go1.12.7 linux/amd64
root@2fd0578f8c39:~/tfclient/src$ protoc --version
# libprotoc 3.12.4
# root@2fd0578f8c39:~/tfclient/src$ rm go.mod go.sum # clear go env
```

- clone  `tensorflow` and `serving`

```bash
root@2fd0578f8c39:~/tfclient/src$ cd /
root@2fd0578f8c39:/$ git clone -b r2.3 https://github.com/tensorflow/tensorflow.git
root@2fd0578f8c39:/$ git clone -b r2.3 https://github.com/tensorflow/serving.git
root@2fd0578f8c39:/$ cd -
```

- download dependency

```bash
root@2fd0578f8c39:~/tfclient/src$ . env.sh
root@2fd0578f8c39:~/tfclient/src$ bash basic-run-env.sh
```

- build protobuf

```bash
root@2fd0578f8c39:~/tfclient/src$ bash protoc.sh
root@2fd0578f8c39:~/tfclient/src$ ll
# total 20
# drwxr-xr-x 3 root root 4096 Nov  2 05:08 tensorflow/
# drwxr-xr-x 3 root root 4096 Nov  2 05:08 github.com/
# drwxr-xr-x 3 root root 4096 Nov  2 05:08 alwaysproblem/
# drwxr-xr-x 9 root root 4096 Nov  2 05:08 ../
# drwxrwxrwx 5 root root 4096 Nov  2 05:08 ./

```

- add to go module

```bash
root@2fd0578f8c39:~/tfclient/src$ go mod init client
root@2fd0578f8c39:~/tfclient/src$ mv proto/github.com/tensorflow $GOPATH/src/github.com/
root@2fd0578f8c39:~/tfclient/src$ mv proto/alwaysproblem $GOPATH/src/github.com/
```


- run server
  *if you forget to run in the first place.*
  ```bash
  $ ROOT=/Users/yongxiyang/Desktop/TFServing-setup-tutorial/
  $ docker run --rm -p 8500:8500 -p 8501:8501 --mount type=bind,source=$ROOT,target=/models --mount type=bind,source=$ROOT/config/versionlabels.config,target=/models/versionctrl.config -it tensorflow/serving --model_config_file=/models/versionctrl.config --model_config_file_poll_wait_seconds=60 --allow_version_labels_for_unavailable_models
  ```

- run the test on the client (please find the right server address)
  - install dependency

    ```bash
    # assume you are in go directory
    $ cd src
    $ source env.sh
    $ bash basic-run-env.sh
    ```

  - run go client for a simple example
    **don't forget source env.sh**
    - request data from server

      ```bash
      # run under src directory
      $ bash run.sh main/predict-service.go # test on local host
      # model_spec:{name:"Toy"  version:{value:1}  signature_name:"serving_default"}  outputs:{key:"output_1"  value:{dtype:DT_FLOAT  tensor_shape:{dim:{size:3}  dim:{size:1}}  float_val:10.805429  float_val:14.010123  float_val:17.214817}}
      ```

    - request different model name

      ```bash
      $ go run main/predict-service.go --model_name Toy
      # model_spec:{name:"Toy"  version:{value:2}  signature_name:"serving_default"}  outputs:{key:"output_1"  value:{dtype:DT_FLOAT  tensor_shape:{dim:{size:3}  dim:{size:1}}  float_val:0.999035  float_val:0.99973494  float_val:0.9999273}}
      $ go run main/predict-service.go --model_name Toy_double
      # model_spec:{name:"Toy_double"  version:{value:1}  signature_name:"serving_default"}  outputs:{key:"output_1"  value:{dtype:DT_FLOAT  tensor_shape:{dim:{size:3}  dim:{size:1}}  float_val:6.8030167  float_val:8.262094  float_val:9.72117}}
      ```

    - request different version through the version number

      ```bash
      $ go run main/predict-service.go --model_name Toy --model_version 1
      # model_spec:{name:"Toy"  version:{value:1}  signature_name:"serving_default"}  outputs:{key:"output_1"  value:{dtype:DT_FLOAT  tensor_shape:{dim:{size:3}  dim:{size:1}}  float_val:10.805429  float_val:14.010123  float_val:17.214817}}
      $ go run main/predict-service.go --model_name Toy --model_version 2
      # model_spec:{name:"Toy"  version:{value:2}  signature_name:"serving_default"}  outputs:{key:"output_1"  value:{dtype:DT_FLOAT  tensor_shape:{dim:{size:3}  dim:{size:1}}  float_val:0.999035  float_val:0.99973494  float_val:0.9999273}}
      ```

    - request different version through the version annotation

      ```bash
      $ go run main/predict-service.go --model_name Toy --model_version_label stable
      # model_spec:{name:"Toy"  version:{value:1}  signature_name:"serving_default"}  outputs:{key:"output_1"  value:{dtype:DT_FLOAT  tensor_shape:{dim:{size:3}  dim:{size:1}}  float_val:10.805429  float_val:14.010123  float_val:17.214817}}
      ```

    - request multiple task model <!--  TODO: -->

      ```bash
      ```

    - request model status

      ```bash
      $ go run main/model-status.go --model_name Toy
      # model_version_status:{version:2 state:AVAILABLE status:{}} model_version_status:{version:1 state:AVAILABLE status:{}}
      ```

    - request model metadata

      ```bash
      $ go run main/predict-model-metadata.go --model_name Toy
      # model_spec:{name:"Toy"  version:{value:2}}  metadata:{key:"signature_def"  value:{[type.googleapis.com/tensorflow.serving.SignatureDefMap]:{signature_def:{key:"__saved_model_init_op"  value:{outputs:{key:"__saved_model_init_op"  value:{name:"NoOp"  tensor_shape:{unknown_rank:true}}}}}  signature_def:{key:"serving_default"  value:{inputs:{key:"input_1"  value:{name:"serving_default_input_1:0"  dtype:DT_FLOAT  tensor_shape:{dim:{size:-1}  dim:{size:2}}}}  outputs:{key:"output_1"  value:{name:"StatefulPartitionedCall:0"  dtype:DT_FLOAT  tensor_shape:{dim:{size:-1}  dim:{size:1}}}}  method_name:"tensorflow/serving/predict"}}}}}
      ```

    - reload model through gRPC API

      ```bash
      $ go run main/model-reload.go --model_name Toy
      # model Toy reloaded sucessfully
      ```

    - request model log

      ```bash
      $ go run main/predict-log.go --model_name Toy # --model_version 1 --model_version_label stable
      # model_spec:{name:"Toy"  version:{value:2}  signature_name:"serving_default"}  outputs:{key:"output_1"  value:{dtype:DT_FLOAT  tensor_shape:{dim:{size:3}  dim:{size:1}}  float_val:0.999035  float_val:0.99973494  float_val:0.9999273}}
      # log_metadata:{model_spec:{name:"Toy"  signature_name:"serving_default"}}  predict_log:{request:{model_spec:{name:"Toy"  signature_name:"serving_default"}  inputs:{key:"input_1"  value:{dtype:DT_FLOAT  tensor_shape:{dim:{size:3}  dim:{size:2}}  float_val:1  float_val:2  float_val:1  float_val:3  float_val:1  float_val:4}}}  response:{model_spec:{name:"Toy"  version:{value:2}  signature_name:"serving_default"}  outputs:{key:"output_1"  value:{dtype:DT_FLOAT  tensor_shape:{dim:{size:3}  dim:{size:1}}  float_val:0.999035  float_val:0.99973494  float_val:0.9999273}}}}
      ```

- GO gRPC api
  1. framework TensorProto

    ```go
    type TensorProto struct {
      state         protoimpl.MessageState
      sizeCache     protoimpl.SizeCache
      unknownFields protoimpl.UnknownFields

      Dtype DataType `protobuf:"varint,1,opt,name=dtype,proto3,enum=tensorflow.DataType" json:"dtype,omitempty"`
      // Shape of the tensor.  TODO(touts): sort out the 0-rank issues.
      TensorShape *TensorShapeProto `protobuf:"bytes,2,opt,name=tensor_shape,json=tensorShape,proto3" json:"tensor_shape,omitempty"`
      // Version number.
      //
      // In version 0, if the "repeated xxx" representations contain only one
      // element, that element is repeated to fill the shape.  This makes it easy
      // to represent a constant Tensor with a single value.
      VersionNumber int32 `protobuf:"varint,3,opt,name=version_number,json=versionNumber,proto3" json:"version_number,omitempty"`
      // Serialized raw tensor content from either Tensor::AsProtoTensorContent or
      // memcpy in tensorflow::grpc::EncodeTensorToByteBuffer. This representation
      // can be used for all tensor types. The purpose of this representation is to
      // reduce serialization overhead during RPC call by avoiding serialization of
      // many repeated small items.
      TensorContent []byte `protobuf:"bytes,4,opt,name=tensor_content,json=tensorContent,proto3" json:"tensor_content,omitempty"`
      // DT_HALF, DT_BFLOAT16. Note that since protobuf has no int16 type, we'll
      // have some pointless zero padding for each value here.
      HalfVal []int32 `protobuf:"varint,13,rep,packed,name=half_val,json=halfVal,proto3" json:"half_val,omitempty"`
      // DT_FLOAT.
      FloatVal []float32 `protobuf:"fixed32,5,rep,packed,name=float_val,json=floatVal,proto3" json:"float_val,omitempty"`
      // DT_DOUBLE.
      DoubleVal []float64 `protobuf:"fixed64,6,rep,packed,name=double_val,json=doubleVal,proto3" json:"double_val,omitempty"`
      // DT_INT32, DT_INT16, DT_INT8, DT_UINT8.
      IntVal []int32 `protobuf:"varint,7,rep,packed,name=int_val,json=intVal,proto3" json:"int_val,omitempty"`
      // DT_STRING
      StringVal [][]byte `protobuf:"bytes,8,rep,name=string_val,json=stringVal,proto3" json:"string_val,omitempty"`
      // DT_COMPLEX64. scomplex_val(2*i) and scomplex_val(2*i+1) are real
      // and imaginary parts of i-th single precision complex.
      ScomplexVal []float32 `protobuf:"fixed32,9,rep,packed,name=scomplex_val,json=scomplexVal,proto3" json:"scomplex_val,omitempty"`
      // DT_INT64
      Int64Val []int64 `protobuf:"varint,10,rep,packed,name=int64_val,json=int64Val,proto3" json:"int64_val,omitempty"`
      // DT_BOOL
      BoolVal []bool `protobuf:"varint,11,rep,packed,name=bool_val,json=boolVal,proto3" json:"bool_val,omitempty"`
      // DT_COMPLEX128. dcomplex_val(2*i) and dcomplex_val(2*i+1) are real
      // and imaginary parts of i-th double precision complex.
      DcomplexVal []float64 `protobuf:"fixed64,12,rep,packed,name=dcomplex_val,json=dcomplexVal,proto3" json:"dcomplex_val,omitempty"`
      // DT_RESOURCE
      ResourceHandleVal []*ResourceHandleProto `protobuf:"bytes,14,rep,name=resource_handle_val,json=resourceHandleVal,proto3" json:"resource_handle_val,omitempty"`
      // DT_VARIANT
      VariantVal []*VariantTensorDataProto `protobuf:"bytes,15,rep,name=variant_val,json=variantVal,proto3" json:"variant_val,omitempty"`
      // DT_UINT32
      Uint32Val []uint32 `protobuf:"varint,16,rep,packed,name=uint32_val,json=uint32Val,proto3" json:"uint32_val,omitempty"`
      // DT_UINT64
      Uint64Val []uint64 `protobuf:"varint,17,rep,packed,name=uint64_val,json=uint64Val,proto3" json:"uint64_val,omitempty"`
    }
    ```
  
  2. PredictRequest proto

    ```go
    type PredictRequest struct {
      state         protoimpl.MessageState
      sizeCache     protoimpl.SizeCache
      unknownFields protoimpl.UnknownFields

      // Model Specification. If version is not specified, will use the latest
      // (numerical) version.
      ModelSpec *ModelSpec `protobuf:"bytes,1,opt,name=model_spec,json=modelSpec,proto3" json:"model_spec,omitempty"`
      // Input tensors.
      // Names of input tensor are alias names. The mapping from aliases to real
      // input tensor names is stored in the SavedModel export as a prediction
      // SignatureDef under the 'inputs' field.
      Inputs map[string]*framework.TensorProto `protobuf:"bytes,2,rep,name=inputs,proto3" json:"inputs,omitempty" protobuf_key:"bytes,1,opt,name=key,proto3" protobuf_val:"bytes,2,opt,name=value,proto3"`
      // Output filter.
      // Names specified are alias names. The mapping from aliases to real output
      // tensor names is stored in the SavedModel export as a prediction
      // SignatureDef under the 'outputs' field.
      // Only tensors specified here will be run/fetched and returned, with the
      // exception that when none is specified, all tensors specified in the
      // named signature will be run/fetched and returned.
      OutputFilter []string `protobuf:"bytes,3,rep,name=output_filter,json=outputFilter,proto3" json:"output_filter,omitempty"`
    }
    ```

  3. PredictResponse proto

    ```go
    // Response for PredictRequest on successful run.
    type PredictResponse struct {
      state         protoimpl.MessageState
      sizeCache     protoimpl.SizeCache
      unknownFields protoimpl.UnknownFields

      // Effective Model Specification used to process PredictRequest.
      ModelSpec *ModelSpec `protobuf:"bytes,2,opt,name=model_spec,json=modelSpec,proto3" json:"model_spec,omitempty"`
      // Output tensors.
      Outputs map[string]*framework.TensorProto `protobuf:"bytes,1,rep,name=outputs,proto3" json:"outputs,omitempty" protobuf_key:"bytes,1,opt,name=key,proto3" protobuf_val:"bytes,2,opt,name=value,proto3"`
    }
    ```

  4. ModelSpec proto
  
    ```go
    // Metadata for an inference request such as the model name and version.
    type ModelSpec struct {
      state         protoimpl.MessageState
      sizeCache     protoimpl.SizeCache
      unknownFields protoimpl.UnknownFields

      // Required servable name.
      Name string `protobuf:"bytes,1,opt,name=name,proto3" json:"name,omitempty"`
      // Optional choice of which version of the model to use.
      //
      // Recommended to be left unset in the common case. Should be specified only
      // when there is a strong version consistency requirement.
      //
      // When left unspecified, the system will serve the best available version.
      // This is typically the latest version, though during version transitions,
      // notably when serving on a fleet of instances, may be either the previous or
      // new version.
      //
      // Types that are assignable to VersionChoice:
      //	*ModelSpec_Version
      //	*ModelSpec_VersionLabel
      VersionChoice isModelSpec_VersionChoice `protobuf_oneof:"version_choice"`
      // A named signature to evaluate. If unspecified, the default signature will
      // be used.
      SignatureName string `protobuf:"bytes,3,opt,name=signature_name,json=signatureName,proto3" json:"signature_name,omitempty"`
    }
    // for VersionChoice
    type ModelSpec_Version struct {
      // Use this specific version number.
      Version *wrappers.Int64Value `protobuf:"bytes,2,opt,name=version,proto3,oneof"`
    }

    type ModelSpec_VersionLabel struct {
      // Use the version associated with the given label.
      VersionLabel string `protobuf:"bytes,4,opt,name=version_label,json=versionLabel,proto3,oneof"`
    }
    ```

  5. Prediction Log Proto

    ```go
    type PredictLog struct {
      state         protoimpl.MessageState
      sizeCache     protoimpl.SizeCache
      unknownFields protoimpl.UnknownFields

      Request  *PredictRequest  `protobuf:"bytes,1,opt,name=request,proto3" json:"request,omitempty"`
      Response *PredictResponse `protobuf:"bytes,2,opt,name=response,proto3" json:"response,omitempty"`
    }
    ```
  
  6. MutilInferenceLog

    ```go
    type MultiInferenceLog struct {
      state         protoimpl.MessageState
      sizeCache     protoimpl.SizeCache
      unknownFields protoimpl.UnknownFields

      Request  *MultiInferenceRequest  `protobuf:"bytes,1,opt,name=request,proto3" json:"request,omitempty"`
      Response *MultiInferenceResponse `protobuf:"bytes,2,opt,name=response,proto3" json:"response,omitempty"`
    }
    ```
  
  7. PredictionLog

    ```go
    // Logged model inference request.
    type PredictionLog struct {
      state         protoimpl.MessageState
      sizeCache     protoimpl.SizeCache
      unknownFields protoimpl.UnknownFields

      LogMetadata *LogMetadata `protobuf:"bytes,1,opt,name=log_metadata,json=logMetadata,proto3" json:"log_metadata,omitempty"`
      // Types that are assignable to LogType:
      //	*PredictionLog_ClassifyLog
      //	*PredictionLog_RegressLog
      //	*PredictionLog_PredictLog
      //	*PredictionLog_MultiInferenceLog
      //	*PredictionLog_SessionRunLog
      LogType isPredictionLog_LogType `protobuf_oneof:"log_type"`
    }
    ```
  8. model_server api

<!-- TODO: finish the handbook ,  get rid of todo and comment-->
