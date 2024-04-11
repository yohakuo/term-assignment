"""
单个字符是字符串
三引号可以创建跨行字符串
字符串中元素被分配为数字，也称为index
第一个元素的索引是0，第二个是1
可以正向或反向索引，最后一个元素的索引是-1，倒数第二个是-2
"""
print("Are you happy?")
print(u"I am really\u0020pleased.")
print(r"d:friends.txt")
print(b"rejoice")
print(bytes("中国", "GBK"))
print(str(b'\xd6\xd0\xb9\xfa', "GBK"))
print(bytes("中国", "UTF-8"))
print(str(b'\xe4\xb8\xad\xe5\x9b\xbd', "UTF-8"))
