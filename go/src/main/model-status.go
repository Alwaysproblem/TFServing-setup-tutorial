package main

import (
	"flag"
	"fmt"
	"time"

	// framework "github.com/tensorflow/tensorflow/tensorflow/go/core/framework"
	pb "github.com/alwaysproblem/tensorflow_serving"
	// "go.uber.org/ratelimit"
	"golang.org/x/net/context"
	"google.golang.org/grpc"
	// "google.golang.org/grpc/credentials"
	"google.golang.org/grpc/grpclog"
	utils "utils"
)

var (
	serverAddr         = flag.String("server_addr", "172.17.0.3:8500", "The server address in the format of host:port")
	modelName          = flag.String("model_name", "Toy", "TensorFlow model name")
	modelVersion       = flag.Int64("model_version", -1, "TensorFlow model version")
	modelVersionLabel  = flag.String("model_version_label", "", "TensorFlow model version label")
)

func main() {
	flag.Parse()

	// var timeoutReq float32 = 30.0
	var opts []grpc.DialOption
	opts = append(opts, grpc.WithInsecure())
	conn, err := grpc.Dial(*serverAddr, opts...)
	if err != nil {
		grpclog.Fatalf("fail to dial: %v", err)
	}
	defer conn.Close()

	client := pb.NewModelServiceClient(conn)
	ctx, canc := context.WithTimeout(context.Background(), time.Duration(int64(20))*time.Second)
	defer canc()

	// setup new config struct
	msr := utils.NewGetModelStatusRequest()
	msr.ModelSpec.Name = *modelName
	if *modelVersion > -1 {
		msr.ModelSpec.VersionChoice = utils.ModelVersion(*modelVersion)
	}
	if *modelVersionLabel != "" {
		msr.ModelSpec.VersionChoice = utils.ModelVersionLabel(*modelVersionLabel)
	}

	resp, _ := client.GetModelStatus(ctx, msr)
	fmt.Println(resp)
}