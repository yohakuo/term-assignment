import time
print("时间戳格式时间:", time.time())
print("struct_time格式时间:", time.localtime(time.time()))
print("字符串格式时间:", time.ctime())
print("字符串格式时间:", time.asctime())
print(time.strftime('%Y-%m-%d %H:%H', time.localtime()))  # time.strftime可以修改格式
help(time.localtime)