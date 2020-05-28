# TFServing-setup-review

## Basic tutorial for Tensorflow Serving.

## **Install Docker**

- **Window/MacOS**: install Docker from [DockerHub](https://hub.docker.com/?overlay=onboarding). (*need to register new account if you are newbie*)

- **linux**: install [Docker](https://runnable.com/docker/install-docker-on-linux)

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

## RESTful API TODO:

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

- set flag --allow_version_labels_for_unavailable_models=true will be able to add version lables at the first runing.

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

- batch: need to set `--enable_batching=true` and pass the config to `--batching_parameters_file`

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

## **Obtain the information**

- get the information data structure.

  ```bash
  curl -d '{"instances": [[1.0, 2.0]]}' -X GET http://localhost:8501/v1/models/Toy/metadata
  ```

## TODO: Prediction Logs

- 

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
