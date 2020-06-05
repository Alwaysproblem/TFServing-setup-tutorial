package tfserving_apis

import (
	"context"
	"errors"
	// "reflect"
	"time"

	framework "github.com/tensorflow/tensorflow/tensorflow/go/core/framework"
	pb "github.com/alwaysproblem/tensorflow_serving"
	"google.golang.org/grpc"
	// google_protobuf "github.com/golang/protobuf/ptypes/wrappers"
)

type PredictionServiceClient struct {
	Conn    *grpc.ClientConn
	Address string
	Stub    pb.PredictionServiceClient
}

// NewClient
func NewPredictionServiceStub(address string) (client *PredictionServiceClient, err error) {
	// fmt.Println("grpcVersion:", grpc.Version)
	client = &PredictionServiceClient{Conn: nil, Address: address, Stub: nil}
	return client, nil
}

func (client *PredictionServiceClient) Dial() (err error) {
	client.Conn, err = grpc.Dial(client.Address, grpc.WithInsecure())
	if err != nil {
		return err
	}
	client.Stub = pb.NewPredictionServiceClient(client.Conn)
	// ctx, _ := context.WithTimeout(context.Background(), time.Duration(5*time.Second))
	return nil
}

func (client *PredictionServiceClient) Close() {
	client.Conn.Close()
}


func (client *PredictionServiceClient) Predict(request *pb.PredictRequest, timeout float32) (resp *pb.PredictResponse, err error) {
	if timeout >= 1.0 {
		ctx, canc := context.WithTimeout(context.Background(), time.Duration(int64(timeout))*time.Second)
		defer canc()
		resp, err := client.Stub.Predict(ctx, request)
		return resp, err
	}else if timeout * 1000.0 >= 1.0{
		ctx, canc := context.WithTimeout(context.Background(), time.Duration(int64(timeout * 1000.0))*time.Millisecond)
		defer canc()
		resp, err := client.Stub.Predict(ctx, request)
		return resp, err
	}else{
		return nil, errors.New("the timeout should be in [1 ms, +inf s)")
	}
}


// NewPredictRequest declare a new request proto
func NewPredictRequest() (pr *pb.PredictRequest) {
	return &pb.PredictRequest{
		ModelSpec: &pb.ModelSpec{
			Name:          "",
			SignatureName: "serving_default",
			// `VersionChoice` need to be specified by function ModelVersion,
			// ModelVersionLabel in the util.go if needed.
			// Recommended to be left unset in the common case.
		},
		Inputs: make(map[string]*framework.TensorProto),
	}
}

