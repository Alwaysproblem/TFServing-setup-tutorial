import numpy as np

import tensorflow as tf
from tensorflow_serving.apis import predict_pb2, prediction_service_pb2_grpc
# from grpc.beta import implementations
import grpc

# grpc api https://github.com/tensorflow/serving/tree/master/tensorflow_serving/apis

# labels can only be assigned to model versions that are loaded and available for serving.
# https://stackoverflow.com/questions/53834218/assigning-version-labels-in-model-config-file-fails

# More recently, it is possible to assign labels to models that are not yet loaded provided the 
# --allow_version_labels_for_unavailable_models=true flag is specified (in the same place you specify your 
# --model_config_file=... variable. (In my case, I do this in a docker-compose.yaml file.)

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

    request = predict_pb2.PredictRequest()
    request.model_spec.name = 'Toy'

    if args.version > -1 :
        request.model_spec.version.value = args.version
    
    if args.labels != None:
        request.model_spec.version_label = args.labels

    request.model_spec.signature_name = 'serving_default'

    # predict_log=prediction_log_pb2.PredictLog(request=predict_request))
    #         for r in range(NUM_RECORDS):
    #             writer.write(log.SerializeToString())

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

    resp = stub.Predict(request, timeout_req)

    print(resp)

    # # for output filter out (you can also check the grpc api `predict.proto` ) 
    # print(resp.outputs["output_1"].float_val)

