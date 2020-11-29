# CPP API

## Requirement

- protobuf == 3.12.4
- grpc == 1.29.1

## Start Server docker

- [start tfserver](../README.md)
- netowork setting
  - this we need to docker image as develop image, so plase find the server ip with `docker network inspect bridge`

    ```bash
    $ docker ps # using this to find the server name under NAMES feild.
    $ docker network inspect bridge
    [
        {
          ...
                "82811806166f9250d0b1734479db6c368a8b90193811231e5125fdab1dfee6a0": {
                    "Name": "focused_borg",   # this is the name of server (need to check)
                    "EndpointID": "1af2f89e7617a837f28fe573aeaf5b57d650216167180b00c70a4be11cfb1510",
                    "MacAddress": "02:42:ac:11:00:03",
                    "IPv4Address": "172.17.0.3/16", # if name is right then this is your server IP
                    "IPv6Address": ""
          ...
        }
    ]
    ```

- enter cpp directory

  ```bash
  $ cd cpp/
  ```

## Build your own C++ TFclient (optional)

- environment preparation (detail on the [doeckerfile](./grpc-cpp.dockerfile))

  - [grpc](https://github.com/grpc/grpc/tree/master/src/cpp)
  - [protobuf](https://github.com/protocolbuffers/protobuf/tree/master/src)

- build docker

  ```bash
  $ docker build -t grpc-cpp -f grpc-cpp-static.dockerfile .
  ```

- start and enter `grpc-cpp` shell

  ```bash
  $ docker run --rm -ti -v `pwd`:/cpp  grpc-cpp
  root@5b9f27acaefe:/# git clone https://github.com/tensorflow/tensorflow
  root@5b9f27acaefe:/# git clone https://github.com/tensorflow/serving
  root@5b9f27acaefe:/# cd /cpp
  root@5b9f27acaefe:/cpp# mkdir gen
  root@5b9f27acaefe:/cpp# bash build-cpp-api.sh
  root@5b9f27acaefe:/cpp# mv gen ./src
  root@5b9f27acaefe:/cpp# cd /cpp/src/predict-service
  root@5b9f27acaefe:/cpp# cd /cpp/src/predict-service
  root@5b9f27acaefe:/cpp/src/predict-service# make
  root@5b9f27acaefe:/cpp/src/predict-service# ./bin/main
  # calling prediction service on 172.17.0.3:8500
  # call predict ok
  # outputs size is 1
  #
  # output_1:
  # 0.999035
  # 0.999735
  # 0.999927
  ```

## Run client examples

- run go client for a simple example
  - enter the docker terminal
  
  ```bash
  $ docker run --rm -ti -v `pwd`:/cpp  grpc-cpp # or you can docker exec -ti <docker name> /bin/bash
  root@5b9f27acaefe:/# cd cpp/src/
  root@5b9f27acaefe:/cpp/src#
  ```

  **assume you are in the src directory**
  - request data from server

    ```bash
    # run under predict-service directory
    $ make
    $ ./bin/main
    # calling prediction service on 172.17.0.3:8500
    # call predict ok
    # outputs size is 1
    # 
    # output_1:
    # 0.999035
    # 0.999735
    # 0.999927
    # Done.
    ```

  - request different model name

    ```bash
    # run under predict-service directory
    $ make
    $ ./bin/main --model_name Toy
    # calling prediction service on 172.17.0.3:8500
    # call predict ok
    # outputs size is 1
    # 
    # output_1:
    # 0.999035
    # 0.999735
    # 0.999927
    # Done.
    $ ./bin/main --model_name Toy_double
    # calling prediction service on 172.17.0.3:8500
    # call predict ok
    # outputs size is 1

    # output_1:
    # 6.80302
    # 8.26209
    # 9.72117
    # Done.
    ```

  - request different version through the version number

    ```bash
    # run under predict-service directory
    $ make
    $ ./bin/main --model_name Toy --model_version 1
    # calling prediction service on 172.17.0.3:8500
    # call predict ok
    # outputs size is 1

    # output_1:
    # 10.8054
    # 14.0101
    # 17.2148
    # Done.
    $ ./bin/main --model_name Toy --model_version 2
    # calling prediction service on 172.17.0.3:8500
    # call predict ok
    # outputs size is 1

    # output_1:
    # 0.999035
    # 0.999735
    # 0.999927
    # Done.
    ```

  - request different version through the version annotation

    ```bash
    # run under predict-service directory
    $ make
    $ ./bin/main --model_name Toy --model_version_label stable
    # calling prediction service on 172.17.0.3:8500
    # call predict ok
    # outputs size is 1
    
    # output_1:
    # 10.8054
    # 14.0101
    # 17.2148
    # Done.
    $ ./bin/main --model_name Toy --model_version_label canary
    # calling prediction service on 172.17.0.3:8500
    # call predict ok
    # outputs size is 1

    # output_1:
    # 0.999035
    # 0.999735
    # 0.999927
    # Done.
    ```

  - request multiple task model <!--  TODO: -->

    ```bash
    $ cd ...
    $ make
    $ ./bin/main
    ```

  - request model status

    ```bash
    # run under model-status directory
    $ make
    $ ./bin/main --model_name Toy
    # calling model service on 172.17.0.3:8500
    # model_spec {
    #   name: "Toy"
    #   signature_name: "serving_default"
    # }
    # 
    # call predict ok
    # metadata size is 0
    # metadata DebugString is 
    # model_version_status {
    #   version: 3
    #   state: END
    #   status {
    #   }
    # }
    # model_version_status {
    #   version: 2
    #   state: AVAILABLE
    #   status {
    #   }
    # }
    # model_version_status {
    #   version: 1
    #   state: AVAILABLE
    #   status {
    #   }
    # }
    ```

  - request model metadata

    ```bash
    # run under model-metadata directory
    $ make
    $ ./bin/main --model_name Toy
    # calling prediction service on 172.17.0.3:8500
    # call predict ok
    # metadata size is 1
    # metadata DebugString is 
    # model_spec {
    #   name: "Toy"
    #   version {
    #     value: 2
    #   }
    # }
    # metadata {
    #   key: "signature_def"
    #   value {
    #     [type.googleapis.com/tensorflow.serving.SignatureDefMap] {
    #       signature_def {
    #         key: "__saved_model_init_op"
    #         value {
    #           outputs {
    #             key: "__saved_model_init_op"
    #             value {
    #               name: "NoOp"
    #               tensor_shape {
    #                 unknown_rank: true
    #               }
    #             }
    #           }
    #         }
    #       }
    #       signature_def {
    #         key: "serving_default"
    #         value {
    #           inputs {
    #             key: "input_1"
    #             value {
    #               name: "serving_default_input_1:0"
    #               dtype: DT_FLOAT
    #               tensor_shape {
    #                 dim {
    #                   size: -1
    #                 }
    #                 dim {
    #                   size: 2
    #                 }
    #               }
    #             }
    #           }
    #           outputs {
    #             key: "output_1"
    #             value {
    #               name: "StatefulPartitionedCall:0"
    #               dtype: DT_FLOAT
    #               tensor_shape {
    #                 dim {
    #                   size: -1
    #                 }
    #                 dim {
    #                   size: 1
    #                 }
    #               }
    #             }
    #           }
    #           method_name: "tensorflow/serving/predict"
    #         }
    #       }
    #     }
    #   }
    # }
    #
    ```

  - reload model through gRPC API

    ```bash
    # run under model-reload directory
    $ make
    $ ./bin/main --model_name Toy
    # calling model service on 172.17.0.3:8500
    # call model service ok
    # model Toy reloaded successfully.
    ```

  - request model log

    ```bash
    # run under predict-log directory
    $ make
    $ ./bin/main --model_name Toy # --model_version 1 --model_version_label stable
    # calling prediction service on 172.17.0.3:8500
    # call predict ok
    # outputs size is 1  

    # output_1:
    # 0.999035
    # 0.999735
    # 0.999927
    # ********************Predict Log*********************
    # request {
    #   model_spec {
    #     name: "Toy"
    #     signature_name: "serving_default"
    #   }
    #   inputs {
    #     key: "input_1"
    #     value {
    #       dtype: DT_FLOAT
    #       tensor_shape {
    #         dim {
    #           size: 3
    #         }
    #         dim {
    #           size: 2
    #         }
    #       }
    #       float_val: 1
    #       float_val: 2
    #       float_val: 1
    #       float_val: 3
    #       float_val: 1
    #       float_val: 4
    #     }
    #   }
    # }
    # response {
    #   outputs {
    #     key: "output_1"
    #     value {
    #       dtype: DT_FLOAT
    #       tensor_shape {
    #         dim {
    #           size: 3
    #         }
    #         dim {
    #           size: 1
    #         }
    #       }
    #       float_val: 0.999035
    #       float_val: 0.999734938
    #       float_val: 0.999927282
    #     }
    #   }
    #   model_spec {
    #     name: "Toy"
    #     version {
    #       value: 2
    #     }
    #     signature_name: "serving_default"
    #   }
    # }
    # ****************************************************
    # Done.
    ```

## Static Lib

- [abseil-cpp#250 Wrong order](https://github.com/abseil/abseil-cpp/issues/250#issuecomment-455831883)
*Note that: the `absl_int128` need `absl_string` so the `-labsl_string` need to be infront of `-labsl_int128` in the `Makefile`*

- generate the static lib

  ```bash
  # run under static-lib directory
  $ make
  $ ls
  # libtfserving.a Makefile
  ```

- test with generated static library

  ```bash
  # enter build-with-a-file directory
  $ make
  $ ./bin/main -s 172.17.0.3:8500
  # calling prediction service on 172.17.0.3:8500
  # call predict ok
  # outputs size is 1
  # 
  # output_1:
  # 0.999035
  # 0.999735
  # 0.999927
  # Done.
  ```
