import pandas as pd
data = {'A': "优秀", 'B': "良好", 'C': "合格", 'D': "不合格"}
s = pd.Series(data)
print(s)
print("s[0]:", s[0])
