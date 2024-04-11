cityList = ["珠海", "威海", "信阳", "惠州", "厦门", "金华", "柳州", "曲靖", "九江", "绵阳"]
del cityList[8]
print(cityList)

print(cityList.pop())  # 默认弹出列表末尾的元素
print(cityList.pop(6))

cityList.remove("厦门")
print(cityList)

cityList[4:] = []
print(cityList)

cityList.clear()
print(cityList)


capitalList = ["华盛顿", "伦敦", "巴黎", "北京"]
print("部分国家首都：", capitalList)
del capitalList  # 删除后不能访问

