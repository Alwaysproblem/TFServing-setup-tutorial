# GO API

## Start Server docker

- [start tfserver](../README.md)
- netowork setting
  - this we need to docker image as develop image, so plase find the server ip with `docker network inspect bridge`

    ```bash
    $ docker ps # using this to find the server name under NAMES feild.
    $ docker network inspect bridge
    [
        {
          ...
                "82811806166f9250d0b1734479db6c368a8b90193811231e5125fdab1dfee6a0": {
                    "Name": "focused_borg",   # this is the name of server (need to check)
                    "EndpointID": "1af2f89e7617a837f28fe573aeaf5b57d650216167180b00c70a4be11cfb1510",
                    "MacAddress": "02:42:ac:11:00:03",
                    "IPv4Address": "172.17.0.3/16", # if name is right then this is your server IP
                    "IPv6Address": ""
          ...
        }
    ]
    ```

- enter cpp directory

  ```bash
  $ cd cpp/
  ```

## Build your own C++ TFclient (optional)

- environment preparation (detail on the [doeckerfile](./grpc-cpp.dockerfile))

  - [grpc](https://github.com/grpc/grpc/tree/master/src/cpp)
  - [protobuf](https://github.com/protocolbuffers/protobuf/tree/master/src)

- build docker

  ```bash
  $ docker build -t grpc-cpp -f grpc-cpp.dockerfile .
  ```

- start and enter `grpc-cpp` shell

  ```bash
  $ docker run --rm -ti -v `pwd`:/cpp  grpc-cpp
  root@5b9f27acaefe:/# git clone https://github.com/tensorflow/tensorflow
  root@5b9f27acaefe:/# git clone https://github.com/tensorflow/serving
  root@5b9f27acaefe:/# cd /cpp
  root@5b9f27acaefe:/cpp# mkdir gen
  root@5b9f27acaefe:/cpp# bash build-cpp-api.sh
  root@5b9f27acaefe:/cpp# mv gen ./src
  root@5b9f27acaefe:/cpp# make
  ```

## API