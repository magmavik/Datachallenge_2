

import pandas as pd
import numpy  as np

import sys

from matplotlib import pyplot as plt

def calcola_corr( col1, col2, shift):
    if shift == 0:
        a = col1
        b = col2
    elif shift > 0:
        a = col1 [:-shift]
        b = col2 [+shift:]
    elif shift < 0:
        a = col1[-shift:]
        b = col2[:+shift]

    return np.corrcoef(a, b)[0, 1]

data = pd.read_csv(sys.argv[1])

data_list = data['distance'].tolist()

###############################
#### check if correlated  #####

shift = 1
corr = calcola_corr(data_list,data_list, 1)
print(corr)


plt.plot()

plt.hist(data_list, 100,density = True)

plt.show()


print(data)