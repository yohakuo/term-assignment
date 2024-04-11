# 输入x,y,z,将它们从小到大排序
list1 = [int(input("请输入：")), int(input("请输入：")), int(input("请输入："))]
fir = min(list1)
last = max(list1)
for i in range(0, 2):
    if list1[i] != fir and list1[i] != last:
        sec = list1[i]
        print(fir, sec, last)
