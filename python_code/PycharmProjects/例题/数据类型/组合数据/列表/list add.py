firsttier_city_list = ["北京", "上海", "广州", "深圳"]
print(firsttier_city_list)

firsttier_city_list.append("成都")
print(firsttier_city_list)

firsttier_city_list.insert(2, "杭州")
print(firsttier_city_list)

firsttier_city_list.extend(["重庆", "武汉"])
print(firsttier_city_list)

firsttier_city_list[8:] = ("天津", "郑州")
print(firsttier_city_list)
