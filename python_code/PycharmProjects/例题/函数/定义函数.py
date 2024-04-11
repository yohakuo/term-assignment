import math
'''
引入库
定义自己的函数
主函数 
'''


# 定义函数
def func(x, y):
    z = math.sqrt(x ** 2 + y ** 2)
    return z


if __name__ == '__main__':
    a = int(input("请输入一个整数："))
    b = int(input("请输入一个整数："))
    c = func(a, b)
    print("c=", c)
'''
格式错误总结：
每大块需要空两行 
每个小部分需要一个空格 括号内逗号后空格 赋值运算符左右两边 
函数置顶
可以选择注释
'''