# GO API

## Build your own go TFclient (optional)

- Thanks to [Maxim Khitrov](https://gist.github.com/mxk) and [datainq](https://github.com/datainq/go-mnist-client). Here is [reference](https://gist.github.com/mxk/b86769306037c9dc49b44d52764cbbdc)

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

  <!-- TODO: simplify these with bash run in docker -->

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
  $ cp env.sh <to your src>
  $ cp basic-run-env.sh <to your src>
  $ cp main.go <to your src>
  $ cp -R utils <to your src>
  $ cp run.sh <to your src>
  ```

- run server

  ```bash
  $ docker run --rm -p 8500:8500 -p 8501:8501 --mount type=bind,source=$(pwd),target=/models --mount type=bind,source=$(pwd)/config/versionctrl.config,target=/models/versionctrl.config -it tensorflow/serving --model_config_file=/models/versionctrl.config --model_config_file_poll_wait_seconds=60
  ```

- run the test on the client
  - install dependency

    ```bash
    # assume you are in go directory
    $ cd src
    $ source env.sh
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
