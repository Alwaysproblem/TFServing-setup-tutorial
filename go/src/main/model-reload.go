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
	configList := utils.ModelServerConfigModelConfigList()
	config := utils.NewModelConfig()
	config.Name = *modelName
	config.BasePath = fmt.Sprintf("/models/save/%s/", *modelName)
	config.ModelPlatform = "tensorflow"

	configList.ModelConfigList.Config = append(
					configList.ModelConfigList.Config, config)

	rcr := utils.NewReloadConfigRequest()
	rcr.Config.Config = configList

	resp, _ := client.HandleReloadConfigRequest(ctx, rcr)

	if resp.Status.ErrorCode == 0 {
		fmt.Printf("model %s reloaded sucessfully\n", *modelName)
	}else{
		fmt.Printf("model %s reloaded failed!\n", *modelName)
        fmt.Println(resp.Status.ErrorCode)
        fmt.Println(resp.Status.ErrorMessage)
	}
}