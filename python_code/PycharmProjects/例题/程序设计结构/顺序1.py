from math import exp, log
x = float(input("请输入x的值："))
if x < 2.0:
    y = 2 * exp(x-1)
else:
    y = log(x ** 2 - 1, 3)
print("y=%9.6f." % y)
