list1 = [8, 3, 1, 5, 2]
N = list1.__len__()
print('排序之前：', end=' ')
for i in range(N):
    print(list1[i], end=' ')
print()


for i in range(N-1):
    for j in range(N-i-1):
        if list1[j] > list1[j+1]:
            list1[j+1], list1[j] = list1[j], list1[j+1]
print('排序之后：', end=' ')
for i in range(N):
    print(list1[i], end=' ')
print()
