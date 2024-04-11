from scipy import linalg
import numpy as np
# 计算矩阵的行列式和逆矩阵
mat = np.array([[5, 6], [7, 8]])
print("方阵：", mat)
print("方阵的行列式：%6.2f." % linalg.inv(mat))
