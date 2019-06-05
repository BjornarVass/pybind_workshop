from sklearn.neighbors import BallTree as bt
import math
from similarity_measure import euc_speed
import numpy as np
import time



def py_euc_speed(first, second):
    x1, y1, speed1 = first
    x2, y2, speed2 = second
    euc_part = math.sqrt(pow(x1-x2, 2) + math.pow(y1-y2, 2))
    speed_part = abs(speed1-speed2)
    return speed_part * 0.5 + euc_part


np.random.seed(42)

data = 30*np.random.rand(1000, 3)

# pybind part
start = time.time()
for i in range(10):
    print(i)
    tree = bt(data, leaf_size=5, metric=euc_speed)
print('Pybind used {} seconds'.format(time.time()-start))

# python part
start = time.time()
for i in range(10):
    print(i)
    tree = bt(data, leaf_size=5, metric=py_euc_speed)
print('Python used {} seconds'.format(time.time()-start))