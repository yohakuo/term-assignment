# 出生三月后，一对兔子会每月生一对，如果兔子不会死，求第三十个月兔子的总数

def fib(n):
    if n <= 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)


i = int(input("输入月："))
print("%d月后兔子的数量为：%d" % (i, fib(i)))
