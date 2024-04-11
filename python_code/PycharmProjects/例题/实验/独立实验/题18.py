# 有 2/1，3/2，5/3，8/5，13/8，21/13...  求这个数列前20项的和
def fib(n):
    if n <= 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)


s = 0
print(fib(3))
for i in range(2, 23):
    seq = fib(i + 1) / fib(i)
    s += seq
print(s)
