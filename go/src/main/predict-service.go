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

	// setup a predict requst struct
	request := utils.NewPredictRequest()
	request.ModelSpec.Name = *modelName
	if *modelVersion > -1 {
		request.ModelSpec.VersionChoice = utils.ModelVersion(*modelVersion)
	}
	if *modelVersionLabel != "" {
		request.ModelSpec.VersionChoice = utils.ModelVersionLabel(*modelVersionLabel)
	}
	request.ModelSpec.SignatureName = "serving_default"
	// data should be the flatten values of tensor (1D Array)
	data := []float32{ 
		1., 2.,
		1., 3.,
		1., 4.,
	}
	dataShape := []int64{
		3, 2,
	}
	// convert data to tensorProto
	dataProto, _ := utils.MakeTensorProto(data, "DT_FLOAT", dataShape)
	request.Inputs["input_1"] = dataProto
	request.OutputFilter = []string{"output_1"} 
	// request.OutputFilter = []string{"output_2"}  // nothing will come out.

	// get prediction
	resp, _ := client.Predict(ctx, request)

	fmt.Println(resp)
}
