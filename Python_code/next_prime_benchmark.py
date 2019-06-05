from prime import next_prime
import time


def is_prime(x):
    if x < 2:
        return True
    for i in range(2, x):
        if x%i == 0:
            return False
    return True

def py_next_prime(x):
    while not is_prime(x):
        x += 1
    return x


test_val = 1000000004

# pybind
start = time.time()
print('The next prime after/including {} is : {}'.format(test_val, next_prime(test_val)))
print('Pybind function used {} seconds'.format(time.time()-start))

# python
start = time.time()
print('The next prime after/including {} is : {}'.format(test_val, py_next_prime(test_val)))
print('Python function used {} seconds'.format(time.time()-start))