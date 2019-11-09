import numpy as np

import tensorflow as tf
from tensorflow_serving.apis import predict_pb2, prediction_service_pb2
from grpc.beta import implementations


host = '0.0.0.0'
port = 9000
timeout_req = 30.0

req_data = np.array([[1., 2.], [1., 3.]])

if __name__ == "__main__":

    repeat = 10000
    channel = implementations.insecure_channel(host, port)
    stub = prediction_service_pb2.beta_create_PredictionService_stub(channel)

    request = predict_pb2.PredictRequest()
    request.model_spec.name = 'Toy'
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

    resp = stub.Predict(request, timeout_req)

    print(resp)

