from fib_example import rec_fib
import time


def py_rec_fib(nr):
    if nr == 0:
        return 0
    if nr == 1:
        return 1
    return py_rec_fib(nr-1) + py_rec_fib(nr-2)

nr = 36

# pybind
start = time.time()
print('The {} th number of the fibonacci sequence is {}'.format(nr, rec_fib(nr)))
print('Pybind function used {} seconds'.format(time.time()-start))

# python
start = time.time()
print('The {} th number of the fibonacci sequence is {}'.format(nr, py_rec_fib(nr)))
print('Python function used {} seconds'.format(time.time()-start))