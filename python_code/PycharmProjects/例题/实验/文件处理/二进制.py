import pickle
list1 = [2, 4, 5, 8]
tuple1 = ("music", "game", "sports")
data = [list1, tuple1]
with open("pickle_file.dat", "wb") as pf:
    for i in data:
        pickle.dump(i, pf)
    print("写入数据成功！")

with open("pickle_file.dat", "rb") as pf1:
    data1 = pickle.load(pf1)
    print("data1:", data1)
    data2 = pickle.load(pf1)
    print("data2:", data2)
