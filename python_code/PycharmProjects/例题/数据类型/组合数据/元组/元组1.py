tuple1 = tuple()
print(tuple1)
print(tuple(["莎士比亚", "托尔斯泰", "但丁", "雨果", "歌德"]))
print(tuple("理想是人生的太阳"))
print(tuple(range(1, 6)))


cityTuple = ("维也纳", "苏黎世", "奥克兰", "慕尼黑", "温哥华", "杜塞尔多夫")
print(cityTuple)
print(cityTuple[3])
print(cityTuple[-2])

print(cityTuple[1:4])
print(cityTuple[1:4:2])
print(cityTuple[:])
print(cityTuple[:4])
print(cityTuple[2:])
print(cityTuple[2:-2])

print("全球生活质量最高的城市：", end=' ')
for city in cityTuple:
    print(city, end=' ')