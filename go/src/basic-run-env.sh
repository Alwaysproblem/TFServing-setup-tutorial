#!/bin/bash

# source env.sh
go get -u -v google.golang.org/grpc
go get -u -v github.com/golang/protobuf/proto
go get -u -v github.com/golang/protobuf/protoc-gen-go
go get -u -v golang.org/x/net/context
go get -u -v go.uber.org/ratelimit