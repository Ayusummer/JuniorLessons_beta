import os
file_path = os.path.abspath(os.path.join(os.path.dirname(__file__), './res/files/myData.txt'))
with open(file_path, 'r', encoding='GBK') as f:
    my1 = f.read(9)
    my2 = f.readline()    # 从当前指针处读写
    my3 = f.readlines()
print("f.read(9):", my1)
print("f.readline():", my2)
print("f.readlines():", my3)
f.close()
