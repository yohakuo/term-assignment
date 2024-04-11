def isevenfunc(n):
    return n % 2 == 0


print(list(filter(isevenfunc, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])))

print(list(zip(["泰山", "黄山", "庐山", "华山"], ["山东", "安徽", "江西", "陕西"])))
z = zip([1, 2, 3], [4, 5, 6])
print(list(zip(*z)))
