#!/bin/bash

source env.sh
set -ex
# complete -f -X '!*.go' run.sh
go run $1 --server_addr 127.0.0.1:8500 --model_name Toy --model_version 1
go run $1 --server_addr 127.0.0.1:8500 --model_name Toy --model_version 2
go run $1 --server_addr 127.0.0.1:8500 --model_name Toy --model_version_label stable