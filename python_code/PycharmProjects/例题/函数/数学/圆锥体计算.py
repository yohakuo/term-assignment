import math
PI = math.pi

r = float(input("请输入圆锥体的半径:"))
h = float(input("请输入圆锥体的高:"))
s1 = PI * r ** 2
s2 = PI * r * math.sqrt(r ** 2 + h ** 2)
s = s2 + s1
v = 1 / 3 * PI * r ** 2 * h
print("圆锥体的表面积为：%6.2f" % s)
print("圆锥体的体积为：%6.2f" % v)