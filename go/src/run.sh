#!/bin/bash

# run this under src directory
source env.sh
go run $1 --server_addr 127.0.0.1:8500 --model_name Toy --model_version 1