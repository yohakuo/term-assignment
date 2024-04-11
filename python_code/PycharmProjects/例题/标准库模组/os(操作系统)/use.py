import os
print("分隔符：", os.sep)
print("操作系统平台：", os.name)
print("环境变量path：", os.getenv('path'))
print("当前工作路径：", os.getcwd())
print("当前路径的目录和文件列表：", os.listdir())

os.rename("use1.py", "use.py")
print("重命名文件后，当前路径的目录和文件列表：", os.listdir())

os.mkdir("new")
print("创建新目录后，当前路径的目录和文件列表：", os.listdir())

os.chdir("new")
print("改变当前工作路径后，当前工作路径：")
