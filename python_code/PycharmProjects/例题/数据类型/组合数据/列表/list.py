# []create list
list1 = []
list2 = [1.25, 21.06, 0.3, 4.7, 58.1]
list3 = ["石油", "汽车", "建筑", "IT"]
list4 = ['Alice', 18, 'Beth', 19]

# list()
list5 = list()
list(("李白", "杜甫", "白居易"))
print(list5)
print(list("素质重于学历"))
print(list(range(5)))

# accessing list or elements  索引号左闭右开
carList = ["奔驰", "大众", "福特", "宝马", "奥迪", "雪佛山"]
print("carList:", carList)
print("carList[2]:", carList[2])
print("carList[-1]:", carList[-1])

# list slicing
print("carList[2:5]:", carList[2:5])
print("carList[2:5:2]:", carList[2:5:2])
print("carList[:]:", carList[:])
print("carList[:5]:", carList[:5])
print("carList[3:]:", carList[3:])
print("carList[2:-1]:", carList[2:-1])

# traverse（遍历） list
print("世界汽车品牌：", end=' ')
for car in carList:
    print(car, end=' ')
