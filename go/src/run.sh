#!/bin/bash

source env.sh
# go run main/main.go --server_addr 127.0.0.1:8500 --model_name Toy --model_version 2
go run main/predict_example.go --server_addr 127.0.0.1:8500 --model_name Toy --model_version 2