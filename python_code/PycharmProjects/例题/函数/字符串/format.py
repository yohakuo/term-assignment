# 根据位置格式化
print('{0}, {1}.'.format('Hello', 'World'))
print('{},I am {}.'.format('Hello', 'Python'))
print('{0} {1},{1} is a new programming language.'.format('Hello', 'Python'))
'''
数字必须是大于0的整数
带数字的替换字段可以重复
数字形式的简单字段名相当于把字段当成一个序列形式。通过索引的形式进行一一取值
'''

# 根据key格式化
print("网站名：{name}，地址{url}".format(name="清华大学", url="http://www.tsinghua.edu.cn/"))
'''
数字和关键字段可以混合使用传递参数
关键字参数必须位于位置参数之后。
混合使用时，可以省略数字
省略字段名{}不能和数字形式的字段名同时使用
'''

# 根据字典格式化
site = {"name": "清华大学", "url": "http://www.tsinghua.edu.cn/"}
print("网站名：{name}，地址{url}".format(**site))


# 根据列表格式化
list = ['world', 'python']
print('hello {names[0]},I am {names[1]}.'.format(names=list))
print('hello {0[0]},I am {0[1]}.'.format(list))

# 数字格式化
print("{:.2f}".format(3.1415926))
print("{:+.2f}".format(3.1415926))
print("{:.0f}".format(3.1415926))
print("{:0>2d}".format(6))


