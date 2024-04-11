import marshal
data1 = ['def', 34, 87]
data2 = {1: '优秀', 2: '良好', 3: '合格', 4: '不合格'}
data3 = (5, 6, 7)
with open("marshal_file.dat", 'wb') as output_file:
    marshal.dump(data1, output_file)
    marshal.dump(data2, output_file)
    marshal.dump(data3, output_file)
print("写入数据成功！")

with open("marshal_file.dat", 'rb') as mf:
    data1 = marshal.load(mf)
    data2 = marshal.load(mf)
    data3 = marshal.load(mf)
print(data1, data2, data3)

