import numpy as np
import pandas as pd
from pandas_indexing import simple_filter, simple_filter2
import time

dim = 1000000
diff = 0.25

def py_naive(test_df, diff):
    last_a = test_df.iloc[0].a
    for idx, row in test_df.iterrows():
        if idx == 0 or np.abs(row['a'] - last_a) >= diff:
            test_df.at[idx, 'chg'] = True
            last_a = row['a']

def py_less_naive(test_df, diff):
    last_a = test_df.iloc[0].a
    a = test_df['a']
    chg = test_df['chg']
    n = a.shape[0]
    for i in range(n):
        if i == 0 or np.abs(a.iat[i] - last_a) >= diff:
            chg.iat[i] = True
            last_a = a.iat[i]

test_df_base = pd.DataFrame({'a': np.random.rand(dim)})
test_df_base['chg'] = False


# pybind
test_df = test_df_base.copy()
start = time.time()
simple_filter(test_df['a'], test_df['chg'], diff)
print('Pybind function used {} seconds'.format(time.time()-start))

# python naive
test_df = test_df_base.copy()
start = time.time()
py_naive(test_df, diff)
print('Python naive function used {} seconds'.format(time.time()-start))


# python less naive
test_df = test_df_base.copy()
start = time.time()
py_less_naive(test_df, diff)
print('Python less naive function used {} seconds'.format(time.time()-start))