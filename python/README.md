# Python API

## **Go through README.md on parent directory first**

- enter python directory
  
  ```bash
  # assume that your are in the root of this repo
  $ cd python
  ```

- setup environment

  ```bash
  $ pip install -U pip
  $ pip install numpy tensorflow tensorflow-serving-api grpcio
  ```

## gRPC API

- request different model name

  ```bash
  $ python3 grpcRequest.py -m Toy # python3 grpcRequest.py -m <model name>
  # outputs {
  #   key: "output_1"
  #   value {
  #     dtype: DT_FLOAT
  #     tensor_shape {
  #       dim {
  #         size: 2
  #       }
  #       dim {
  #         size: 1
  #       }
  #     }
  #     float_val: 0.9990350008010864
  #     float_val: 0.9997349381446838
  #   }
  # }
  # model_spec {
  #   name: "Toy"
  #   version {
  #     value: 2
  #   }
  #   signature_name: "serving_default"
  # }
  $ python3 grpcRequest.py -m Toy_double
  # outputs {
  #   key: "output_1"
  #   value {
  #     dtype: DT_FLOAT
  #     tensor_shape {
  #       dim {
  #         size: 2
  #       }
  #       dim {
  #         size: 1
  #       }
  #     }
  #     float_val: 6.803016662597656
  #     float_val: 8.262093544006348
  #   }
  # }
  # model_spec {
  #   name: "Toy_double"
  #   version {
  #     value: 1
  #   }
  #   signature_name: "serving_default"
  # }
  ```

- request different version through the version number

  ```bash
    $ python3 grpcRequest.py -v 1 # python3 grpcRequest.py -v <version number>
    # outputs {
    #   key: "output_1"
    #   value {
    #     dtype: DT_FLOAT
    #     tensor_shape {
    #       dim {
    #         size: 2
    #       }
    #       dim {
    #         size: 1
    #       }
    #     }
    #     float_val: 10.805429458618164
    #     float_val: 14.010123252868652
    #   }
    # }
    # model_spec {
    #   name: "Toy"
    #   version {
    #     value: 1
    #   }
    #   signature_name: "serving_default"
    # }
    $ python3 grpcRequest.py -v 2
    # outputs {
    #   key: "output_1"
    #   value {
    #     dtype: DT_FLOAT
    #     tensor_shape {
    #       dim {
    #         size: 2
    #       }
    #       dim {
    #         size: 1
    #       }
    #     }
    #     float_val: 0.9990350008010864
    #     float_val: 0.9997349381446838
    #   }
    # }
    # model_spec {
    #   name: "Toy"
    #   version {
    #     value: 2
    #   }
    #   signature_name: "serving_default"
    # }
  ```

- request different version through the version annotation

  ```bash
  $ python3 grpcRequest.py -l stable # python3 grpcRequest.py -l <model label or annotation>
  # outputs {
  #   key: "output_1"
  #   value {
  #     dtype: DT_FLOAT
  #     tensor_shape {
  #       dim {
  #         size: 2
  #       }
  #       dim {
  #         size: 1
  #       }
  #     }
  #     float_val: 10.805429458618164
  #     float_val: 14.010123252868652
  #   }
  # }
  # model_spec {
  #   name: "Toy"
  #   version {
  #     value: 1
  #   }
  #   signature_name: "serving_default"
  # }
  $ python3 grpcRequest.py -l canary
  # outputs {
  #   key: "output_1"
  #   value {
  #     dtype: DT_FLOAT
  #     tensor_shape {
  #       dim {
  #         size: 2
  #       }
  #       dim {
  #         size: 1
  #       }
  #     }
  #     float_val: 0.9990350008010864
  #     float_val: 0.9997349381446838
  #   }
  # }
  # model_spec {
  #   name: "Toy"
  #   version {
  #     value: 2
  #   }
  #   signature_name: "serving_default"
  # }
  ```

- request multiple task model

- request model status

  ```bash
  $ python grpcModelStatus.py -m Toy_double -v 1
  # model_version_status {
  #   version: 1
  #   state: AVAILABLE
  #   status {
  #   }
  # }
  ```

- request model metadata

  ```bash
  $ python grpcMetadata.py
  # model_spec {
  #   name: "Toy"
  #   version {
  #     value: 2
  #   }
  # }
  # metadata {
  #   key: "signature_def"
  #   value {
  #     type_url: "type.googleapis.com/tensorflow.serving.SignatureDefMap"
  #     value: "\n\253\001\n\017serving_default\022\227\001\n;\n\007input_1\0220\n\031serving_default_input_1:0\020\001\032\021\022\013\010\377\377\377\377\377\377\377\377\377\001\022\002\010\002\022<\n\010output_1\0220\n\031StatefulPartitionedCall:0\020\001\032\021\022\013\010\377\377\377\377\377\377\377\377\377\001\022\002\010\001\032\032tensorflow/serving/predict\n>\n\025__saved_model_init_op\022%\022#\n\025__saved_model_init_op\022\n\n\004NoOp\032\002\030\001"
  #   }
  # }
  ```

