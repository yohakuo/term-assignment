def cube(x):
    return x ** 3
# 计算列表中每个值的三次方


print(list(map(cube, [1, 2, 3, 4, 5])))


def add(x, y):
    return x + y


print(list(map(add, [1, 3, 5, 7, 9], [2, 4, 6, 8, 10])))

a, b = map(int, input("请输入两个数（用空格隔开）：").split())
print("a=%d,b=%d." % (a, b))
