import numpy as np

import tensorflow as tf
from tensorflow_serving.apis import predict_pb2, prediction_service_pb2_grpc, prediction_log_pb2
# from grpc.beta import implementations
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
    parse.add_argument('-l', '--version-labels', type=str, action="store", dest="labels", default=None)

    args = parse.parse_args()

    repeat = 10000
    # channel = implementations.insecure_channel(host, int(port))
    channel = grpc.insecure_channel(server) 
    # stub = prediction_service_pb2_grpc.beta_create_PredictionService_stub(channel)
    stub = prediction_service_pb2_grpc.PredictionServiceStub(channel)

    request = predict_pb2.PredictRequest()
    request.model_spec.name = args.model

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

    # predict_log=prediction_log_pb2.PredictLog(request=request)
    predict_log = prediction_log_pb2.PredictionLog(
            predict_log=prediction_log_pb2.PredictLog(request=request))

    print("request logs".center(100, "*"))

    print(predict_log)
    # print(predict_log.SerializeToString()) # serialize the log to TFRecord logs file

    # fetch the tensor content from predict logs
    # print(predict_log.predict_log.request.inputs["input_1"].tensor_content)
    print("end".center(100, "*"), end='\n\n')

    resp = stub.Predict(request, timeout_req)

    print("outputs".center(100, "*"))
    print(resp)
    print("end".center(100, "*"))
    print(predict_log)
    # # for output filter out (you can also check the grpc api `predict.proto` ) 
    # print(resp.outputs["output_1"].float_val)

