import numpy as np

a = np.arange(8)
print(a.reshape(2, 4))
print(np.transpose(a.reshape(2, 4)))

# 2
b = np.array([[1, 2], [3, 4]])
print(b * 2)  # 与数相乘
c = np.array(([[5, 6], [7, 8]]))
print(b + c)  # 数组相加

print(np.dot(b, c))  # 数组内积
print(np.matmul(b, c))  # 两个数组的矩阵乘法
print(np.vdot(b, c))  # 数组的点积
print(np.inner(b, c))  # 数组的向量内积
print(np.linalg.det(b))  # 求矩阵行列式
print(np.linalg.inv(a))  # 求逆矩阵
