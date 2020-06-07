#!/bin/bash

# TODO: test this work
# please mount src to /work in docker
git clone -b r1.15 https://github.com/tensorflow/tensorflow.git
git clone -b r1.14 https://github.com/tensorflow/serving.git
go run protoc.go # ignore the warning but this procedure only works under specific protoc version
go mod init client
go mod edit -replace=github.com/tensorflow/tensorflow/tensorflow/go/core=./proto/tensorflow/core
go mod edit -replace=github.com/alwaysproblem/tensorflow_serving=./proto/tensorflow/serving
cd proto/tensorflow/core && go mod init github.com/tensorflow/tensorflow/tensorflow/go/core && cd -
cd proto/tensorflow/serving && go mod init github.com/alwaysproblem/tensorflow_serving && cd -
rm -rf tensorflow/ serving/