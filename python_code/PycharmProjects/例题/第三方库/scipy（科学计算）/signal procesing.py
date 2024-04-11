import numpy as np
import scipy.signal
x = np.array([3, 4, 5])
h = np.array([6, 7, 8])
nn = scipy.signal.convolve(x, h)  # 一维卷积
print("nn:", nn)
