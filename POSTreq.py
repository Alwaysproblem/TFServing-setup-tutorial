import requests
import numpy as np
import json
import timeit

model_name = 'Toy'
port = 8501
host = '0.0.0.0'

url = f'http://{host}:{port}/v1/models/{model_name}:predict'

req_data = {}

req_data["instances"] = [{"userid":[["0"]], "adid":[["CoCo"]]}]
# , {"userid":"1", "adid":"Peter_Rabbit"}]
req_data = json.dumps(req_data)

s = timeit.default_timer()
get = requests.post(url, data=req_data)
inter = timeit.default_timer() - s
# print(get.ok)
print(get.content.decode('utf-8'))
print(inter)