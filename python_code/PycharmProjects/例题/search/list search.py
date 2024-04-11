import time
start = time.time()

list1 = [3, 6, 1, 9, 5, 8, 7, 4]
key = int(input("请输入要查找的关键字："))
num = -1
n = 0
while n < 1000:
    for i in range(len(list1)):
        if list1[i] == key:
            num = i
            break
    if num != -1:
        print("要查找的关键字%d索引为%d" % (key, num))
    else:
        print("关键字%d查找失败！" % key)
    n = n+1


end = time.time()
print((end-start)/1000)