nobel_prize_dict = {"物理学家": ["伦琴", "爱因斯坦", "波尔"],
                    "化学家": ["欧内斯特·卢瑟福", "范特霍夫", "玛丽·居里"],
                    "医学家": ["埃米尔·阿道夫·冯·贝林", "罗伯特·科赫", "屠呦呦"]}
for key, value in nobel_prize_dict.items():
    print("获得诺贝尔奖的" + str(key) + ":", end=' ')
    for item in value:
        print(item, end=' ')
    print()
