# go-pro

go language

## generated .pb.go file with protoc-gen-go plugin

/usr/local/bin/protoc --go_out=. -I . ./tensorflow_serving/predict.proto

## gRPC Support

/usr/local/bin/protoc --go_out=plugins=grpc:. -I . ./tensorflow_serving/prediction_service.proto

注

1. 使用选项-I或--proto_path通知protoc去什么地方查找import的文件(import文件路径写法，则根据-I的path为根目录)，如果不指定，protoc将会在当前目录(即调用protoc的路径)下查找  

2. 一般选择在$GOPATH/src目录为当前目录
