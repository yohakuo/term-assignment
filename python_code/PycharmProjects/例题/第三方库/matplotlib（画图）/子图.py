import matplotlib.pyplot as plt
plt.figure()
plt.subplot(2, 2, 1)  # 1
plt.plot([0, 1, 2], [1, 2, 3], 'r')
plt.subplot(2, 2, 2)  # 2
plt.plot([0, 1, 2], [1, 1, 4], 'b')
plt.subplot(2, 2, 3)  # 3
plt.plot([0, 1, 2], [1, 2, 8], 'g')
plt.subplot(2, 2, 4)  # 1
plt.plot([0, 1, 2], [1, 3, 16], 'y')
plt.show()
