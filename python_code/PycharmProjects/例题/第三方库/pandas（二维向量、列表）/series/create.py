import pandas as pd
import numpy as np
data = np.array(['需求分析', '概要分析', '详细设计', '编制代码', '运行维护'])
s = pd.Series(data)
print(s)