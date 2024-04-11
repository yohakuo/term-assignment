delicacySet1 = {"中国冰糖葫芦", "墨西哥卷饼", "英国炸鱼", "美国热狗", "土耳其烤肉",
                "新加坡炒粿"}
delicacySet2 = {"新加坡炒粿", "日本章鱼烧", "韩国炸鸡", "越南虾饼", "曼谷香脆煎饼"}
print(delicacySet1 | delicacySet2)  # 并集
print(delicacySet1 & delicacySet2)  # 交集
print(delicacySet1 - delicacySet2)  # 差集。返回一个新集合,包括在集合1中但不在集合2中的元素
print(delicacySet1 < delicacySet2)  # 子集测试
