#bin/bash

set -ex

mkdir -p /cpp/gen

OUT=/cpp/gen

INT=/tensorflow
protoc -I=$INT --cpp_out=$OUT --grpc_out=$OUT --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
    $INT/tensorflow/core/framework/*.proto
    
protoc -I=$INT --cpp_out=$OUT --grpc_out=$OUT --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
    $INT/tensorflow/core/protobuf/*.proto $INT/tensorflow/stream_executor/*.proto

# protoc --proto_path=$IN --go_out=plugins=grpc:$OUT \
#     $IN/tensorflow/stream_executor/*.proto

protoc -I=$INT --cpp_out=$OUT --grpc_out=$OUT --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
    $INT/tensorflow/core/lib/core/*.proto
    
protoc -I=$INT --cpp_out=$OUT --grpc_out=$OUT --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
    $INT/tensorflow/core/example/*.proto


INS=/serving
protoc -I=$INS -I=$INT --cpp_out=$OUT --grpc_out=$OUT --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
    $INS/tensorflow_serving/apis/*.proto \
    $INS/tensorflow_serving/config/*.proto \
    $INS/tensorflow_serving/core/*.proto \
    $INS/tensorflow_serving/sources/storage_path/*.proto \
    $INS/tensorflow_serving/util/*.proto 