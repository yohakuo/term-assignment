# 如果一个数恰好等于除它以外的所有公约数的和，它就被称为完全数。请打印1000以内的数字
i = 6
while i < 1000:
    sum1 = 0
    for j in range(1, i):
        if i % j == 0:
            sum1 += j
    if sum1 == i:
        print(i)
    i = i + 1
