phoneSet = {"华为", "苹果"}
print("手机品牌：", phoneSet)
phoneSet.add("小米")    # 只能添加一个
print("set.add()添加元素后：", phoneSet)
phoneSet.update(["华为", "Oppo", "Vivo"])
print("set.update()添加元素后：", phoneSet)


world_tournament_set = {"世界杯排球赛", "世界乒乓球锦标赛", "世界篮球锦标赛",
                        "世界足球锦标赛"}
print("世界大赛：", world_tournament_set)
world_tournament_set.remove("世界足球锦标赛")
print("set.remove删除元素后：", world_tournament_set)
world_tournament_set.discard("世界杯排球赛")
print("set.discard删除元素后：", world_tournament_set)
world_tournament_set.clear()
print("set.clear删除元素后：", world_tournament_set)

