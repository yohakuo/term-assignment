#
sum = 0
for i in range(0, 21, 3):
    sum = sum + i
print('sum=', sum)

"""
法二-
sum = 0
for i in range(1, 21):
    if i % 3 == 0:
    sum = sum + i
print('sum=', sum)
"""

n1 = 1
n2 = 1
count = 2
print("斐波那契数列前10列为：", end=' ')
print(n1, n2, end=' ')
while True:
    if count >= 10:
        break
    nth = n1 + n2   # 下一项
    print(nth, end=' ')  # 输出count+1项
    n1 = n2
    n2 = nth
    count += 1




