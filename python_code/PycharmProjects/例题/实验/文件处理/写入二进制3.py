import shelve
tg = dict(zip(['name', 'age'], ['Tong Gang', 31]))
tj = dict(zip(['name', 'age'], ['Tie Jin', 42]))
with shelve.open('shelve_file')as sf:
    sf['tg'] = tg
    sf['tj'] = tj
    print("写入数据成功！")
    print(sf['tg'])
    print(sf['tj'])
# 读取
with shelve.open('shelve_file') as sf1:
    tg = sf1['tg']
    tg['name'] = 'Tong Gen'  # 修改
    sf1['tg'] = tg      # 存储
    print(sf1['tg'])
