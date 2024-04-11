file = open(r"C:\Users\23947\Desktop\text.txt")
print("文件名字：", file.name)
print("访问模式：", file.mode)
print("是否已关闭：", file.closed)
file.close()

with open(r"C:\Users\23947\Desktop\text.txt", "w") as file:
    num = file.write("Go its own way, let others say!")
    # 写入字符串
    print("写入字符%d个！" % num)


