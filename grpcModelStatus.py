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
    parse.add_argument('-v', '--version', type=int, action="store", dest="version", default=-1)

    args = parse.parse_args()

    channel = grpc.insecure_channel(server) 

    # for output tensor
    request = predict_pb2.PredictRequest()
    request.model_spec.name = args.model

    if args.version > -1 :
        request.model_spec.version.value = args.version

    request.model_spec.signature_name = 'serving_default'

    # this HandleReloadConfigRequest is for the reload API of the model specified 
    modelstub = model_service_pb2_grpc.ModelServiceStub(channel)

    # this can get the status for model served.
    model_status = modelstub.GetModelStatus(request, timeout_req)
    print(model_status)


    # # for output filter out (you can also check the grpc api `predict.proto` ) 
    # print(resp.outputs["output_1"].float_val)

