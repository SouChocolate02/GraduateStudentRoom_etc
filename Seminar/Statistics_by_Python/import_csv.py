import csv

csv_file = open("./TEST_STOCK.csv", "r", encoding="ms932")
# #リスト形式
f = csv.reader(csv_file, delimiter=",", doublequote=True, lineterminator="\r\n", quotechar='"', skipinitialspace=True)

# # もろもろの処理の後、close
csv_file.close()

f = csv.reader(csv_file, delimiter=",", doublequote=True, lineterminator="\r\n", quotechar='"', skipinitialspace=True)
header = next(f)
print(header)
for row in f:
    #rowはList
    #row[0]で必要な項目を取得することができる
print(row)