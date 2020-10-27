# 编写程序输出该文件的内容，
# 要求使用一次性读入整个文件内容和逐行读取文件内容两种方式。

import os
file_path = os.path.abspath(os.path.join(os.path.dirname(__file__), './yzy.txt'))
with open(file_path, 'r', encoding='UTF-8') as f:
    my1 = f.read()
    print("f.read():", my1)

with open(file_path, 'r', encoding='UTF-8') as f1:
    my2 = f1.readlines()
print("f1.readlines():", my2)

