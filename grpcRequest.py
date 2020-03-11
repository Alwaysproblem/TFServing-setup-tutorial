import numpy as np

import tensorflow as tf
from tensorflow_serving.apis import predict_pb2, prediction_service_pb2_grpc
# from grpc.beta import implementations
import grpc


host = '0.0.0.0'
port = 8500
server = host+":"+str(port)
timeout_req = 30.0

req_data = np.array([[1., 2.], [1., 3.]])

if __name__ == "__main__":
    import timeit
    repeat = 10000
    # channel = implementations.insecure_channel(host, int(port))
    channel = grpc.insecure_channel(server) 
    # stub = prediction_service_pb2_grpc.beta_create_PredictionService_stub(channel)
    stub = prediction_service_pb2_grpc.PredictionServiceStub(channel)

    sT = 0
    for _ in range(1000):
        s = timeit.default_timer()
        request = predict_pb2.PredictRequest()
        request.model_spec.name = 'Toy_double_xla'
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
        e = timeit.default_timer()
        # print(resp)
        # print(f"the duration is {(e-s) * 1000}ms")
        sT += (e-s)
    
    print(f"the average time for request of {request.model_spec.name} is {sT}ms")

