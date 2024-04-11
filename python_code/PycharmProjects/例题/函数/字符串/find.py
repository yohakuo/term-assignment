str = "时间是一切财富中最宝贵的财富"
print("子字符串位置：", str.find("财富"))
print("子字符串位置：", str.find("财富", 6))
print("子字符串位置：", str.rfind("财富"))
print("子字符串位置：", str.rfind("财富", 4, 10))
print("子字符串位置：", str.rfind("成功"))
print(str.startswith("时间"))
print(str.endswith("财富"))
# 找不到返回-1
