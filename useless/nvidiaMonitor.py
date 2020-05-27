import os
import sys
import time

try:
    while True:
        if sys.platform in {'darwin', 'linux', 'linux2'}:
            print("printf '\033c'")
        else:
            os.system("cls")
        
        os.system("nvidia-smi")
        time.sleep(1)
except:
    sys.exit()
