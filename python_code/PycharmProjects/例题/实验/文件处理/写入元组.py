mingTuple = ("王朝阳", "于谦", "戚继光", "海瑞", "郑和", "徐达")
with open(r"C:\Users\23947\Desktop\text.txt", "w") as file:
    num = file.write(str(mingTuple))
    print("写入元组成功！")

str1 = ["\n好雨知时节，当春乃发生。\n", "随风潜入夜，润物细无声。"]
with open(r"C:\Users\23947\Desktop\text1.txt", "w") as file:
    file.writelines(str1)
    print("写入字符序列成功！")

# 读
with open(r"C:\Users\23947\Desktop\text1.txt", "r") as file:
    for line in file:           # 循环读取
        print(line, end=" ")

# 按行读取
with open(r"C:\Users\23947\Desktop\text1.txt", "r") as f:
    str2 = f.readlines()
    print('\n', str2)