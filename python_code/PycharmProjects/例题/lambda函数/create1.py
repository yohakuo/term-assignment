list5 = [1, 2, 3, 3, 2, 4]
print([item for item in list5])    # 不加[]输出的不是列表类型，而是一个“生成器表达式”
print([str.title() for str in {"chinese", "america", "england"}])