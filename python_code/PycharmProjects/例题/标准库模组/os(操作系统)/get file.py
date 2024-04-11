import os

print("(路径，文件)：", os.path.split(r"C:\Users\23947\PycharmProjects\
例题\标准库模组\os(操作系统)\get file.py"))
print("目录存在？：", os.path.exists(r"C:\Users\23947\PycharmProjects\例题"))
print("文件存在？：", os.path.isfile(r"C:\Users\23947\PycharmProjects\例题\标准库模组\os(操作系统)\get file.py"))
print("文件大小：", os.path.getsize(r"C:\Users\23947\PycharmProjects\例题\标准库模组\os(操作系统)\get file.py"))

# 路径不要直接分行
