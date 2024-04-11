import timeit


def myfunc():
    sum = 0
    for i in range(1, 100):
        for j in range(1, 100):
            sum = sum + 1 * j


t1 = timeit.timeit(stmt=myfunc, number=1000)
print("t1=", t1)
t2 = timeit.repeat(stmt=myfunc, number=1000, repeat=6)
print("t2:", t2)
