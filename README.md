# Tensorflow Serving Client API

## Basic tutorial for Tensorflow Serving Client API

## **Requiement**

- Docker
- GO (>= 1.11) for go API
- Python for python API

## **Install Docker**

- **Window/MacOS**: install Docker from [DockerHub](https://hub.docker.com/?overlay=onboarding). (*need to register new account if you are newbie*)

- **linux**: install [Docker](https://runnable.com/docker/install-docker-on-linux)

## **Tutorial for starting**

```bash
$ git clone https://github.com/Alwaysproblem/TFServing-setup-review.git

$ cd TFServing-setup-review
$ git checkout tfclient
```

## **Easy TFServer**

- here is no batch configuration only for demonstration

```bash
$ docker run --rm -p 8500:8500 -p 8501:8501 -v `pwd`:/models -it tensorflow/serving --model_config_file=/models/config/versionlabels.config --model_config_file_poll_wait_seconds=60 --allow_version_labels_for_unavailable_models
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
```
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
$ docker run -t --rm -p 8501:8501 -v "$(pwd)/${path_to_your_own_models}/1:/models/${user_define_model_name}" -e MODEL_NAME=${user_define_model_name} tensorflow/serving &

#run the client.
$ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/${user_define_model_name}:predict
```

- you also can use tensorflow_model_server command after entering docker bash
```bash
$ docker exec -it ${docker image name} bash -l

$ tensorflow_model_server --port=8500 --rest_api_port=8501 --model_name=${MODEL_NAME} --model_base_path=${MODEL_BASE_PATH}/${MODEL_NAME}
```

- example
  + Save the model after running LinearKeras.py 

```bash
$ docker run -t --rm -p 8501:8501 -v "$(pwd)/save/Toy:/models/Toy" -e MODEL_NAME=Toy tensorflow/serving &

$ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/Toy:predict

# {
#     "predictions": [[0.999035]
#     ]
```

- bind your own model to the server
  - bind bash path to the model.

```bash
$ docker run -p 8501:8501 --mount type=bind,source=/path/to/my_model/,target=/models/my_model -e MODEL_NAME=my_model -t tensorflow/serving
```

- example

```bash
$ docker run -p 8501:8501 --mount type=bind,source=$(pwd)/save/Toy,target=/models/Toy -e MODEL_NAME=Toy -t tensorflow/serving

$ curl -d '{"instances": [[1.0, 2.0]]}' -X POST http://localhost:8501/v1/models/Toy:predict

# {
#     "predictions": [[0.999035]
#     ]
```

## RESTful API

- `instances` means a row of data
- `inputs` means a column of data
- if you have mutiple inputs, it should be like (' ' is not working)

```json
{"instances": [
  {
    "a": [390511], 
    "b": [25],
    "c": [1],
    "d": [1],
    "e": [1], 
    "f": [2], 
    "g": [111], 
    "j": [1], 
    "s": [3617, 607, 42, 5, ...], 
    "q": [141, 142, 143, ...]
    }
  {
    "a": [3905], 
    "b": [25],
    "c": [1],
    "d": [1],
    "e": [4], 
    "f": [2], 
    "g": [11], 
    "j": [1], 
    "s": [3617, 607, 42, 35, ...], 
    "q": [141, 12, 143, ...]
    }
  ]
}
```

- [REST API](https://github.com/tensorflow/serving/blob/master/tensorflow_serving/g3doc/api_rest.md)


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
$ docker run -t --rm -p 8501:8501 -v "$(pwd):/models/" tensorflow/serving --model_config_file=/models/${Config Path} --model_config_file_poll_wait_seconds=60
```

- example

```bash
$ docker run -t --rm -p 8501:8501 -v "$(pwd):/models/" tensorflow/serving --model_config_file=/models/config/Toy.config

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
$ docker run -p 8500:8500 -p 8501:8501 \
  --mount type=bind,source=${/path/to/my_model/},target=/models/${my_model} \
  --mount type=bind,source=${/path/to/my/models.config},target=/models/${models.config} -t tensorflow/serving --model_config_file=/models/{models.config}
```

- example

```bash
$ docker run -p 8500:8500 -p 8501:8501 --mount type=bind,source=$(pwd)/save/,target=/models/save --mount type=bind,source=$(pwd)/config/Toy.config,target=/models/Toy.config -t tensorflow/serving --model_config_file=/models/Toy.config

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
$ docker run -p 8500:8500 -p 8501:8501 --mount type=bind,source=$(pwd)/save/,target=/models/save --mount type=bind,source=$(pwd)/config/versionctrl.config,target=/models/versionctrl.config -t tensorflow/serving --model_config_file=/models/versionctrl.config --model_config_file_poll_wait_seconds=60


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

- refer to [serving_config](https://www.tensorflow.org/tfx/serving/serving_config)

    Please **note that** labels can only be assigned to model versions that are loaded and available for serving. Once a model version is available, one may reload the model config on the fly, to assign a label to it (can be achieved using HandleReloadConfigRequest RPC endpoint).

    Maybe you should delete the label related part first, then start the tensorflow serving, and finally add the label related part to the config file on the fly.

<!-- - response
``` bash

``` -->

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
$ docker run -p 8500:8500 -p 8501:8501 --mount type=bind,source=$(pwd),target=/models --mount type=bind,source=$(pwd)/config/versionctrl.config,target=/models/versionctrl.config -t tensorflow/serving --model_config_file=/models/versionctrl.config --model_config_file_poll_wait_seconds=60 --enable_batching=true --batching_parameters_file=/models/batch/batchpara.config
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
$ curl -d '{"instances": [[1.0, 2.0]]}' -X GET http://localhost:8501/v1/models/Toy/metadata
```


## **Accerleration by GPU**

- pull tensorflow server GPU version from DockerHub.

```bash
$ docker pull tensorflow/serving:latest-gpu
```

- clone the server.git if you haven't done it.

```bash
$ git clone https://github.com/tensorflow/serving
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
$ pip install numpy tensorflow tensorflow-serving-api grpcio
```

- run grpcRequest.py

```bash
$ python3 grpcRequest.py
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
$ python3 POSTreq.py
# {
#     "predictions": [[0.990161777], [0.99347043]
#     ]
# }
```

## For non-standard input model

**Note that this example use my own dataset**

- create a virtual env

- git checkout -b feature_column_serving

- mount current directory to model folder in docker.

- substitute ${name} for your own alias for docker image.

```bash
$ docker run --rm -it --name holy-shit -p 8501:8501 -p 8500:8500 -v $(pwd):/models tensorflow/serving --model_config_file=/models/config/Toy.config
```

- enter the internal bash under docker.

```bash
$ docker exec -it tf2 bash -l
```

- run the tensorflow_model_server or get help.

```bash
root@2f3ad5e231d6# cd models
root@2f3ad5e231d6# tensorflow_model_server --model_name=FC --model_base_path=/models/save/FC/ --rest_api_port=8501
```

- run the grpcRequest.py and POSTreq.py
  - run grpcRequest.py

  ```bash
  outputs {
    key: "dense"
    value {
      dtype: DT_FLOAT
      tensor_shape {
        dim {
          size: 2
        }
        dim {
          size: 1
        }
      }
      float_val: 0.21722325682640076
      float_val: 0.7290472388267517
    }
  }
  model_spec {
    name: "FC"
    version {
      value: 1
    }
    signature_name: "serving_default"
  }
  ```

  - POSTreq.py

  ```bash
  this request is based on isntances
  True
  {
      "predictions": [[0.217223257], [0.729047239]
      ]
  }
  time consumption: 15.43633100000008ms
  this request is based on inputs
  True
  {
      "outputs": [
          [
              0.217223257
          ],
          [
              0.729047239
          ]
      ]
  }
  time consumption: 6.197227999999999ms
  ```

## the format for POST

[Here](https://www.tensorflow.org/tfx/serving/api_rest)
