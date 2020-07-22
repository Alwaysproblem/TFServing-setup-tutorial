FROM ubuntu:18.04

RUN apt-get update \
    && apt-get install software-properties-common -y \
    && apt-get install autoconf automake libtool curl make g++ unzip build pkg-config libgflags-dev -y \
    && apt-get install protobuf-compiler-grpc libprotobuf-dev build-essential cmake clang-5.0 libc++-dev -y \
    && apt-get install doxygen -y \
    && apt-get clean

# sudo apt install curl gnupg
# curl https://bazel.build/bazel-release.pub.gpg | sudo apt-key add -
# echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
# sudo apt update && sudo apt install bazel