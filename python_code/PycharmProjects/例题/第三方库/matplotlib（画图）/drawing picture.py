import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5, 6, 7, 8]
y = [3, 5, 6, 9, 13, 6, 32, 111]
plt.xlim((0, 10))
plt.ylim((0, 120))
plt.xlabel('x轴', fontproperties='SimHei', fontsize=16)  # Fontsize不对
plt.ylabel('y轴', fontproperties='SimHei', fontsize=16)
plt.plot(x, y, 'r', lw=2)
plt.show()
