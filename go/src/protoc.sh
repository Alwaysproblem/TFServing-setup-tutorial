set -ex
INT=/tensorflow
INS=/serving
OUT=$(pwd)/proto

mkdir -p $OUT
chmod 777 $OUT

protoc -I=$INT -I=$INS --go_out=plugins=grpc:$OUT  \
    $INT/tensorflow/core/example/*.proto \
    $INT/tensorflow/core/framework/*.proto \
    $INT/tensorflow/core/lib/core/*.proto \
    $INT/tensorflow/core/protobuf/*.proto \
    $INT/tensorflow/stream_executor/*.proto

protoc -I=$INT -I=$INS --go_out=plugins=grpc,import_path=serving:$OUT \
    $INS/tensorflow_serving/apis/*.proto \
    $INS/tensorflow_serving/config/*.proto \
    $INS/tensorflow_serving/core/*.proto \
    $INS/tensorflow_serving/sources/storage_path/*.proto \
    $INS/tensorflow_serving/util/*.proto

mkdir -p $OUT/alwaysproblem/tensorflow_serving
# mv $OUT/tensorflow_serving $OUT/alwaysproblem/tensorflow_serving
mv $(find $OUT/tensorflow_serving -name *.pb.go) $OUT/alwaysproblem/tensorflow_serving
find $OUT/tensorflow_serving -type d -empty -delete

set +ex