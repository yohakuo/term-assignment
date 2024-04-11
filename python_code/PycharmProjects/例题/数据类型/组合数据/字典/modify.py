influential_people_dict = {"牛顿": "物理学家", "孔子": "儒家", "亚里士多德": "哲学家",
                           "达尔文": "生物学家", "欧几里得": "数学家", "伽利略": "天文学家"}
del influential_people_dict["牛顿"]
print(influential_people_dict)

print(influential_people_dict.pop("亚里士多德"))
print(influential_people_dict)

print(influential_people_dict.popitem())
print(influential_people_dict)

influential_people_dict.clear()
print(influential_people_dict)