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
	modelName          = flag.String("model_name", "FC", "TensorFlow model name")
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

	inputs := map[string](interface{}){
		"aid": []string{"dgadfadsfag", "sdfgad"},
		"click_adid": []string{
			"sdfgad", "adgas", "adgasdfd", "asdgadsg",
				"asdgadsfa", "Asdgasd", "Asdga", "",
			"sdfgad", "adgas", "adgasdfd", "", "", "", "", "",
		},
		"age": []int64{63, 67},
		"cp": []int64{1, 4},
		"chol": []int64{233, 286},
		"oldpeak": []float32{2.3, 1.5},
	}
	

	inputShape := map[string]([]int64){
		"aid": []int64{2, 1},
		"click_adid": []int64{2, 8},
		"age": []int64{2, 1},
		"cp": []int64{2, 1},
		"chol": []int64{2, 1},
		"oldpeak": []int64{2, 1},
	}
	
	inputsType := map[string]string{
			"aid": "DT_STRING",
			"click_adid": "DT_STRING",
			"age":"DT_INT64",
			"cp":"DT_INT64",
			"chol":"DT_INT64",
			"oldpeak": "DT_FLOAT",
		}


	// convert data to tensorProto
	for k, v := range inputs {
		// fmt.Println(v)
		dataProto, errs := utils.MakeTensorProto(v, inputsType[k], inputShape[k])
		if errs != nil{
			panic(errs)
		}else{
			// fmt.Println(dataProto.TensorShape)
			request.Inputs[k] = dataProto
		}
	}
	// request.OutputFilter = []string{"output_1"} 
	// request.OutputFilter = []string{"output_2"}  // nothing will come out.

	// get prediction
	resp, _ := client.Predict(ctx, request)

	// _ = client
	// _ = ctx

	fmt.Println(resp)
	// fmt.Println(request)
}
