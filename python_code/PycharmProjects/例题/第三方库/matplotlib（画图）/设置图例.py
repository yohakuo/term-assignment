import matplotlib.pyplot as plt
import numpy as np
x = np.arange(1, 20, 1)
plt.plot(x, x ** 2 + 1, 'red', lw=2)
plt.plot(x, x * 16, 'b', linestyle='dashed', lw=2)
plt.legend(['x**2', '16*x'])
plt.show()
