world_GDP_set = {"美国", "中国", "日本", "德国", "英国"}
world_GDP_set_copy1 = world_GDP_set.copy()
world_GDP_set_copy2 = world_GDP_set
world_GDP_set.add("法国")
print("world_GDP_set:", world_GDP_set)
print("world_GDP_set_copy1:", world_GDP_set_copy1)
print("world_GDP_set_copy2", world_GDP_set_copy2)
del world_GDP_set
