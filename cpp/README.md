# GO API

## Build your own C++ TFclient (optional)


- [grpc](https://github.com/grpc/grpc/tree/master/src/cpp)
- [protobuf](https://github.com/protocolbuffers/protobuf/tree/master/src)

find ip with `docker network inspect bridge` and go

[
    {
        "Name": "bridge",
        "Id": "4efd677e4825cae70148a9d3a381bd1fd3ee59e914b5b8f831689f750af8c968",
        "Created": "2020-07-20T08:38:40.249456693Z",
        "Scope": "local",
        "Driver": "bridge",
        "EnableIPv6": false,
        "IPAM": {
            "Driver": "default",
            "Options": null,
            "Config": [
                {
                    "Subnet": "172.17.0.0/16",
                    "Gateway": "172.17.0.1"
                }
            ]
        },
        "Internal": false,
        "Attachable": false,
        "Ingress": false,
        "ConfigFrom": {
            "Network": ""
        },
        "ConfigOnly": false,
        "Containers": {
            "00b4513a55ee9a0de473880cb6b0fac8af97bf65afdc232983b6eedb9e0b4e54": {
                "Name": "gracious_taussig",
                "EndpointID": "00fcc462c299d7f51dd6bc8c890db07b8bb3bb0dda2f4ddd366721c9f5330bc7",
                "MacAddress": "02:42:ac:11:00:02",
                "IPv4Address": "172.17.0.2/16",
                "IPv6Address": ""
            },
            "82811806166f9250d0b1734479db6c368a8b90193811231e5125fdab1dfee6a0": {
                "Name": "focused_borg",
                "EndpointID": "1af2f89e7617a837f28fe573aeaf5b57d650216167180b00c70a4be11cfb1510",
                "MacAddress": "02:42:ac:11:00:03",
                "IPv4Address": "172.17.0.3/16",
                "IPv6Address": ""
            }
        },
        "Options": {
            "com.docker.network.bridge.default_bridge": "true",
            "com.docker.network.bridge.enable_icc": "true",
            "com.docker.network.bridge.enable_ip_masquerade": "true",
            "com.docker.network.bridge.host_binding_ipv4": "0.0.0.0",
            "com.docker.network.bridge.name": "docker0",
            "com.docker.network.driver.mtu": "1500"
        },
        "Labels": {}
    }
]