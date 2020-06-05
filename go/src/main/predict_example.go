package main

import (
	"flag"
	"fmt"

	// framework "github.com/tensorflow/tensorflow/tensorflow/go/core/framework"
	// pb "github.com/alwaysproblem/tensorflow_serving"
	// "go.uber.org/ratelimit"
	// "golang.org/x/net/context"
	// "google.golang.org/grpc"
	// "google.golang.org/grpc/credentials"
	// "google.golang.org/grpc/grpclog"
	api "client/tfserving_apis"
)

var (
	serverAddr         = flag.String("server_addr", "127.0.0.1:9000", "The server address in the format of host:port")
	modelName          = flag.String("model_name", "mnist", "TensorFlow model name")
	modelVersion       = flag.Int64("model_version", 1, "TensorFlow model version")
)

func main() {
	flag.Parse()

	var timeoutReq float32 = 30.0

	stub, _ := api.NewPredictionServiceStub(*serverAddr)
	stub.Dial()

	defer stub.Close()

	request := api.NewPredictRequest()
	request.ModelSpec.Name = *modelName

	// data should be the flatten values of tensor (1D Array)
	data := []float32{ 
		1., 2.,
		1., 3.,
	}
	dataShape := []int64{
		2, 2,
	}

	// _, _ = api.MakeTensorProto(data, "DT_FLOAT", dataShape)
	dataProto, _ := api.MakeTensorProto(data, "DT_FLOAT", dataShape)
	request.Inputs["input_1"] = dataProto

	resp, _ := stub.Predict(request, timeoutReq)
	fmt.Println(resp)
}
