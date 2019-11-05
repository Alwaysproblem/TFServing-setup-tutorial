# TFServing-setup-review

## basic tutorial for Tensorflow Serving.

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
$ docker run -t --rm -p 8501:8501 \
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

#check the all alive image.
$ docker ps

#run a serving image as a daemon
$ docker run -d --name serving_base tensorflow/serving

#execute a command in the docker, you should substitute $(docker image name) for you own image name.
$ docker run -it ${docker image name} sh -c "cd /tmp"
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