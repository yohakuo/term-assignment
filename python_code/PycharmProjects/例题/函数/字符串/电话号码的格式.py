phone = input("请输入电话号码：")
while True:
    if phone.isdecimal() and len(phone) == 11:
        print("您的电话号码是：", phone)
        break
    else:
        phone = input("您输入的电话号码不正确！\n请重新输入")
