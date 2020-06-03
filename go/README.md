# TFclient golang Version

## Basic tutorial for Tensorflow serving client grpc API (go version)

## **Install Docker**

- **Window/MacOS**: install Docker from [DockerHub](https://hub.docker.com/?overlay=onboarding). (*need to register new account if you are newbie*)

- **linux**: install [Docker](https://runnable.com/docker/install-docker-on-linux)

## Build your own go TFclient

- Thanks to [Maxim Khitrov](https://gist.github.com/mxk) and [reference](https://gist.github.com/mxk/b86769306037c9dc49b44d52764cbbdc)

- requirement

  ```text
  go >= 1.11
  protoc == 3.6.1
  ```

- setup a new directory and the structure is like this:

  ```text
  ---client (your new directory name)
      |
      ---pkg (for go modules)
      |
      ---src (for customed modules and source files)
      |
      ---bin (fo go binary files)
  ```

- copy `dockerfile` to your own directory and build docker image through dockerfile

  ```bash
  # assume that you are under go directory.
  cp dockerfile <your>
  # docker build -t <tag>:<label> path -f <dockerfile>
  docker build -t alwaysproblem/tfclient-go:build path -f dockerfile
  ```

- build inside docker

  ```bash
  $ docker run --rm -ti --name goenv -v `pwd`:/work alwaysproblem/tfclient-go:build /bin/bash
  ```

  ```bash
  root@8c768509e690:/work# cd src
  root@8c768509e690:/work/src# git clone -b r1.15 https://github.com/tensorflow/tensorflow.git
  root@8c768509e690:/work/src# git clone -b r1.14 https://github.com/tensorflow/serving.git
  root@8c768509e690:/work/src# go run protoc.go # ignore the warning but this procedure only works under specific protoc version
  root@8c768509e690:/work/src# go mod init client
  root@8c768509e690:/work/src# go mod edit -replace=github.com/tensorflow/tensorflow/tensorflow/go/core=./proto/tensorflow/core
  root@8c768509e690:/work/src# go mod edit -replace=github.com/alwaysproblem/tensorflow_serving=./proto/tensorflow/serving
  root@8c768509e690:/work/src# cd proto/tensorflow/core && go mod init github.com/tensorflow/tensorflow/tensorflow/go/core && cd -
  root@8c768509e690:/work/src# cd proto/tensorflow/serving && go mod init github.com/alwaysproblem/tensorflow_serving && cd -
  root@8c768509e690:/work/src# rm -rf tensorflow/ serving/
  root@8c768509e690:/work/src# exit
  ```

- copy test file to your own directory

  ```bash
  ```

- run server

  ```bash
  $ docker run --rm -p 8500:8500 -p 8501:8501 --mount type=bind,source=$(pwd),target=/models --mount type=bind,source=$(pwd)/config/versionctrl.config,target=/models/versionctrl.config -it tensorflow/serving --model_config_file=/models/versionctrl.config --model_config_file_poll_wait_seconds=60
  ```

- run the test on the client
  - install dependency

    ```bash
    # assume you are in go directory
    $ source env.sh
    $ cd src
    $ bash basic-run-env.sh
    ```

  - run go client

    ```bash
    # run under src directory
    $ bash run.sh # test on local host
    # OK
    # time per request:  42.607813ms
    # tensor: output_1, version: 0
    # 0.999035
    # 0.99973494
    ```


<!-- TODO: make it suitable for go below-->
## **Tutorial for starting**

```bash
$ git clone https://github.com/Alwaysproblem/TFServing-setup-review.git
$ cd TFServing-setup-review
```

## **Easy TFServer**

- try simple example from tensorflow document.

  ```bash
  # Download the TensorFlow Serving Docker image and repo
  $ docker pull tensorflow/serving

  $ git clone https://github.com/tensorflow/serving
  # Location of demo models
  TESTDATA="$(pwd)/serving/tensorflow_serving/servables/tensorflow/testdata"

  # Start TensorFlow Serving container and open the REST API port
  $ docker run -it --rm -p 8501:8501 \
      -v "$TESTDATA/saved_model_half_plus_two_cpu:/models/half_plus_two" \
      -e MODEL_NAME=half_plus_two \
      tensorflow/serving &

  # Query the model using the predict API
  # need to create a new terminal.
  $ curl -d '{"instances": [1.0, 2.0, 5.0]}' \
      -X POST http://localhost:8501/v1/models/half_plus_two:predict

  # Returns => { "predictions": [2.5, 3.0, 4.5] }
  ```

- Docker common command.

  ```bash
  #kill all the alive image.
  $ docker kill $(docker ps -q)

  #stop all the alinve image
  $ docker stop $(docker ps -q)

  # remove all non-running image
  $ docker rm $$(docker ps -aq)

  # check all images
  $ dokcker ps -a

  #check the all alive image.
  $ docker ps

  #run a serving image as a daemon with a readable name.
  $ docker run -d --name serving_base tensorflow/serving

  #execute a command in the docker, you should substitute $(docker image name) for you own image name.
  $ docker exec -it ${docker image name} sh -c "cd /tmp"

  # enter docker ubuntu bash
  $ docker exec -it ${docker image name} bash -l
  ```

## **Run Server with your own saved pretrain models**

- make sure your model directory like this:

  ```text
  ---save
      |
      ---Model Name
            |
            ---1
                |
                ---asset
                |
                ---variables
                |
                ---model.pb
  ```

- substitute **user_define_model_name** for you own model name and **path_to_your_own_models** for directory path of your own model

  ```bash
  # run the server.
  $ docker run -it --rm -p 8501:8501 -v "$(pwd)/${path_to_your_own_models}/1:/models/${user_define_model_name}" -e MODEL_NAME=${user_define_model_name} tensorflow/serving &

  #run the client.
  $ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/${user_define_model_name}:predict
  ```

- you also can use tensorflow_model_server command after entering docker bash

  ```bash
  $ docker exec -it ${docker image name} bash -l

  $ tensorflow_model_server --port=8500 --rest_api_port=8501 --model_name=${MODEL_NAME} --model_base_path=${MODEL_BASE_PATH}/${MODEL_NAME}
  ```

- example
  - Save the model after running LinearKeras.py 

    ```bash
    $ docker run -it --rm -p 8501:8501 -v "$(pwd)/save/Toy:/models/Toy" -e MODEL_NAME=Toy tensorflow/serving &

    $ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/Toy:predict

    # {
    #     "predictions": [[0.999035]
    #     ]
    ```

- bind your own model to the server
  - bind bash path to the model.

    ```bash
    $ docker run -p 8501:8501 --mount type=bind,source=/path/to/my_model/,target=/models/my_model -e MODEL_NAME=my_model -it tensorflow/serving
    ```

- example

  ```bash
  $ docker run -p 8501:8501 --mount type=bind,source=$(pwd)/save/Toy,target=/models/Toy -e MODEL_NAME=Toy -it tensorflow/serving

  $ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/Toy:predict

  # {
  #     "predictions": [[0.999035]
  #     ]
  ```

## RESTful API

- data is like

  |   a   |   b   |   c   |   d   |   e   |   f   |
  | :---: | :---: | :---: | :---: | :---: | :---: |
  |  390  |  25   |   1   |   1   |   1   |   2   |
  |  345  |  34   |  45   |   2   |  34   | 3456  |

- `instances` means a row of data

  ```json
  {"instances": [
      {
        "a": [[390]],
        "b": [[25]],
        "c": [[1]],
        "d": [[1]],
        "e": [[1]],
        "f": [[2]]
      },
      {
        "a": [[345]],
        "b": [[34]],
        "c": [[45]],
        "d": [[2]],
        "e": [[34]],
        "f": [[3456]]
      }
    ]
  }
  ```

- `inputs` means a column of data

  ```json
    {"inputs":
      {
        "a": [[390], [345]],
        "b": [[25], [34]],
        "c": [[1], [45]],
        "d": [[1], [2]],
        "e": [[1], [34]],
        "f": [[2], [3456]]
      },
    }
  ```

- [REST API](https://www.tensorflow.org/tfx/serving/api_rest)

## **Run multiple model in TFServer**

- set up the configuration file named Toy.config

  ```protobuf
  model_config_list: {
    config: {
      name: "Toy",
      base_path: "/models/save/Toy/",
      model_platform: "tensorflow"
    },
    config: {
      name: "Toy_double",
      base_path: "/models/save/Toy_double/",
      model_platform: "tensorflow"
    }
  }
  ```

- substitute **Config Path** for you own configeratin file.
  
  ```bash
  docker run -it --rm -p 8501:8501 -v "$(pwd):/models/" tensorflow/serving --model_config_file=/models/${Config Path} --model_config_file_poll_wait_seconds=60
  ```

- example

  ```bash
  $ docker run -it --rm -p 8501:8501 -v "$(pwd):/models/" tensorflow/serving --model_config_file=/models/config/Toy.config

  $ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/Toy_double:predict
  # {
  #     "predictions": [[6.80301666]
  #     ]
  # }

  $ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/Toy:predict
  # {
  #     "predictions": [[0.999035]
  #     ]`
  # }
  ```

- bind your own path to TFserver. The model target path is related to the configuration file.

  ```bash
  $ docker run --rm -p 8500:8500 -p 8501:8501 \
    --mount type=bind,source=${/path/to/my_model/},target=/models/${my_model} \
    --mount type=bind,source=${/path/to/my/models.config},target=/models/${models.config} -it tensorflow/serving --model_config_file=/models/{models.config}
  ```

- example

  ```bash
  $ docker run --rm -p 8500:8500 -p 8501:8501 --mount type=bind,source=$(pwd)/save/,target=/models/save --mount type=bind,source=$(pwd)/config/Toy.config,target=/models/Toy.config -it tensorflow/serving --model_config_file=/models/Toy.config

  $ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/Toy_double:predict
  # {
  #     "predictions": [[6.80301666]
  #     ]
  # }

  $ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/Toy:predict
  # {
  #     "predictions": [[0.999035]
  #     ]
  # }
  ```

## **Version control for TFServer**

- set up single version control configuration file.

  ```protobuf
  model_config_list: {
    config: {
      name: "Toy",
      base_path: "/models/save/Toy/",
      model_platform: "tensorflow",
      model_version_policy: {
          specific {
              versions: 1
          }
      }
    },
    config: {
      name: "Toy_double",
      base_path: "/models/save/Toy_double/",
      model_platform: "tensorflow"
    }
  }
  ```

- set up multiple version control configuration file.

  ```protobuf
  model_config_list: {
    config: {
      name: "Toy",
      base_path: "/models/save/Toy/",
      model_platform: "tensorflow",
      model_version_policy: {
          specific {
              versions: 1,
              versions: 2
          }
      }
    },
    config: {
      name: "Toy_double",
      base_path: "/models/save/Toy_double/",
      model_platform: "tensorflow"
    }
  }
  ```

- example

  ```bash
  $ docker run --rm -p 8500:8500 -p 8501:8501 --mount type=bind,source=$(pwd)/save/,target=/models/save --mount type=bind,source=$(pwd)/config/versionctrl.config,target=/models/versionctrl.config -it tensorflow/serving --model_config_file=/models/versionctrl.config --model_config_file_poll_wait_seconds=60
  ```

- for POST

  ```bash
  $ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/Toy/versions/1:predict
  # {
  #     "predictions": [[10.8054295]
  #     ]
  # }

  $ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/Toy/versions/2:predict
  # {
  #     "predictions": [[0.999035]
  #     ]
  # }
  ```

- for gRPC

  ```bash
    $ python3 grpcRequest.py -v 1
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

- set an alias label for each version. Only avaliable for gRPC.

  ```protobuf
  model_config_list: {
    config: {
      name: "Toy",
      base_path: "/models/save/Toy/",
      model_platform: "tensorflow",
      model_version_policy: {
          specific {
              versions: 1,
              versions: 2
          }
      },
      version_labels {
        key: 'stable',
        value: 1
      },
      version_labels {
        key: 'canary',
        value: 2
      }
    },
    config: {
      name: "Toy_double",
      base_path: "/models/save/Toy_double/",
      model_platform: "tensorflow"
    }
  }
  ```

- refer to [https://www.tensorflow.org/tfx/serving/serving_config](https://www.tensorflow.org/tfx/serving/serving_config)

    Please **note that** labels can only be assigned to model versions that are loaded and available for serving. Once a model version is available, one may reload the model config on the fly, to assign a label to it (can be achieved using HandleReloadConfigRequest RPC endpoint).

    Maybe you should delete the label related part first, then start the tensorflow serving, and finally add the label related part to the config file on the fly.

- set flag `--allow_version_labels_for_unavailable_models` true will be able to add version lables at the first runing.

  ``` bash
  $ docker run --rm -p 8500:8500 -p 8501:8501 --mount type=bind,source=$(pwd)/save/,target=/models/save --mount type=bind,source=$(pwd)/config/versionlabels.config,target=/models/versionctrl.config -it tensorflow/serving --model_config_file=/models/versionctrl.config --model_config_file_poll_wait_seconds=60 --allow_version_labels_for_unavailable_models
  ```

  ```bash
  $ python3 grpcRequest.py -l stable
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

## **Other Configuration parameter**

- [Configuration](https://github.com/tensorflow/serving/tree/master/tensorflow_serving/config)

- Batch Configuration: need to set `--enable_batching=true` and pass the config to `--batching_parameters_file`, [more](https://github.com/tensorflow/serving/blob/master/tensorflow_serving/batching/README.md#batch-scheduling-parameters-and-tuning)

  - CPU-only: One Approach
  
    If your system is CPU-only (no GPU), then consider starting with the following values: `num_batch_threads` equal to the number of CPU cores; `max_batch_size` to infinity; `batch_timeout_micros` to 0. Then experiment with `batch_timeout_micros` values in the 1-10 millisecond (1000-10000 microsecond) range, while keeping in mind that 0 may be the optimal value.

  - GPU: One Approach

    If your model uses a GPU device for part or all of your its inference work, consider the following approach:

    Set `num_batch_threads` to the number of CPU cores.

    Temporarily set `batch_timeout_micros` to infinity while you tune `max_batch_size` to achieve the desired balance between throughput and average latency. Consider values in the hundreds or thousands.

    For online serving, tune `batch_timeout_micros` to rein in tail latency. The idea is that batches normally get filled to `max_batch_size`, but occasionally when there is a lapse in incoming requests, to avoid introducing a latency spike it makes sense to process whatever's in the queue even if it represents an underfull batch. The best value for `batch_timeout_micros` is typically a few milliseconds, and depends on your context and goals. Zero is a value to consider; it works well for some workloads. (For bulk processing jobs, choose a large value, perhaps a few seconds, to ensure good throughput but not wait too long for the final (and likely underfull) batch.)

    `batch.config`

    ```protobuf
    max_batch_size { value: 1 }
    batch_timeout_micros { value: 0 }
    max_enqueued_batches { value: 1000000 }
    num_batch_threads { value: 8 }
    ```

  - example

    ```bash
    docker run --rm -p 8500:8500 -p 8501:8501 --mount type=bind,source=$(pwd),target=/models --mount type=bind,source=$(pwd)/config/versionctrl.config,target=/models/versionctrl.config -it tensorflow/serving --model_config_file=/models/versionctrl.config --model_config_file_poll_wait_seconds=60 --enable_batching=true --batching_parameters_file=/models/batch/batchpara.config
    ```

- monitor: pass file path to `--monitoring_config_file`

    `monitor.config`

    ```protobuf
    prometheus_config {
        enable: true,
        path: "/models/metrics"
    }
    ```

  - request through RESTful API
    - example
      - server

        ```bash
        $ docker run --rm -p 8500:8500 -p 8501:8501 -v "$(pwd):/models" -it tensorflow/serving --model_config_file=/models/config/versionlabels.config --model_config_file_poll_wait_seconds=60 --allow_version_labels_for_unavailable_models --monitoring_config_file=/models/monitor/monitor.config
        ```

      - client

        ```bash
        $ curl -X GET http://localhost:8501/monitoring/prometheus/metrics
        # # TYPE :tensorflow:api:op:using_fake_quantization gauge
        # # TYPE :tensorflow:cc:saved_model:load_attempt_count counter
        # :tensorflow:cc:saved_model:load_attempt_count{model_path="/models/save/Toy/1",status="success"} 1
        # :tensorflow:cc:saved_model:load_attempt_count{model_path="/models/save/Toy/2",status="success"} 1
        # ...
        # # TYPE :tensorflow:cc:saved_model:load_latency counter
        # :tensorflow:cc:saved_model:load_latency{model_path="/models/save/Toy/1"} 54436
        # :tensorflow:cc:saved_model:load_latency{model_path="/models/save/Toy/2"} 45230
        # ...
        # # TYPE :tensorflow:mlir:import_failure_count counter
        # # TYPE :tensorflow:serving:model_warmup_latency histogram
        # # TYPE :tensorflow:serving:request_example_count_total counter
        # # TYPE :tensorflow:serving:request_example_counts histogram
        # # TYPE :tensorflow:serving:request_log_count counter
        ```

  - show monitor data in the prometheus docker
    - modified your own prometheus configuration file

      ```yaml
      # my global config
      global:
        scrape_interval:     15s # Set the scrape interval to every 15 seconds. Default is every 1 minute.
        evaluation_interval: 15s # Evaluate rules every 15 seconds. The default is every 1 minute.
        # scrape_timeout is set to the global default (10s).

      # Alertmanager configuration
      alerting:
        alertmanagers:
        - static_configs:
          - targets:
            # - alertmanager:9093

      # Load rules once and periodically evaluate them according to the global 'evaluation_interval'.
      rule_files:
        # - "first_rules.yml"
        # - "second_rules.yml"

      # A scrape configuration containing exactly one endpoint to scrape:
      # Here it's Prometheus itself.
      scrape_configs:
        - job_name: 'tensorflow'
          scrape_interval: 5s
          metrics_path: '/monitoring/prometheus/metrics'
          static_configs:
      - targets: ['docker.for.mac.localhost:8501'] # for `Mac users`
      # - targets: ['127.0.0.1:8501']
      ```

    - start prometheus docker server

    ```bash
    $ docker run --rm -ti --name prometheus -p 127.0.0.1:9090:9090 -v "$(pwd)/monitor:/tmp" prom/prometheus --config.file=/tmp/prometheus/prome.yaml
    ```

    - access prometheus on the webUI
      - check target and status
      ![target](image4md/target.png)
      ![status](image4md/status.png)
      - webUI on [localhost:9090](http://localhost:9090/)
      ![graph](image4md/prom_graph.png)

  <!-- - request with gRPC TODO: -->

## **Obtain the information**

- get the information data structure.

  ```bash
  curl -d '{"instances": [[1.0, 2.0]]}' -X GET http://localhost:8501/v1/models/Toy/metadata
  ```

- get the information data structure with gRPC

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

## **Accerleration by GPU**

- pull tensorflow server GPU version from DockerHub.

  ```bash
  docker pull tensorflow/serving:latest-gpu
  ```

- clone the server.git if you haven't done it.

  ```bash
  git clone https://github.com/tensorflow/serving
  ```

- set `--runtime==nvidia` and use the `tensorflow/serving:latest-gpu`

  ```bash
  docker run --runtime=nvidia -p 8501:8501 -v "$(pwd)/${path_to_your_own_models}/1:/models/${user_define_model_name}" -e MODEL_NAME=${user_define_model_name} tensorflow/serving &
  ```

- example

  ```bash
  docker run --runtime=nvidia -p 8501:8501 -v "$(pwd)/save/Toy:/models/Toy" -e MODEL_NAME=Toy tensorflow/serving:latest-gpu &
  or
  nvidia-docker run -p 8501:8501 -v "$(pwd)/save/Toy:/models/Toy" -e MODEL_NAME=Toy tensorflow/serving:latest-gpu &
  or
  docker run --gpu ${all/1} -p 8501:8501 -v "$(pwd)/save/Toy:/models/Toy" -e MODEL_NAME=Toy tensorflow/serving:latest-gpu &
  ```

## Setup gRPC and POST request using Python files

- setup environment

  ```bash
  pip install numpy tensorflow tensorflow-serving-api grpcio
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

- run grpcRequest.py

  ```bash
  python3 grpcRequest.py
  # outputs {
  #   key: "dense"
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
  #     float_val: 0.9901617765426636
  #     float_val: 0.9934704303741455
  #   }
  # }
  # model_spec {
  #   name: "Toy"
  #   version {
  #     value: 3
  #   }
  #   signature_name: "serving_default"
  # }
  ```

- get model status and reload model using grpc

  - run server

    ```bash
    $ docker run --rm -p 8500:8500 -p 8501:8501 --mount type=bind,source=$(pwd)/save/,target=/models/save --mount type=bind,srce=$(pwd)/config/versionlabels.config,target=/models/versionctrl.config -it tensorflow/serving --model_config_file=/models/versionctrl.config --model_config_file_poll_wait_seconds=60 --allow_version_labels_for_unavailable_models
    ```
  
  - run client

    ```bash
    $ python grpcMetadata.py
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

    # *******************************************model metadata*******************************************
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

    # status {
    # }

    # Reload sucessfully
    # ************************************************end*************************************************
    ```

  - from Server

    ```bash
    # 2020-05-28 10:38:51.057588: I tensorflow_serving/model_servers/model_service_impl.cc:47]
    # Config entry
    #   index : 0
    #   path : /models/save/Toy/
    #   name : Toy
    #   platform : tensorflow
    # 2020-05-28 10:38:51.057775: I tensorflow_serving/model_servers/server_core.cc:462] Adding/updating models.
    # 2020-05-28 10:38:51.057843: I tensorflow_serving/model_servers/server_core.cc:573]  (Re-)adding model: Toy
    # 2020-05-28 10:38:51.156301: I tensorflow_serving/core/loader_harness.cc:138] Quiescing servable version {name: Toy_double version: 1}
    # 2020-05-28 10:38:51.156406: I tensorflow_serving/core/loader_harness.cc:145] Done quiescing servable version {name: Toy_double version: 1}
    # 2020-05-28 10:38:51.156442: I tensorflow_serving/core/loader_harness.cc:120] Unloading servable version {name: Toy_double version: 1}
    # ...
    # 2020-05-28 10:38:52.083807: I tensorflow_serving/core/loader_harness.cc:128] Done unloading servable version {name: Toy version: 2}
    ```

- [RESTful API](https://www.tensorflow.org/tfx/serving/api_rest)

- run POSTreq.py

  ```bash
  python3 POSTreq.py
  # this request is based on isntances
  # True
  # {
  #     "predictions": [[0.990161777], [0.99347043]
  #     ]
  # }
  # time consumption: 47.346710999999985ms
  # this request is based on inputs
  # True
  # {
  #     "outputs": [
  #         [
  #             0.985201657
  #         ],
  #         [
  #             0.99923408
  #         ]
  #     ]
  # }
  # time consumption: 6.932738000000049ms
  ```

