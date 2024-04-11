from datetime import datetime
from datetime import timedelta
dt = datetime.now()
print("当前日期：", dt.date())
print("当前时间：", dt.timetz())
print("当前年份：%d，当前月份：%d，当前日期：%d." % datetime(2018, 9, 16, 12, 20, 36))


print("1周包含的总秒数：", timedelta(days=7).total_seconds())
d = datetime.now()
print("当前本地系统时间：", d)
print("1天后", d+timedelta(days=1))
print("1天前", d+timedelta(days=-1))



