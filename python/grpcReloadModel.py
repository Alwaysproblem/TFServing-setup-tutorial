import numpy as np

import tensorflow as tf
from tensorflow_serving.apis import predict_pb2, prediction_service_pb2_grpc
from tensorflow_serving.apis import model_service_pb2_grpc
from tensorflow_serving.apis import model_management_pb2
from tensorflow_serving.config import model_server_config_pb2
import grpc

host = '0.0.0.0'
port = 8500
server = host+":"+str(port)
timeout_req = 30.0

req_data = np.array([[1., 2.], [1., 3.]])

if __name__ == "__main__":
    import argparse

    parse = argparse.ArgumentParser(prog="the tensorflow client for python.")
    parse.add_argument('-m', '--model', type=str, action="store", dest="model", default="Toy")

    args = parse.parse_args()

    channel = grpc.insecure_channel(server) 

    # this HandleReloadConfigRequest is for the reload API of the model specified 
    modelstub = model_service_pb2_grpc.ModelServiceStub(channel)
    model_man_request = model_management_pb2.ReloadConfigRequest() 
    model_server_config = model_server_config_pb2.ModelServerConfig()

    # Create a config to add to the list of served models
    config_list = model_server_config_pb2.ModelConfigList()
    one_config = config_list.config.add()

    ## you can modify with your own model configuration.
    # TODO: get the config and check if model name is right.
    one_config.name = args.model
    one_config.base_path = f"/models/save/{args.model}/"
    one_config.model_platform = "tensorflow"

    model_server_config.model_config_list.CopyFrom(config_list)
    model_man_request.config.CopyFrom(model_server_config)

    # print(model_man_request.IsInitialized())
    # print(model_man_request.ListFields())
    model_reload = modelstub.HandleReloadConfigRequest(model_man_request, timeout_req)

    if model_reload.status.error_code == 0:
        print(f"model {one_config.name} reloaded sucessfully")
    else:
        print(f"model {one_config.name} reloaded failed!")
        print(model_reload.status.error_code)
        print(model_reload.status.error_message)

    # add new models to serve
    # prediction_service_pb2_grpc.add_PredictionServiceServicer_to_server(
    #     PredictionServiceServicer(models=models), server)
    # model_service_pb2_grpc.add_ModelServiceServicer_to_server(
    #     ModelServiceServicer(models=models), server)
