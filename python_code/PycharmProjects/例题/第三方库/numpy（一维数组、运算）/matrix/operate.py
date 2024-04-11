import numpy as np
A = np.mat('1, 2;3, 4')
print(A * 2)            # 矩阵和数乘
B = np.mat('5, 6;7, 8')
print(A + B)            # 矩阵矩阵相加

print(A.dot(B))         # 矩阵点积
print(np.matmul(A, B))  # 矩阵相乘
print(np.inner(A, B))   # 矩阵内积
print(np.linalg.inv(A))  # 逆矩阵
print(np.linalg.det(A))  # 行列式
