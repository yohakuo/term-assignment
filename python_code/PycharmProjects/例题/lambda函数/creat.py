print([x ** 2 for x in range(6)])
print([[x, pow(10, x)]for x in range(4)])
print([abs(x) for x in [1, -2, 3, -4, 5, -6]if x < 0])
list1 = [1, 2, 3]
list2 = [4, 5, 6]
print([(x, y) for x in list1 for y in list2])

list3 = ["指南针", "火药", "造纸术", "印刷术"]
list4 = ["中国劳动人民", "唐朝炼丹家", "蔡伦", "毕昇"]
print([list3[i] + "由" + list4[i] + "发明" for i in range(len(list3))])


