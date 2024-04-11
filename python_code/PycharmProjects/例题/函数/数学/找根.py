import math

a = 2.0
b = 3.0
c = 1.0
pbs = b ** 2 - 4 * a * c
x1 = (-b + math.sqrt(pbs)) / (2 * a)
x2 = (-b - math.sqrt(pbs)) / (2 * a)
print("x1=", x1)
print("x2=", x2)
