FROM ubuntu:18.04

RUN apt-get update \
    && apt-get install software-properties-common -y \
    && apt-get install autoconf automake libtool curl make g++ unzip build -y \
    && apt-get install protobuf-compiler-grpc libprotobuf-dev build-essential -y \
    && apt-get install \
    && apt-get clean