dict1 = {}
dict2 = {"氮": 0.78, "氧": 0.21, "稀有气体": 0.00939, "二氧化碳": 0.00031, "其他": 0.0003}
print(dict2)

dict3 = dict(name="Mary", height=165, weight=51)
print(dict3)

# 以映射函数创建字典
print(dict(zip(["name", "height", "weight"], ["Jack", 178, 72])))

# 以可迭代对象创建
print([("name", "Linda"), ("height", "166"), ("weight", 53)])
