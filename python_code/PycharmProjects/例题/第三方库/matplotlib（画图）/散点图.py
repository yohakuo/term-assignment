import matplotlib.pyplot as plt
import numpy as np
n = 512
x = np.random.normal(0, 1, n)
y = np.random.normal(0, 1, n)
color = np.arctan2(y, x)
plt.scatter(x, y, s=75, c=color, alpha=0.6)
plt.xlim((-2.0, 2.0))
plt.ylim((-2.0, 2.0))
plt.show()
