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
	utils "client/utils"
)

var (
	serverAddr         = flag.String("server_addr", "127.0.0.1:8500", "The server address in the format of host:port")
	modelName          = flag.String("model_name", "Toy", "TensorFlow model name")
	modelVersion       = flag.Int64("model_version", -1, "TensorFlow model version")
	modelVersionLabel  = flag.String("model_version_label", "", "TensorFlow model version label")
)

func main() {
	flag.Parse()

	var timeoutReq float32 = 30.0
	var opts []grpc.DialOption
	opts = append(opts, grpc.WithInsecure())
	conn, err := grpc.Dial(*serverAddr, opts...)
	if err != nil {
		grpclog.Fatalf("fail to dial: %v", err)
	}
	defer conn.Close()

	request := utils.NewPredictRequest()
	request.ModelSpec.Name = *modelName
	request.ModelSpec.SignatureName = "serving_default"
	if *modelVersion > -1 {
		request.ModelSpec.VersionChoice = utils.ModelVersion(*modelVersion)
	}
	if *modelVersionLabel != "" {
		request.ModelSpec.VersionChoice = utils.ModelVersionLabel(*modelVersionLabel)
	}

	// data should be the flatten values of tensor (1D Array)
	data := []float32{ 
		1., 2.,
		1., 3.,
		1., 4.,
	}
	dataShape := []int64{
		3, 2,
	}

	// _, _ = api.MakeTensorProto(data, "DT_FLOAT", dataShape)
	dataProto, _ := utils.MakeTensorProto(data, "DT_FLOAT", dataShape)
	request.Inputs["input_1"] = dataProto

	client := pb.NewPredictionServiceClient(conn)
	ctx, canc := context.WithTimeout(context.Background(), time.Duration(int64(timeoutReq))*time.Second)
	defer canc()

	// predict_log = prediction_log_pb2.PredictionLog(
	// 	predict_log=prediction_log_pb2.PredictLog(request=request))
		
		
	resp, _ := client.Predict(ctx, request)
	fmt.Println(resp)
		
	predicLog := utils.NewPredictionLog(request, resp)
	predicLog.LogMetadata.ModelSpec = request.ModelSpec

	fmt.Println(predicLog)
}
