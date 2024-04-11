score = int(input("请输入成绩："))
if score >= 90:
    print("成绩等级：优秀！")
elif score >= 80:
    print("成绩等级：良好！")
elif score >= 60:
    print("成绩等级：合格！")
else:
    print("成绩等级：不合格！")


score = int(input("请输入学生成绩："))
flag = "合格"if score >= 60 else "未合格"
print("成绩结果：", flag)


x, op, y = input("请输入操作数和操作符：").split()
if op == "+":
    z = float(x) + float(y)
    print("运行程序结果：", x, op, y, "=", z)
elif op == "-":
    z = float(x) - float(y)
    print("运行程序结果：", x, op, y, "=", z)
elif op == "*":
    z = float(x) * float(y)
    print("运行程序结果：", x, op, y, "=", z)
elif op == "/":
    z = float(x) / float(y)
    print("运行程序结果：", x, op, y, "=", z)
else:
    print("您输入的运算符不支持！请重新输入！")
