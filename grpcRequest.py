import numpy as np

import tensorflow as tf
from tensorflow_serving.apis import predict_pb2, prediction_service_pb2_grpc
# from grpc.beta import implementations
import grpc


host = '0.0.0.0'
port = 8500
server = host+":"+str(port)
timeout_req = 30.0

# req_data = np.array([[1., 2.], [1., 3.]])
# req_data = '{"userid":[["0"]], "adid":[["CoCo"]]}'
userids = [["0"]]
adids = [["CoCo"]]


if __name__ == "__main__":

    repeat = 10000
    # channel = implementations.insecure_channel(host, int(port))
    channel = grpc.insecure_channel(server) 
    # stub = prediction_service_pb2_grpc.beta_create_PredictionService_stub(channel)
    stub = prediction_service_pb2_grpc.PredictionServiceStub(channel)

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

    user_proto = tf.make_tensor_proto(userids, dtype=tf.dtypes.string)
    ad_proto = tf.make_tensor_proto(adids, dtype=tf.dtypes.string)

    request.inputs["userid"].CopyFrom(user_proto)
    request.inputs["adid"].CopyFrom(ad_proto)

    resp = stub.Predict(request, timeout_req)

    print(resp)