- reload model through gRPC API

  ```bash
  $ python grpcReloadModel.py -m Toy
  # model Toy reloaded sucessfully
  ```

- request model log

  ```bash
  $ python grpcRequestLog.py -m Toy
  # ********************************************request logs********************************************
  # predict_log {
  #   request {
  #     model_spec {
  #       name: "Toy"
  #       signature_name: "serving_default"
  #     }
  #     inputs {
  #       key: "input_1"
  #       value {
  #         dtype: DT_FLOAT
  #         tensor_shape {
  #           dim {
  #             size: 2
  #           }
  #           dim {
  #             size: 2
  #           }
  #         }
  #         tensor_content: "\000\000\200?\000\000\000@\000\000\200?\000\000@@"
  #       }
  #     }
  #     output_filter: "output_1"
  #   }
  # }
  # ************************************************end*************************************************
  # **********************************************outputs***********************************************
  # outputs {
  #   key: "output_1"
  #   value {
  #     dtype: DT_FLOAT
  #     tensor_shape {
  #       dim {
  #         size: 2
  #       }
  #       dim {
  #         size: 1
  #       }
  #     }
  #     float_val: 0.9990350008010864
  #     float_val: 0.9997349381446838
  #   }
  # }
  # model_spec {
  #   name: "Toy"
  #   version {
  #     value: 2
  #   }
  #   signature_name: "serving_default"
  # }
  # ************************************************end*************************************************
  ```

- grpc API for python
  - [grpc API](https://github.com/tensorflow/serving/tree/master/tensorflow_serving/apis)
  
  - predict.proto

    ```protobuf
    syntax = "proto3";

    package tensorflow.serving;
    option cc_enable_arenas = true;

    import "tensorflow/core/framework/tensor.proto";
    import "tensorflow_serving/apis/model.proto";

    // PredictRequest specifies which TensorFlow model to run, as well as
    // how inputs are mapped to tensors and how outputs are filtered before
    // returning to user.
    message PredictRequest {
      // Model Specification. If version is not specified, will use the latest
      // (numerical) version.
      ModelSpec model_spec = 1;  # for python `request.model_spec`

      // Input tensors.
      // Names of input tensor are alias names. The mapping from aliases to real
      // input tensor names is stored in the SavedModel export as a prediction
      // SignatureDef under the 'inputs' field.
      map<string, TensorProto> inputs = 2; # for python `request.input` dictionary

      // Output filter.
      // Names specified are alias names. The mapping from aliases to real output
      // tensor names is stored in the SavedModel export as a prediction
      // SignatureDef under the 'outputs' field.
      // Only tensors specified here will be run/fetched and returned, with the
      // exception that when none is specified, all tensors specified in the
      // named signature will be run/fetched and returned.
      repeated string output_filter = 3; # for python `request.output_filter` list need to append values.
    }

    // Response for PredictRequest on successful run.
    message PredictResponse {
      // Effective Model Specification used to process PredictRequest.
      ModelSpec model_spec = 2;

      // Output tensors.
      map<string, TensorProto> outputs = 1;
    }
    ```

  - model.proto
  
    ```protobuf
    syntax = "proto3";

    package tensorflow.serving;
    option cc_enable_arenas = true;

    import "google/protobuf/wrappers.proto";

    // Metadata for an inference request such as the model name and version.
    message ModelSpec {
      // Required servable name.
      string name = 1;

      // Optional choice of which version of the model to use.
      //
      // Recommended to be left unset in the common case. Should be specified only
      // when there is a strong version consistency requirement.
      //
      // When left unspecified, the system will serve the best available version.
      // This is typically the latest version, though during version transitions,
      // notably when serving on a fleet of instances, may be either the previous or
      // new version.

      # for this `request.model_spec.version.value`
      # or `request.model_spec.version_label`
      oneof version_choice {
        // Use this specific version number.
        google.protobuf.Int64Value version = 2;

        // Use the version associated with the given label.
        string version_label = 4;
      }

      // A named signature to evaluate. If unspecified, the default signature will
      // be used.
      # for python `request.model_spec.signature_name`
      string signature_name = 3;
    }
    ```

## For production

- [SavedModel Warmup](https://www.tensorflow.org/tfx/serving/saved_model_warmup)
- `--enable_model_warmup`: Enables model warmup using user-provided PredictionLogs in assets.extra/ directory
