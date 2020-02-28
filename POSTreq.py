import requests
import numpy as np
import json
import timeit

model_name = 'Toy'
port = 9009
host = '0.0.0.0'

url = f'http://{host}:{port}/v1/models/{model_name}:predict'

req_data = {}

req_data["instances"] = [[1., 2.], [1., 3.]]
req_data = json.dumps(req_data)

s = timeit.default_timer()
get = requests.post(url, data=req_data)
inter = timeit.default_timer() - s
# print(get.ok)
print(get.content.decode('utf-8'))
print(inter)