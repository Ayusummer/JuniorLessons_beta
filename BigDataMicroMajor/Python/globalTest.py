fName = "program0805.py"
file = None
try:
    file = open(fName, "r", encoding="utf-8")
    for line in file:
        print(line, end="")
except FileNotFoundError:
    print("您要读取的文件不存在，请确认")
else:
    print("文件读取正常结束")
finally:
    print("文件正常关闭")
    if file != None:
        file.close()
