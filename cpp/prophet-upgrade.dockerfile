FROM ubuntu:14.04

ENV GITLAB_TOKEN=UT__2joSb5tY3x5JKk-Q

RUN apt-get update \
    && apt-get install software-properties-common -y \
    && add-apt-repository ppa:ubuntu-toolchain-r/test \
    && apt-get update \
    && apt-get install build-essential libboost-all-dev libc++-dev wget curl git scons g++ gcc  unzip -y \
    && apt-get install gcc-6 g++-6 -y \
    && apt-get install automake bison flex libevent-dev libssl-dev autoconf libtool make pkg-config libgflags-dev -y \
    && apt-get -y install  supervisor libffi-dev python-dev python-pip  libiberty-dev   libjemalloc-dev  libgoogle-glog-dev \
    && apt-get -y install libhashkit-dev libsasl2-dev snappy libsnappy-dev libcurl4-openssl-dev \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 80 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90 \
    && apt-get clean

#TODO: need to merge this.
# apt-get install mpi-default-dev libicu-dev python-dev python3-dev libbz2-dev zlib1g-dev


RUN cd \
    && git clone https://$GITLAB_TOKEN:$GITLAB_TOKEN@git.op-mobile.opera.com/adalgo/opera-ads-hermes \
    && git clone https://$GITLAB_TOKEN:$GITLAB_TOKEN@git.op-mobile.opera.com/adalgo/opera-ads-rosseta \
    && git clone https://$GITLAB_TOKEN:$GITLAB_TOKEN@git.op-mobile.opera.com/adalgo/opera-ads-prophet \
    && git clone https://$GITLAB_TOKEN:$GITLAB_TOKEN@git.op-mobile.opera.com/adalgo/opera-ads-athena \
    && git clone https://$GITLAB_TOKEN:$GITLAB_TOKEN@git.op-mobile.opera.com/adalgo/opera-ads-pandora \
    && git clone https://$GITLAB_TOKEN:$GITLAB_TOKEN@git.op-mobile.opera.com/adalgo/opera-ads-common \
    && ln -sf ./opera-ads-pandora pandora

# apt-get -y install  supervisor libffi-dev python-dev python-pip  libiberty-dev   libjemalloc-dev  libgoogle-glog-dev
# apt-get -y install libhashkit-dev libsasl2-dev snappy libsnappy-dev

# install boost v1.70
RUN cd /tmp \
    && wget https://dl.bintray.com/boostorg/release/1.70.0/source/boost_1_70_0.tar.gz \
    && tar -zxf boost_1_70_0.tar.gz \
    && cd boost_1_70_0 \
    && ./bootstrap.sh \
    && ./b2 \
    && ./b2 install

# install thrift and build thrift protocol
RUN cd /tmp \
    && curl https://archive.apache.org/dist/thrift/0.10.0/thrift-0.10.0.tar.gz | tar zx \
    && cd thrift-0.10.0 \
    && ./configure \
    && make \
    && make install \
    && ldconfig \
    && cd /root/opera-ads-common/thrift \
    && sh build.sh

# install cityhash from google
RUN cd /tmp \
    && git clone https://github.com/google/cityhash \
    && ./configure --enable-sse4.2 \
    && make all check CXXFLAGS="-g -O3 -msse4.2" \
    && make install

# install cmake
RUN cd / \
    && wget http://www.cmake.org/files/v3.12/cmake-3.12.1.tar.gz \
    && tar -xvzf cmake-3.12.1.tar.gz \
    && cd cmake-3.12.1/ \
    && ./configure \
    && make \
    && make install \
    && rm -rf cmake-3.12.1.tar.gz

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
ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/:/grpc/cmake/build/:/root/pandora/third_party/lib/:src/third_party/lib/