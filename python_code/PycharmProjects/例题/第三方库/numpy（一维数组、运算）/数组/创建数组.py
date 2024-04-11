import numpy as np
print(np.array([1, 2, 3, 4, 5, 6]))  # 一维数组
print(np.array([1, 2, 3, 4, 5, 6]).reshape(2, 3))  # 二维数组

print(np.array([[1, 2, 3], [4, 5, 6]]))  # 二维数组
print(np.array([1, 3, 5], dtype=complex))  # 指定数据类
print(np.array([2, 4, 6], ndmin=2))   # 指定最小维度
