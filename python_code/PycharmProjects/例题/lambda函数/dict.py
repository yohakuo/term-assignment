print({i: i % 3 == 0 for i in range(1, 11)})
chineseList = ["运动", "饮食", "营养"]
englishList = ["motion", "diet", "nutrition"]
print({chineseList[i]: englishList[i] for i in range(len(chineseList))})