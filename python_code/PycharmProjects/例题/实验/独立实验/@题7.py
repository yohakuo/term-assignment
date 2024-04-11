# 乘法表
for i in range(1, 10):
    for j in range(1, i+1):
        print(f'{j}x{i}={i*j}\t', end='')
    print()


# a = 1
# b = 2
# c = 3   \t <-> Tab
# print(f'a={a}, b={b}, c={c}')
# # 等价于print('a={}, b={}, c={}'.format(a, b, c))
#
# 结果：
# a=1, b=2, c=3
