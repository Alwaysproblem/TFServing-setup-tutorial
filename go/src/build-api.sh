#!/bin/bash

# TODO: test this work
# please mount src to /work in docker
git clone -b r2.3 https://github.com/tensorflow/tensorflow.git
git clone -b r2.3 https://github.com/tensorflow/serving.git
bash basic-run-env.sh
. env.sh
bash protoc.sh # ignore the warning but this procedure only works under specific protoc version
go mod init client
mv proto/github.com/tensorflow $GOPATH/src/github.com/
mv proto/alwaysproblem $GOPATH/src/github.com/
# cd proto/tensorflow/core && go mod init github.com/tensorflow/tensorflow/tensorflow/go/core && cd -
# cd github.com/alwaysproblem/tensorflow_serving && go mod init github.com/alwaysproblem/tensorflow_serving && cd -
rm -rf tensorflow/ serving/