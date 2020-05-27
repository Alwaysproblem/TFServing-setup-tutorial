import numpy as np
import timeit
import time
import sys
import json

import tensorflow as tf
from tensorflow_serving.apis import predict_pb2, prediction_service_pb2_grpc
# from grpc.beta import implementations
import grpc

import math

host = '0.0.0.0'
port = 8500
server = host+":"+str(port)

with open('request/a_100_toy.json') as ff:
    post_100 = json.load(ff)

# with open('a_gRPC_200.json') as ff:
#     post_200 = json.load(ff)

sparse_features = ["m1", "adid", "adspaceid", "adtype", "nt",
                    "osv", "p_city", "appid"]
varlen_features = ["click_adids", "install_pkgs"]

# data_100 = {}
# data_200 = {}
# data_100["instances"] = post_100
# data_200["instances"] = post_200

# data_100 = json.dumps(data_100)
# data_200 = json.dumps(data_200)

if __name__ == "__main__":

    repeat = 10
    channel = grpc.insecure_channel(server) 
    stub = prediction_service_pb2_grpc.PredictionServiceStub(channel)

    request = predict_pb2.PredictRequest()
    request.model_spec.name = 'CTR_XLA'
    request.model_spec.signature_name = 'serving_default'

    for f in sparse_features+varlen_features:
        data_proto = tf.make_tensor_proto(post_100[f], dtype=tf.int64)
        request.inputs[f].CopyFrom(data_proto)

    # warmup
    print("warmup...")
    for _ in range(max(repeat / 10, 10)):
        resp = stub.Predict(request, 30.0)

    timeSum_xla = 0
    timeSum = 0
    for _ in range(10):
        request.model_spec.name = 'CTR_XLA'
        t100 = 0
        for _ in range(repeat):
            start_100 = timeit.default_timer()
            resp = stub.Predict(request, 30.0)
            interval_100 = timeit.default_timer() - start_100
            # print(f'batch 100, duration: { interval_100 * 1000} ms')
            t100 += interval_100

        timeSum_xla += t100 / repeat
        print(f"the average duration for {request.model_spec.name} : {t100 / repeat * 1000}ms.")

        request.model_spec.name = 'CTR'
        t100 = 0
        for _ in range(repeat):
            start_100 = timeit.default_timer()
            resp = stub.Predict(request, 30.0)
            interval_100 = timeit.default_timer() - start_100
            # print(f'batch 100, duration: { interval_100 * 1000} ms')
            t100 += interval_100
        
        timeSum += t100 / repeat
        print(f"the average duration for {request.model_spec.name} : {t100 / repeat * 1000}ms.")

    print(f"the totoal average duration for XLA is {timeSum_xla / 10 * 1000}ms.")
    print(f"the totoal average duration for normal is {timeSum / 10 * 1000}ms.")

    # for f in sparse_features+varlen_features:
    #     data_proto = tf.make_tensor_proto(post_200[f], dtype=tf.int64)
    #     request.inputs[f].CopyFrom(data_proto)
    
    # t200 = 0
    # for _ in range(repeat):
    #     start_200 = timeit.default_timer()
    #     resp = stub.Predict(request, 30.0)
    #     interval_200 = timeit.default_timer() - start_200
    #     print(f'batch 200 time: { interval_200 * 1000} ms')
    #     t200 += interval_200 * 1000
    # t200 //= repeat

    # print(f'the delta 100 time: { math.fabs(t100 - t200)} ms')
    # print(f'total time: { (interval_200 - interval_100) * 1000} ms')

