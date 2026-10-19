# 2.2.1 不要なデータを除外する

import pandas as pd
kokusei= pd.read_csv('data/c01.csv', encoding= 'shift_jis')
kokusei.head()
print('Hello')