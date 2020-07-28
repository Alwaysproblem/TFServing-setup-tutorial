#!/usr/bin/
export GOPATH=$(dirname `pwd`)
# export GOROOT=$(pwd)/src
export GOBIN=$GOPATH/bin
# turn on the GOmodule for searching the pkg in current path.
export GO111MODULE=on
export PATH=$PATH:$GOPATH/bin