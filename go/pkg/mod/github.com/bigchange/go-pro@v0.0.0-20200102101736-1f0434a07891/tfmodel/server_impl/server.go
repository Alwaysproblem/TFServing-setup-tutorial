// Package main implements a tfdemo grpc server.
package main

import (
	"flag"
	"fmt"
	pb "github.com/bigchange/go-pro/proto"
	"github.com/golang/glog"
	"google.golang.org/grpc"
	"io/ioutil"
	"net"
	"os"
	"os/signal"
	"syscall"
)

var (
	modelPB = flag.String("model_pb", "/Users/chaojiangyou/lls/src/github.com/bigchange/go-pro/model/model.pb", "Binary proto file containing the tensorflow model.")
	port    = flag.Int("port", 36255, "Serving port.")
)

func main() {
	flag.Parse()
	lis, err := net.Listen("tcp", fmt.Sprintf(":%d", *port))
	if err != nil {
		glog.Fatalf("Failed to listen to %d, err: %v", *port, err)
	}
	def, err := ioutil.ReadFile(*modelPB)
	if err != nil {
		glog.Fatalf("Failed to read tensorflow model pb %s, err: %v", *modelPB, err)
	}
	s := grpc.NewServer()
	pb.RegisterSumServiceServer(s, NewServlet(def))
	go func() {
		glog.Infof("Start serving on port %d.", *port)
		s.Serve(lis)
	}()
	c := make(chan os.Signal)
	signal.Notify(c, os.Interrupt, syscall.SIGTERM)
	<-c
	glog.Info("Intercepted SIGTERM, start shutting down...")
	s.GracefulStop()
	glog.Info("GRPC server shut down.")
}
