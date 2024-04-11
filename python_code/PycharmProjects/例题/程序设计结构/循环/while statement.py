total = 0
ave = 0
count = 0
score = int(input("请输入学生英语成绩："))
while score != -1:
    total = total + score
    count = count + 1
    score = int(input("请输入学生英语成绩："))
ave = total / count
print("录入学生英语成绩%d份，学生英语总成绩%d，平均成绩%4.2f." % (count, total, ave))
