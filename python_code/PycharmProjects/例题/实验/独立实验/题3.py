# include <stdio.h>
# 一个整数，再加100后它为完全平方数，加上268是也为完全平方数
import math

for x in range(0, 9999):
    m = math.sqrt(x + 100)
    n = math.sqrt(x + 268)
    if m % 1 == 0:
        if n % 1 == 0:
            print(x)

