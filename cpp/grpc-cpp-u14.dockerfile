FROM ubuntu:14.04

RUN apt-get update \
    && apt-get install software-properties-common -y \
    && add-apt-repository ppa:ubuntu-toolchain-r/test \
    && apt-get update \
    && apt-get install autoconf automake libtool curl make unzip -y \
    && apt-get install pkg-config libgflags-dev build-essential libc++-dev -y \
    && apt-get install doxygen git libboost-all-dev wget -y \
    && apt-get install gcc-6 g++-6 -y \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 80 --slave /usr/bin/g++ g++ /usr/bin/g++-6 \
    && apt-get clean

RUN cd / \
    && wget http://www.cmake.org/files/v3.12/cmake-3.12.1.tar.gz \
    && tar -xvzf cmake-3.12.1.tar.gz \
    && cd cmake-3.12.1/ \
    && ./configure \
    && make \
    && make install

# install protobuf C++
RUN cd / \
    && git clone https://github.com/google/protobuf \
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
