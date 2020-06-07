import requests
import numpy as np
import json
import timeit

model_name = 'Toy'
port = 8501
host = '0.0.0.0'

url = f'http://{host}:{port}/v1/models/{model_name}:predict'

def requset_with_rows():
    req_data = {}
    instances = []
    instances.append([1., 2.])
    instances.append([1., 3.])
    req_data["instances"] = instances
    req_data = json.dumps(req_data)
    return req_data

def requset_with_columns():
    req_data = {}
    inputs = [[1., 1,], [2., 3.]]
    req_data["inputs"] = inputs
    req_data = json.dumps(req_data)
    return req_data

if __name__ == "__main__":
    # batch is
    # request by instances
    print("this request is based on isntances")
    s = timeit.default_timer()
    req_data = requset_with_rows()
    get = requests.post(url, data=req_data)
    inter = timeit.default_timer() - s
    print(get.ok)
    print(get.content.decode('utf-8'))
    print(f'time consumption: {inter * 1000}ms')
    
    # request by inputs
    print("this request is based on inputs")
    s = timeit.default_timer()
    req_data = requset_with_columns()
    get = requests.post(url, data=req_data)
    inter = timeit.default_timer() - s
    print(get.ok)
    print(get.content.decode('utf-8'))
    print(f'time consumption: {inter * 1000}ms')