# 一个球从100m高处做自由落体运动，每次掉落，回弹高度为开始的一半，问它第十次撞击地面时运动了多少m？
# 回弹多少m？
from __future__ import division
h = 100
s = 0
n = int(input("请输入撞击地面的次数："))
for i in range(1, n):
    s = s + h
    h = h / 2.0
print("此时运动了%dm，回弹%fm" % (s, h/2))
