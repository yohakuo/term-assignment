import math

x1 = 3.12
x2 = 3.36
x3 = 3.08
x_ = (x1 + x2 + x3) / 3
s = math.sqrt((math.pow(x1 - x_, 2) + math.pow(x2 - x_, 2) \
               + math.pow(x3 - x_, 2)) / 3)
print("x_ =", x_)
print("s =", s)
