# Add several Go libraries and additional Go tools
# using `make get `
SHELL=/bin/bash
ROOT=$(shell pwd)
# gorocksdb build settings
export CGO_LDFLAGS=-g -O2 -lrocksdb -lstdc++ -lm -lz -lbz2 -lsnappy -llz4 -lzstd

.PHONY: clean get test vet cover run dist protoc no_std_log bench fmt


clean:
	rm -rf src/vendor
	rm -rf bin
	rm -rf pkg
	rm -rf dist

get: get_clone get_install

get_clone:
	go run tools/dep/*.go --path=${GOPATH}

get_install:
	go install github.com/gogo/protobuf/protoc-gen-gogoslick
	go install github.com/mauricelam/genny
	go install github.com/mattn/goreman
	go install golang.org/x/lint/golint
	go install golang.org/x/tools/cmd/goimports
	go install honnef.co/go/tools/cmd/staticcheck



