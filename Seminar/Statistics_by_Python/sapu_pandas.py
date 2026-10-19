# sapu_pandas.python
import pandas as pd
# read_excel ではなく read_csv で読み込みます
try:
    # まずは一般的な utf-8 または cp932（日本語Windows標準）で試す
    df = pd.read_csv('user_data.xlsx', encoding='cp932')
except UnicodeDecodeError:
    df = pd.read_csv('user_data.xlsx', encoding='utf-8')

print(df)