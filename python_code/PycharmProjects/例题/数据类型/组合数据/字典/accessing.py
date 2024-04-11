LSZ_dict = {"姓名": "李时珍", "出生时间": 1518, "籍贯": "湖北", "职业": "医生"}
print("LSZ_dict:", LSZ_dict)
print("LSZ_dict中元素个数：", len(LSZ_dict))
print("姓名：", LSZ_dict["姓名"])
print("籍贯：", LSZ_dict["籍贯"])
print("职业：", LSZ_dict["职业"])

print("字典中所有的键/值：", end=' ')
for key, value in LSZ_dict.items():   # 遍历字典
    print(key, '/', value, end=',')
print()
print("字典中所有的键：", end=' ')
for key in LSZ_dict.items():
    print(key, end=',')
print()
