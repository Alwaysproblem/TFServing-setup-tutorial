import requests
import numpy as np
import json
import timeit

model_name = 'FC'
port = 8501
host = '0.0.0.0'

url = f'http://{host}:{port}/v1/models/{model_name}:predict'

def requset_with_rows():
    req_data = {}
    instances = []
    instances.append({
      "aid": ["dgadfadsfag"],
      "click_adid": ["sdfgad", "adgas", "adgasdfd", "asdgadsg", "asdgadsfa", "Asdgasd", "Asdga", ""],
      "age": [63],
      "cp": [1],
      "chol": [233],
      "oldpeak": [2.3],
    })
    instances.append({
      "aid": ["sdfgad"],
      "click_adid": ["sdfgad", "adgas", "adgasdfd", "", "", "", "", ""],
      "age": [67],
      "cp": [4],
      "chol": [286],
      "oldpeak": [1.5],
    })
    req_data["instances"] = instances
    req_data = json.dumps(req_data)
    print(req_data)
    return req_data

def requset_with_columns():
    req_data = {}
    inputs = {
        "aid":[["dgadfadsfag"], ["sdfgad"]],
        "click_adid":
        [
            ["sdfgad", "adgas", "adgasdfd", "asdgadsg",
                "asdgadsfa", "Asdgasd", "Asdga", ""],
            ["sdfgad", "adgas", "adgasdfd", "", "", "", "", ""]
        ],
        "age":[[63], [67]],
        "cp":[[1], [4]],
        "chol":[[233], [286]],
        "oldpeak": [[2.3], [1.5]],
    }
    req_data["inputs"] = inputs
    req_data = json.dumps(req_data)
    return req_data

if __name__ == "__main__":
    # batch is 2
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