package main

import (
	"context"
	"flag"
	"fmt"
	"github.com/golang/glog"
	"google.golang.org/grpc"

	pb "github.com/bigchange/go-pro/proto"
)

func tensorflow_client_compute() {
	var port = flag.Int("port", 36255, "GRPC server port, must be in [1024, 65535).")
	var x = flag.Float64("x", 0.0, "First summand.")
	var y = flag.Float64("y", 0.0, "Second summand.")
	flag.Parse()
	if *port <= 1023 || *port > 65535 {
		glog.Fatalf("Invalid --port=%d", *port)
	}
	host := fmt.Sprintf("localhost:%d", *port)
	conn, err := grpc.Dial(host, grpc.WithInsecure())
	if err != nil {
		glog.Fatalf("failed to dial: %v", err)
	}
	defer conn.Close()

	client := pb.NewSumServiceClient(conn)

	resp, err := client.Sum(context.Background(), &pb.Request{
		X: float32(*x),
		Y: float32(*y),
	})
	if err != nil {
		glog.Fatalf("gRPC failed! %v", err)
	}
	fmt.Println(*x, "+", *y, "=", resp.Sum)
}

func main() {
	// tfmodel.TfModelLoadAndEval_imdb_model()
	// tfmodel.TfModelLoadAndEval()
	// tfmodel.TfModelLoadAndEval_work_tagger()
	// tfmodel.TfServing_imdb_model()
	// tfmodel.TfServing_work_tagger()
	// tfmodel.TfServing_bert_model()
	tensorflow_client_compute()

}
