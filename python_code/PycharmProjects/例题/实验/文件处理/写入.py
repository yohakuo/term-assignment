with open(r"C:\Users\23947\Desktop\text1.txt", "w") as file:
    num = file.write("黑夜无论怎样悠长\n白昼总会到来")
    print("向文件写入字符%d个！" % num)

    str1 = input("请输入内容：")      # 输入 ——莎士比亚
with open(r"C:\Users\23947\Desktop\text1.txt", "a") as file:    # a表示追加模式
    file.write("\n")
    num = file.write(str1)
    print("向文件写入字符%d个！" % num)


# 读文件
with open(r"C:\Users\23947\Desktop\text1.txt", "r") as file1:
    str2 = file1.read()
    print(str2, '\n')

# 读取一行
with open(r"C:\Users\23947\Desktop\text1.txt", "r") as file2:
    str3 = file2.readline()
    print(str3, '\n')

with open(r"C:\Users\23947\Desktop\text1.txt", "r") as file3:
    data = file3.readline()
    print('输出一行后的文件指针在：', file3.tell())
    file3.seek(0)
    print('用seek（）将文件指针放回开始处：', file3.tell())
    print('再次输出：', file3.readline())