# 顺序结构中，一条一条实现代码
a = 5
b = 6
c = a + b
print("c=", c)

# 单分支
n = int(input("请输入一个整数："))
flag = str(n) + "是偶数！"
if n % 2 != 0:
    flag = str(n) + "是奇数！"
print(flag)

x = int(input("请输入一个整数："))
y = int(input("请输入一个整数："))
if x < y:
    x, y = y, x
print("%d,%d" % (x, y))

a = 5
b = 6
if a > b:
    max = a
else:
    max = b
print("max=", max)

