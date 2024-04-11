#  输入具体的日期，确定这是今年的哪一天
day = int(input("please enter day："))
month = int(input("please enter month："))
dayList = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

num = 0
i = 0
if month == 1:
    num = day
    print(num)
while month-1:
    num = int(dayList[i]) + num
    i = i + 1
    month = month - 1
    if month == 1:
        num = num + day
        print(num)