from vectorized_funcs import subtract_or_add, euc_dist
import time
import numpy as np
import math


def py_subtractOrAdd(x, y):
    if x > y:
        return x - y
    else:
        return x + y

def py_euc_dist(x, y):
    if x > y:
        return math.sqrt(x*x + y*y)
    else:
        return math.sqrt(x*y + x*y)

size = 100000000
x = np.random.randint(10, size=size)
y = np.random.randint(10, size=size)
#y = 4

print("SIMPLE SUBTRACTION AND ADDITION")
# pybind
start = time.time()
out_array = subtract_or_add(x, y)
print('Pybind function used {} seconds'.format(time.time()-start))


# python
vectorized = np.vectorize(py_subtractOrAdd)
start = time.time()
out_array = vectorized(x, y)
print('Python function used {} seconds'.format(time.time()-start))

print("\nMULTIPLICATON AND SQRT")
# pybind
start = time.time()
out_array = euc_dist(x, y)
print('Pybind function used {} seconds'.format(time.time()-start))


# python
vectorized = np.vectorize(py_euc_dist)
start = time.time()
out_array = vectorized(x, y)
print('Python function used {} seconds'.format(time.time()-start))