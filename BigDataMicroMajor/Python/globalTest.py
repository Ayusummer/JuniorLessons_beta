from pandas import Series

s1 = Series(range(1, 11))
s2 = Series({'语文': 90, '数学': 87, '英语': 67, '程序设计': 78})
# print("s1:\n{0}\ns2:\n{1}".format(s1, s2))

# 通过索引，切片访问Series的value
# print("s1[4] : {0}\ns2['英语'] : {1}".format(s1[4], s2['英语']))
# print("s1[1:4]:\n{0}\n"
#       "s2[1:3]:\n{1}".format(s1[1:4], s2[1:3]))


# 通过索引修改Series的value，注意字典的键为索引
s2['程序设计'] = 89
print("s2:\n{0}".format(s2))
