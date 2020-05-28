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
    parse.add_argument('-v', '--version', type=int, action="store", dest="version", default=-1)
    parse.add_argument('-l', '--version-labels', type=str, action="store", dest="labels", default=None)

    args = parse.parse_args()

    repeat = 10000
    # channel = implementations.insecure_channel(host, int(port))
    channel = grpc.insecure_channel(server) 
    # stub = prediction_service_pb2_grpc.beta_create_PredictionService_stub(channel)
    stub = prediction_service_pb2_grpc.PredictionServiceStub(channel)

    # for output tensor
    request = predict_pb2.PredictRequest()
    request.model_spec.name = 'Toy'

    if args.version > -1 :
        request.model_spec.version.value = args.version
    
    if args.labels != None:
        request.model_spec.version_label = args.labels

    request.model_spec.signature_name = 'serving_default'

    # if you have a structure data. example a dictionary,
    # you should exhausted every key to change them to protobuf patten
    # requset.input is the same as the keras model input layer.
    # so if you define a inputlayer 
    # for f in sparse_features+varlen_features:
    #     data_proto = tf.make_tensor_proto(post_100[f], dtype=tf.int64)
    #     request.inputs[f].CopyFrom(data_proto)

    data_proto = tf.make_tensor_proto(req_data, dtype=tf.float32)

    request.inputs["input_1"].CopyFrom(data_proto)

    # only get outputs you want model to response.
    request.output_filter.append("output_1")

    # this HandleReloadConfigRequest is for the reload API of the model specified 
    modelstub = model_service_pb2_grpc.ModelServiceStub(channel)
    model_man_request = model_management_pb2.ReloadConfigRequest() 
    model_server_config = model_server_config_pb2.ModelServerConfig()

    # Create a config to add to the list of served models
    config_list = model_server_config_pb2.ModelConfigList()
    one_config = config_list.config.add()
    one_config.name = "Toy"
    one_config.base_path = "/models/save/Toy/"
    one_config.model_platform = "tensorflow"

    model_server_config.model_config_list.CopyFrom(config_list)
    model_man_request.config.CopyFrom(model_server_config)

    # print(model_man_request.IsInitialized())
    # print(model_man_request.ListFields())
    model_reload = modelstub.HandleReloadConfigRequest(model_man_request, timeout_req)

    # this can get the status for model served.
    model_status = modelstub.GetModelStatus(request, timeout_req)

    # this is for outputs tensor.
    resp = stub.Predict(request, timeout_req)

    print("outputs".center(100, "*"))
    print(resp)
    print("end".center(100, "*"), end='\n\n')

    print("model metadata".center(100, "*"))
    print(model_status)
    print(model_reload)
    if model_reload.status.error_code == 0:
        print("Reload sucessfully")
    else:
        print("Reload failed!")
        print(model_reload.status.error_code)
        print(model_reload.status.error_message)
    print("end".center(100, "*"))

    # # for output filter out (you can also check the grpc api `predict.proto` ) 
    # print(resp.outputs["output_1"].float_val)

