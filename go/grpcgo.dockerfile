FROM ubuntu:20.04

RUN apt-get update \
    && apt-get install software-properties-common -y \
    && apt-get install git golang-go protobuf-compiler-grpc libprotobuf-dev -y \
    && mkdir -p /go \
    && apt-get clean

ENV GOPATH=/go
ENV PATH=$PATH:/usr/lib/go-1.14/bin:$GOPATH/bin

RUN go get -u -v google.golang.org/grpc \
    && go get -u -v github.com/golang/protobuf/proto \
    && go get -u -v github.com/golang/protobuf/protoc-gen-go

WORKDIR /work