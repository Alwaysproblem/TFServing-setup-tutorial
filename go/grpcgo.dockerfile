FROM ubuntu:18.04

RUN apt-get update \
    && apt-get install software-properties-common -y \
    && apt-get install autoconf automake libtool curl make g++ unzip -y wget \
    && apt-get install pkg-config libgflags-dev build-essential cmake clang-5.0 libc++-dev -y \
    && apt-get install doxygen git libboost-all-dev vim -y \
    && apt-get clean

RUN wget https://dl.google.com/go/go1.12.7.linux-amd64.tar.gz \
    && tar -xvf go1.12.7.linux-amd64.tar.gz \
    && mv go /usr/local

# install protobuf C++
RUN cd / \
    && git clone -b v3.12.4 https://github.com/google/protobuf \
    && cd protobuf \
    && git submodule update --init --recursive \
    && ./autogen.sh \
    && ./configure \
    && make \
    && make check \
    && make install \
    && ldconfig \
    && cd ..

ENV PATH=$PATH:/protobuf/src/protoc:/usr/local/go/bin

WORKDIR /root/tfclient/src

COPY src /root/tfclient/src
