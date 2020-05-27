import json

import tensorflow as tf
from tensorflow_serving.apis import predict_pb2, prediction_service_pb2_grpc
# from grpc.beta import implementations
import grpc

host = '0.0.0.0'
port = 8500
server = host+":"+str(port)

with open('request/a_100_toy.json') as ff:
    post_100 = json.load(ff)

sparse_features = ["m1", "adid", "adspaceid", "adtype", "nt",
                    "osv", "p_city", "appid"]
varlen_features = ["click_adids", "install_pkgs"]

if __name__ == "__main__":

    channel = grpc.insecure_channel(server) 
    stub = prediction_service_pb2_grpc.PredictionServiceStub(channel)

    request = predict_pb2.PredictRequest()
    request.model_spec.name = 'CTR'
    request.model_spec.signature_name = 'serving_default'

    for f in sparse_features+varlen_features:
        data_proto = tf.make_tensor_proto(post_100[f], dtype=tf.int64)
        request.inputs[f].CopyFrom(data_proto)

    resp = stub.Predict(request, 30.0)

    print(resp)

