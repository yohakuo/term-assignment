# include <stdio.h>
# profit<=100000r ,bonus increase by 10%
profit = int(input("请输入每月利润:"))
bonus = 0
if profit <= 100000:
    bonus = profit * 1.1
elif profit > 100000 & profit <= 200000:
    bonus = (profit - 100000) * 0.075 + 100000 * 0.1
elif profit > 200000 & profit <= 400000:
    bonus = (profit - 200000) * 0.05
elif profit > 400000 & profit <= 600000:
    bonus = (profit - 400000) * 0.03
elif profit > 600000 & profit <= 1000000:
    bonus = (profit - 600000) * 0.015
elif profit > 1000000:
    bonus = (profit - 1000000) * 0.01
print(bonus)
