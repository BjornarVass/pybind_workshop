from crossover import simple_crossover, inplace_crossover, inplace_comparison_crossover
import numpy as np
import time
import random


def py_simple_crossover(p1, p2):
    out = []
    for i in range(len(p1)):
        if random.random() < 0.5:
            out.append(p1[i])
        else:
            out.append(p2[i])
    return out


def py_inplace_crossover(p1, p2):
    for i in range(len(p1)):
        if random.random() < 0.5:
            temp = p1[i]
            p1[i] = p2[i]
            p2[i] = temp


def py_inplace_comparison_crossover(p1, p2):
    for i in range(len(p1)):
        if abs(p1[i]-p2[i]) > 5 and random.random() < 0.5:
            temp = p1[i]
            p1[i] = p2[i]
            p2[i] = temp


features = 100000

p1 = np.random.rand(features)*10
p2 = np.random.rand(features)*10

# pybind
start = time.time()
for i in range(100):
    child = simple_crossover(p1, p2)
print('Pybind function used {} seconds on simple crossover'.format(time.time()-start))

# python
start = time.time()
for i in range(100):
    child = py_simple_crossover(p1, p2)
print('Python function used {} seconds on simple crossover'.format(time.time()-start))

# pybind
start = time.time()
for i in range(100):
    c1 = np.copy(p1)
    c2 = np.copy(p2)
    inplace_crossover(c1, c2)
print('Pybind function used {} seconds on inplace crossover'.format(time.time()-start))

# python
start = time.time()
for i in range(100):
    c1 = np.copy(p1)
    c2 = np.copy(p2)
    py_inplace_crossover(c1, c2)
print('Python function used {} seconds on inplace crossover'.format(time.time()-start))

# pybind
start = time.time()
for i in range(100):
    c1 = np.copy(p1)
    c2 = np.copy(p2)
    inplace_comparison_crossover(c1, c2)
print('Pybind function used {} seconds on inplace comparison crossover'.format(time.time()-start))

# python
start = time.time()
for i in range(100):
    c1 = np.copy(p1)
    c2 = np.copy(p2)
    py_inplace_comparison_crossover(c1, c2)
print('Python function used {} seconds on inplace comparison crossover'.format(time.time()-start))
