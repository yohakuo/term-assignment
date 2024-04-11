# 输入一个5位数字，用来确认它是否回文。12321
num = int(input("请输入一个五位数："))
a = num % 10
b = num % 100 // 10
c = num // 100 % 10
d = num // 1000 % 10
e = num // 10000
# print(a, b, c, d, e)
if a == e and b == d:
    print("%d是回文数！" % num)
else:
    print("%d不是回文数！" % num)
