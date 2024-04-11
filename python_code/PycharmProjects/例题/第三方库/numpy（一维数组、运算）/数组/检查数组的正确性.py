import numpy as np
a = np.arange(24).reshape(2, 3, 4)  # 数组的维度 返回一个数
print(a.ndim)                       # 维度大小的元组
print(a.shape)
print(a.size)
print(a.dtype)
print(a.itemsize)