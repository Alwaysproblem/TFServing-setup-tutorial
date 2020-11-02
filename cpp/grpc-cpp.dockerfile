FROM ubuntu:18.04

RUN apt-get update \
    && apt-get install software-properties-common -y \
    && apt-get install autoconf automake libtool curl make g++ unzip -y \
    && apt-get install pkg-config libgflags-dev build-essential cmake clang-5.0 libc++-dev -y \
    && apt-get install doxygen git libboost-all-dev -y \
    && apt-get clean
    # && apt-get install protobuf-compiler-grpc libprotobuf-dev  -y \

# sudo apt install curl gnupg
# curl https://bazel.build/bazel-release.pub.gpg | sudo apt-key add -
# echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
# sudo apt update && sudo apt install bazel

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

# install grpc
RUN cd / \
    && git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc \
    && cd grpc \
    && git submodule update --init \
    && mkdir -p cmake/build \
    && cd cmake/build \
    && cmake ../.. -DBUILD_SHARED_LIBS=ON \
    && make \
    && make install \
    && cd /

# add env
ENV PATH=$PATH:/grpc/cmake/build/
ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/:/grpc/cmake/build/