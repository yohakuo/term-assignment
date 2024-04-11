import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
# r对路径进行转义，windows需要
file_path = r"C:\Users\23947\Desktop\sta000001.xlsx"
# 读取excel文件，并将‘日期’列解析为日期时间格式,并设为索引
raw_data = pd.read_excel(file_path, parse_dates=['data'], index_col='data')
# 日期为索引列
raw_data.index.name = 'data'
# 将数据按日期这一列排序（保证后续计算收益率的正确性）
# raw_data = raw_data.sort_values(by='日期')
# 更多数据信息 print(raw_data.info())
print(raw_data)

# openP = raw_data['open']
# high = raw_data['high']
# low = raw_data['low']
# close = raw_data['close']
# volume = raw_data['volume']
#
#
# print('mean:', 'close-', np.mean(close, axis=0), 'volume-', np.mean(volume, axis=0))
# print('average(close):', np.average(close, axis=0))
# print('max:', np.max(high, axis=0))
# print('min:', np.min(low, axis=0))
# print('波动（high）:', np.ptp(high, axis=0), '波动（low）:', np.ptp(low, axis=0))


print("股票最高价大于9.00元的天数", raw_data.loc[(raw_data['high'] >= 9.00)].count())
print("股票收盘价分组：", np.where(raw_data['close'] >= 9.00, '高', '低'))
print("股票数据的描述性分析：\n", raw_data.describe())
print("股票数据的相关性分析：\n", raw_data.corr())

# raw_data['close'].plot(grid=True, color='red')
# plt.title('2018-7(close)', fontsize='9')
# plt.xlabel('data', fontproperties='SimHei', fontsize=16)
# plt.ylabel('close', fontproperties='SimHei', fontsize=16)
# plt.legend(loc='best', fontsize='small')
# plt.show()
