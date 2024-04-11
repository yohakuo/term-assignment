from datetime import date
from datetime import time
d = date.today()
print("当前本地日期：", d)
print("日期：%d年 %d月 %d日." % (d.year, d.month, d.day))
print("今天是周%d." % d.isoweekday())


print("时间最大值：", time.max)
print("时间最小值：", time.min)
t = time(20, 30, 50, 8888)
print("时间：%d时%d分%d秒%d微秒." % (t.hour, t.minute, t.second, t.microsecond))
