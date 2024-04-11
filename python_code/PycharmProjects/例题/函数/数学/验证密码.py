import random

str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRST"
len = str.__len__()
yzm = ""
for i in range(4):
    yzm = yzm + str[random.randint(0, len - 1)]
print("当前验证码：", yzm)
yzmInput = input("请输入验证码：")
if yzm == yzmInput:
    print("验证通过！")
else:
    print("验证失败！")
