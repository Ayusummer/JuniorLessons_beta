# 2．编写程序，随机生成由英文字母和数字组成的4位验证码。
import string   # 用于获取所有大小写字母
import random

list1 = list(range(10))
list1.extend(iter(string.ascii_letters))
list_IDCode = [random.choice(list1) for _ in range(4)]
print(list_IDCode)
