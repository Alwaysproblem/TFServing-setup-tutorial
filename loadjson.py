import requests
import json

import timeit
import time
import math

import sys

with open('request/a_100.json') as ff:
    post_100 = json.load(ff)

with open('request/a_200.json') as ff:
    post_200 = json.load(ff)

data_100 = {}
data_200 = {}
data_100["instances"] = post_100
data_200["instances"] = post_200

data_100 = json.dumps(data_100)
data_200 = json.dumps(data_200)

# print(data)

url = 'http://localhost:8501/v1/models/CTR:predict'

repeatTimes = 1000


mint = 0

for _ in range(repeatTimes//100):
    mint_inner = math.inf
    for _ in range(repeatTimes // 10):
        start_time = timeit.default_timer()
        get = requests.post(url, data=data_100)
        if get.ok is False:
            sys.exit()
        elapsed_100 = timeit.default_timer() - start_time
        print(f"the team 100 is {'OK' if get.ok is True else 'ERROR'}.")
        print(f"the team 100 takes {elapsed_100 * 1000} ms")

        time.sleep(0.1)

        start_time = timeit.default_timer()
        get = requests.post(url, data=data_200)
        if get.ok is False:
            sys.exit()
        elapsed_200 = timeit.default_timer() - start_time
        print(f"the team 200 is {'OK' if get.ok is True else 'ERROR'}.")
        print(f"the team 200 takes {elapsed_200 * 1000} ms.")

        time.sleep(0.1)

        print(f"To sum up, the delta 100 takes {abs(elapsed_200 - elapsed_100) * 1000} ms.")
        mint_inner = min(mint_inner, abs(elapsed_200 - elapsed_100) * 1000)
    
    mint += mint_inner

mint //= 10

aver_100 = 0
for _ in range(repeatTimes):
    start_time = timeit.default_timer()
    get = requests.post(url, data=data_100)
    elapsed_100 = timeit.default_timer() - start_time
    if get.ok is False:
        sys.exit()
    print(f"the team 100 is {'OK' if get.ok is True else 'ERROR'}.")
    print(f"the team 100 takes {elapsed_100 * 1000} ms")
    aver_100 += elapsed_100 * 1000

aver_100 //= repeatTimes

time.sleep(0.5)

aver_200 = 0
for _ in range(repeatTimes):
    start_time = timeit.default_timer()
    get = requests.post(url, data=data_200)
    elapsed_200 = timeit.default_timer() - start_time
    if get.ok is False:
        sys.exit()
    print(f"the team 200 is {'OK' if get.ok is True else 'ERROR'}.")
    print(f"the team 200 takes {elapsed_200 * 1000} ms")
    aver_200 += elapsed_200 * 1000

aver_200 //= repeatTimes

print(f"minimal time cost is {mint}ms.")
print(f"average time cost is {abs(aver_200 - aver_100)}ms.")
