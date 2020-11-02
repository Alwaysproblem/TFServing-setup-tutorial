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
	var timeoutReq float32 = 30.0

	// grpc init
	var opts []grpc.DialOption
	opts = append(opts, grpc.WithInsecure())
	conn, err := grpc.Dial(*serverAddr, opts...)
	if err != nil {
		grpclog.Fatalf("fail to dial: %v", err)
	}
	defer conn.Close()

	// setup a Prediction service
	client := pb.NewPredictionServiceClient(conn)
	ctx, canc := context.WithTimeout(context.Background(), time.Duration(int64(timeoutReq))*time.Second)
	defer canc()

	// setup model metadata struct
	// Metadata fields to get. Currently supported: "signature_def".
	metadata := utils.NewGetModelMetadataRequest([]string{"signature_def",})
	metadata.ModelSpec.Name = *modelName
	if *modelVersion > -1 {
		metadata.ModelSpec.VersionChoice = utils.ModelVersion(*modelVersion)
	}
	if *modelVersionLabel != "" {
		metadata.ModelSpec.VersionChoice = utils.ModelVersionLabel(*modelVersionLabel)
	}
	// get model metadata
	meta, _ := client.GetModelMetadata(ctx, metadata)
	fmt.Println(meta)
}
