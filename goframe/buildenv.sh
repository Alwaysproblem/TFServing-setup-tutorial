rm -rf src/github.com/golang/
rm -rf src/go.uber.org/
rm -rf src/golang.org/
rm -rf src/google.golang.org/
rm -rf src/gopath
rm -rf pkg/*

go get -u golang.org/x/net/context
go get -u github.com/golang/protobuf/{proto,protoc-gen-go}
go get -u google.golang.org/grpc
go get -u github.com/tensorflow/tensorflow/tensorflow/go
go get -u go.uber.org/ratelimit