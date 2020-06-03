// usage: go run predict_client.go --server_addr 127.0.0.1:9000 --model_name dense --model_version 1
package main

import (
	"flag"
	"fmt"
	"time"

	framework "github.com/tensorflow/tensorflow/tensorflow/go/core/framework"
	pb "github.com/alwaysproblem/tensorflow_serving"
	// "go.uber.org/ratelimit"
	"golang.org/x/net/context"
	"google.golang.org/grpc"
	// "google.golang.org/grpc/credentials"
	"google.golang.org/grpc/grpclog"
	"client/utils"
)

var (
	serverAddr         = flag.String("server_addr", "127.0.0.1:9000", "The server address in the format of host:port")
	modelName          = flag.String("model_name", "mnist", "TensorFlow model name")
	modelVersion       = flag.Int64("model_version", 1, "TensorFlow model version")
)

func main() {
	flag.Parse()
	var opts []grpc.DialOption
	opts = append(opts, grpc.WithInsecure())
	conn, err := grpc.Dial(*serverAddr, opts...)
	if err != nil {
		grpclog.Fatalf("fail to dial: %v", err)
	}
	defer conn.Close()
	client := pb.NewPredictionServiceClient(conn)
	sendReq(client, 50)
}

func sendReq(client pb.PredictionServiceClient, batchSize int) error {
	// pr := newMnistRequest(modelName, modelVersion, batchSize)
	var _ int = batchSize
	var Sig string = "serving_default"
	pr := newPredictRequest(modelName, modelVersion, &Sig)

	utils.AddInput(pr, "input_1", framework.DataType_DT_FLOAT, []float32{
		1., 2.,
		1., 3.,
	}, []int64{2, 2}, nil)

	ctx, canc := context.WithTimeout(context.Background(), 20*time.Second)
	// ctx, canc := context.WithTimeout(context.Background(), 20*time.Millisecond)
	defer canc()
	start := time.Now()
	resp, err := client.Predict(ctx, pr)

	dur := time.Since(start)
	if err != nil {
		fmt.Println(err)
		return err
	}

	fmt.Println("OK")
	fmt.Println("time per request: ", dur)
	for k, v := range resp.Outputs {
	
		fmt.Printf("tensor: %s, version: %d\n", k, v.VersionNumber)
		if v.Dtype != framework.DataType_DT_FLOAT {
			fmt.Errorf("wrong type: %s", v.Dtype)
		}

		// fmt.Println(v.TensorShape.Dim[0].Size)
		var k int64 = 0
		for ; k < v.TensorShape.Dim[0].Size; k++ {
			fmt.Println(v.FloatVal[k])
		}
	}
	return nil
}

func newPredictRequest(modelName *string, modelVersion *int64, SignatureName *string) *pb.PredictRequest {
	pr := utils.NewPredictRequest(*modelName, *modelVersion)
	pr.ModelSpec.SignatureName = *SignatureName
	return pr
}
