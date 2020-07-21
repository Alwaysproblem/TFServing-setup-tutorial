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

*[basic tutorial](https://github.com/Alwaysproblem/TFServing-setup-tutorial/tree/master)*

## Run Server

- here is no batch configuration only for demonstration

```bash
$ docker run --rm -p 8500:8500 -p 8501:8501 -v `pwd`:/models -it tensorflow/serving --model_config_file=/models/config/versionlabels.config --model_config_file_poll_wait_seconds=60 --allow_version_labels_for_unavailable_models
```

## Tutorial for gRPC API

- [GO](./go/README.md)
- [Python](./python/README.md)
- [Cpp](./cpp/README.md)