#bin/bash

set -ex

mkdir -p gen

OUT=gen

INT=/tensorflow
protoc -I=$INT --go_out=plugins=grpc:$OUT \
    $INT/tensorflow/core/framework/*.proto
    
protoc -I=$INT --go_out=plugins=grpc:$OUT \
    $INT/tensorflow/core/protobuf/*.proto $INT/tensorflow/stream_executor/*.proto

# protoc --proto_path=$IN --go_out=plugins=grpc:$OUT \
#     $IN/tensorflow/stream_executor/*.proto

protoc -I=$INT --go_out=plugins=grpc:$OUT \
    $INT/tensorflow/core/lib/core/*.proto
    
protoc -I=$INT --go_out=plugins=grpc:$OUT \
    $INT/tensorflow/core/example/*.proto


INS=/serving
protoc -I=$INS -I=$INT --go_out=plugins=grpc:$OUT --go_opt=paths=source_relative \
    $INS/tensorflow_serving/apis/*.proto \
    $INS/tensorflow_serving/config/*.proto \
    $INS/tensorflow_serving/core/*.proto \
    $INS/tensorflow_serving/sources/storage_path/*.proto \
    $INS/tensorflow_serving/util/*.proto

# try  # --go_opt=module=github.com/foo/bar \
