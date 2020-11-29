FROM ubuntu:18.04

RUN apt-get update \
    && apt-get install software-properties-common -y \
    && apt-get install autoconf automake libtool curl make g++-6 unzip -y \
    && apt-get install pkg-config libgflags-dev build-essential cmake clang-5.0 libc++-dev -y \
    && apt-get install doxygen git libboost-all-dev -y \
    && apt-get clean

# install protobuf C++
RUN cd / \
    && git clone -b v3.12.4 https://github.com/google/protobuf \
    && cd protobuf \
    && git submodule update --init --recursive \
    && ./autogen.sh \
    && ./configure --disable-shared \
    && make \
    && make check \
    && make install \
    && ldconfig \
    && cd ..

# install grpc
RUN cd / \
    && git clone -b v1.29.1 https://github.com/grpc/grpc \
    && cd grpc \
    && git submodule update --init \
    && mkdir -p cmake/build \
    && cd cmake/build \
    && cmake ../.. -DgRPC_PROTOBUF_PROVIDER=package \
    && make \
    && make install \
    && cd /

ENV PATH=$PATH:/grpc/cmake/build/
ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/:/grpc/cmake/build/