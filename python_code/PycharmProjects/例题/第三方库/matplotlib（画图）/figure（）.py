import numpy as np
import matplotlib.pyplot as plt
x = np.linspace(-1, 1, 50)
# figure 1
y1 = 3 * x - 1
plt.figure()
plt.plot(x, y1, 'r')       # 绘图
# figure 2
y2 = x ** 2
plt.figure()
plt.plot(x, y2, 'b')       # 绘图
plt.show()


