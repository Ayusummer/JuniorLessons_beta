# 前言
- 含有运行代码及结果的代码可复制粘贴在本文档同目录下的globalTest.py运行
# 作业相关
- 作业上传至 服务器：
  - ftp://211.65.95.251
  - 登陆用户名：student_wll
  - 密码：student_wll
# 换源操作
- [参考文档](https://github.com/winrey/EasyConnectedInChina)
```python
py -3.8 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple opencc  
py -3.8 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple -r requirements.txt
py -3.8 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple --upgrade pip
```
- 镜像源地址
  - 阿里云   
    https://mirrors.aliyun.com/pypi/simple/
  - 中国科技大学  
    https://pypi.mirrors.ustc.edu.cn/simple/
  - 豆瓣(douban)  
    http://pypi.douban.com/simple/
  - 清华大学  
    https://pypi.tuna.tsinghua.edu.cn/simple/
  - 中国科学技术大学  
    http://pypi.mirrors.ustc.edu.cn/simple/   



# Pycharm相关
## 快捷键
### 查找替换
- Ctrl + R 替换
- Ctrl + Shift + R 全局替换
> 无意中触发了TIM快捷键:Ctrl+Alt+F(文字识别)

--- 
# 基础杂项
## 深浅拷贝
- [该部分来源](https://www.runoob.com/w3cnote/python-understanding-dict-copy-shallow-or-deep.html)
- 直接赋值：其实就是对象的引用（别名）。
- 浅拷贝(copy)：拷贝父对象，不会拷贝对象的内部的子对象。
- 深拷贝(deepcopy)： copy 模块的 deepcopy 方法，完全拷贝了父对象及其子对象。
### 字典浅拷贝实例
```python
>>>a = {1: [1,2,3]}
>>> b = a.copy()
>>> a, b
({1: [1, 2, 3]}, {1: [1, 2, 3]})
>>> a[1].append(4)
>>> a, b
({1: [1, 2, 3, 4]}, {1: [1, 2, 3, 4]})
```
### 深度拷贝需要引入 copy 模块：
```python 
>>>import copy
>>> c = copy.deepcopy(a)
>>> a, c
({1: [1, 2, 3, 4]}, {1: [1, 2, 3, 4]})
>>> a[1].append(5)
>>> a, c
({1: [1, 2, 3, 4, 5]}, {1: [1, 2, 3, 4]})
```
### 解析
- b = a: 赋值引用，a 和 b 都指向同一个对象。
  ![](./res/杂项_拷贝_赋值.png)
- b = a.copy(): 浅拷贝, a 和 b 是一个独立的对象，但他们的子对象还是指向统一对象（是引用）。
  ![](./res/杂项_拷贝_浅拷贝.png)
- b = copy.deepcopy(a): 深度拷贝, a 和 b 完全拷贝了父对象及其子对象，两者是完全独立的。
  ![](./res/杂项_拷贝_深拷贝.png)

---
## 逻辑符号
- and的优先级要大于or
- a and b语句的输出全看a的Boolean值，如果a为True，输出b；反之，如果a为False，输出a
- a or b语句的输出也全看a的Boolean值，如果a为True，输出a；反之，如果a为False，输出b
- 在python中not是逻辑判断词，用于布尔型True和False，notTrue为False，notFalse为True
- 只有0、None、空、False的布尔值为False，其余的为True。
  - 参与数学运算时,True->1,False->0;

---
## 输出
- print函数的参数end表示分隔参数(默认为回车)
---
### Python格式化输出 %s %d %f
- %% 百分号标记         
  - 就是输出一个%
- %c 字符及其ASCII码
- %s 字符串
- %d 有符号整数(十进制)
- %u 无符号整数(十进制)
- %o 无符号整数(八进制)
- %x 无符号整数(十六进制)
- %X 无符号整数(十六进制大写字符)
- %e 浮点数字(科学计数法)
- %E 浮点数字(科学计数法，用E代替e)
- %f 浮点数字(用小数点符号)
- %g 浮点数字(根据值的大小采用%e或%f)
- %G 浮点数字(类似于%g)
- %p 指针(用十六进制打印值的内存地址)
- %n 存储输出字符的数量放进参数列表的下一个变量中
#### %格式化符也可用于字典，可用%(name)引用字典中的元素进行格式化输出。
   
- 负号指时数字应该是左对齐的，“0”告诉Python用前导0填充数字，正号指时数字总是显示它的正负(+，-)符号，即使数字是正数也不例外。
        
- 可指定最小的字段宽度，如："%5d" % 2。
- 也可用句点符指定附加的精度，如："%.3d" % 3。
```python
# 例：数字格式化
nYear = 2018
nMonth = 9
nDay = 12
# 格式化日期 %02d数字转成两位整型缺位填0
print ('%04d-%02d-%02d' %(nYear,nMonth,nDay))
>> 2018-09-12 # 输出结果

fValue = 8.123
print ('%06.2f' %fValue) # 保留宽度为6的2位小数浮点型
>> 008.12 # 输出

print ('%d' %10) # 输出十进制
>> 10

print ('%o' %10) # 输出八进制
>> 12

print ('%02x' %10) # 输出两位十六进制，字母小写空缺补零
>> 0a
 
print ('%04X' %10) # 输出四位十六进制，字母大写空缺补零
>> 000A
 
print ('%.2e' %1.2888) # 以科学计数法输出浮点型保留2位小数
>> 1.29e+00
```
#### 格式化操作符辅助指令

#### 符号 作用
- \* 定义宽度或者小数点精度
- \- 用做左对齐
- \+ 在正数前面显示加号( + )
- \<sp> 在正数前面显示空格
- \# 在八进制数前面显示零('0'),在十六进制前面显示'0x'或者'0X'(取决于
          用的是'x'还是'X')
- 0 显示的数字前面填充‘0’而不是默认的空格
- % '%%'输出一个单一的'%'
- (var) 映射变量(字典参数)
- m.n m 是显示的最小总宽度,n 是小数点后的位数(如果可用的话)






---
## random
### randint用于生成正数类型随机数
- n = randint(20, 100)        # 20<=n<=100


---
## 时间
### time.localtime()
- 描述:
  -  Python time localtime() 函数类似gmtime()，作用是格式化时间戳为本地的时间。 如果sec参数未输入，则以当前时间为转换标准。 
  -  DST (Daylight Savings Time) flag (-1, 0 or 1) 是否是夏令时。
- 语法:
  - time.localtime([ sec ])
- 参数:
  - sec -- 转换为time.struct_time类型的对象的秒数。  
- 返回值:
  - 该函数没有任何返回值。 


---
# 函数
- 第4节课
---
## lamda函数:定义匿名函数
```python 
g = lambda x:x+1
```
相当于:
```python
def g(x):
     return x+1
```

---
## 函数注释   
- 例子:
```python
def dog(name:str, age:(1, 99), species:'狗狗的品种') -> tuple:
  return (name, age, species)
```
- 查看这些注释可以通过自定义函数的特殊属性__annotations__获取,结果会议字典的形式返回：
```python
dog.__annotations__
# {'age': (1, 99), 'name': str, 'return': tuple, 'species': '狗狗的品种'}
```
- 另外，使用函数注释并不影响默认参数的使用：
```python
def dog(name:str ='dobi', age:(1, 99) =3, species:'狗狗的品种' ='Labrador') -> tuple:
    return (name, age, species)
```

## *args,**kwargs
[原文链接](https://blog.csdn.net/qq_41877039/article/details/97623476>)  
### *args的用法
- 当传入的参数个数未知，且不需要知道参数名称时使用*args;

---
### **kwargs的用法
- 当传入的参数个数未知，但需要知道参数的名称时(立马想到了字典，即键值对)
```python
def func_kwargs(farg, **kwargs):
    print("formal arg:", farg)
    for key in kwargs:
        print("keyword arg: %s: %s" % (key, kwargs[key]))
func_kwargs(1 ,id=1, name='youzan', city='hangzhou',age ='20',四块五的妞是 = '来日方长的')
print('--------------------')
# 输出结果如下：
# formal arg: 1
# keyword arg: id: 1
# keyword arg: name: youzan
# keyword arg: city: hangzhou
# keyword arg: age: 20
# keyword arg: 四块五的妞是: 来日方长的
#利用它转换参数为字典

def kw_dict(**kwargs):
    return kwargs
print(kw_dict(a=1,b=2,c=3))
# 输出结果如下：
# --------------------
# {'a': 1, 'b': 2, 'c': 3}
```






---
# 可迭代序列
- 第5节课
---
## 切片操作
- 逆序
  ```python
  print(txt[::-1])
  ```

---
## ASCII码
- [ASCII码对照](https://tool.ip138.com/ascii_code)
### chr()函数  
- 描述  
  chr() 用一个范围在 range（256）内的（就是0～255）整数作参数，返回一个对应的字符。
- 用法   
  chr(i)
  - i -- 可以是10进制也可以是16进制的形式的数字。
  - 返回值是当前整数对应的 ASCII 字符。

---
## List
列表
### index()
index() 函数用于从列表中找出某个值第一个匹配项的索引位置。
#### 用法  
```python
list.index(x[, start[, end]])
```
- x-- 查找的对象。
- start-- 可选，查找的起始位置。
- end-- 可选，查找的结束位置。
- 该方法返回查找对象的索引位置，如果没有找到对象则抛出异常。

---
### 删除列表中某个元素的3种方法
- [参考](https://www.cnblogs.com/xiaodai0/p/10564956.html)
- remove、pop、del：
---
#### 1.remove
- 删除单个元素，删除**首个**符合条件的元素，按值删除
```python
# 举例说明:
>>> str=[1,2,3,4,5,2,6]
>>> str.remove(2)
>>> str
>>> [1, 3, 4, 5, 2, 6]
```

---
#### 2.pop
- 删除单个或多个元素，按位删除(根据索引删除)
```python
>>> str=[0,1,2,3,4,5,6]
>>> str.pop(1) #pop删除时会返回被删除的元素
>>> str
>>> [0, 2, 3, 4, 5, 6]
>>> str2=['abc','bcd','dce']
>>> str2.pop(2)
>>> 'dce'
>>> str2
>>> ['abc', 'bcd']
```

---
#### 3.del
- 它是根据索引(元素所在位置)来删除 
```python
# 举例说明:
>>> str=[1,2,3,4,5,2,6]
>>> del str[1]
>>> str
>>> [1, 3, 4, 5, 2, 6]

>>> str2=['abc','bcd','dce']
>>> del str2[1]
>>> str2
>>> ['abc', 'dce']

```
- 除此之外，del还可以删除指定范围内的值。
```python
>>> str=[0,1,2,3,4,5,6]
>>> del str[2:4] #删除从第2个元素开始，到第4个为止的元素(但是不包括尾部元素)
>>> str
>>> [0, 1, 4, 5, 6]

```
- del 也可以删除整个数据对象(列表、集合等)
  ```python
  >>> str=[0,1,2,3,4,5,6]
  >>> del str
  >>> str #删除后，找不到对象
  ```
  ```python
  Traceback (most recent call last):
  File "<pyshell#27>", line 1, in <module>
  str
  NameError: name 'str' is not defined
  ```
> 注意：del是删除引用(变量)而不是删除对象(数据)，对象由自动垃圾回收机制（GC）删除。

---
#### 补充: 删除元素的变相方法
```python
s1 = (1, 2, 3, 4, 5, 6)
s2 = (2, 3, 5)
s3 = []
for i in s1:
    if i not in s2:
        s3.append(i)
print('s1_1:', s1)
s1 = s3
print('s2:', s2)
print('s3:', s3)
print('s1_2:', s1)
```

---
### sort()
sort() 函数用于对原列表进行排序，如果指定参数，则使用比较函数指定的比较函数。
#### 用法
```python
list.sort( key=None, reverse=False)
```
- key -- 主要是用来进行比较的元素，只有一个参数，具体的函数的参数就是取自于可迭代对象中，指定可迭代对象中的一个元素来进行排序。
- reverse -- 排序规则，reverse = True 降序， reverse = False 升序（默认）。
- 注意:该方法**没有返回值**，但是会对列表的对象进行排序。
- list.sort()改变自身
  - sorted(list)生成新列表

---
### map()
map() 会根据提供的函数对指定序列做映射。
#### 用法
```python
map(function, iterable, ...)
```
- function -- 函数
- iterable -- 一个或多个序列
- 第一个参数 function 以参数序列中的每一个元素调用 function 函数，返回包含每次 function 函数返回值的新列表。
- 返回值
  - Python 2.x 返回列表。
  - Python 3.x 返回迭代器。



---
## str 
字符串
### replace()
Python replace() 方法把字符串中的 old（旧字符串） 替换成 new(新字符串)，如果指定第三个参数max，则替换不超过 max 次。
#### 用法
```python
str.replace(old, new[, max])
```
- old -- 将被替换的子字符串。
- new -- 新字符串，用于替换old子字符串。
- max -- 可选字符串, 替换不超过 max 次
- 返回字符串中的 old（旧字符串） 替换成 new(新字符串)后**生成的新字符串**，如果指定第三个参数max，则替换不超过 max 次。

---
### split()
Python split() 通过指定分隔符对字符串进行切片，如果参数 num 有指定值，则分隔 num+1 个子字符串
#### 用法
```python
str.split(str="", num=string.count(str)).
```
- str -- 分隔符，默认为所有的空字符，包括空格、换行(\n)、制表符(\t)等。
- num -- 分割次数。默认为 -1, 即分隔所有。
- 返回分割后的字符串列表。
- > 注意:该方法不会改变原本的字符串
```python
# 实例
str_t = "Line1-abcdef \nLine2-abc \nLine4-abcd"
print("str_t:\n"+str_t)
print("str_t.split():")
print(str_t.split())            # 以空格为分隔符，包含 \n
print("str_t.split(' ', 1):")
print(str_t.split(' ', 1))     # 以空格为分隔符，分隔成两个

# 运行结果
str_t:
Line1-abcdef 
Line2-abc 
Line4-abcd
str_t.split():
['Line1-abcdef', 'Line2-abc', 'Line4-abcd']
str_t.split(' ', 1):
['Line1-abcdef', '\nLine2-abc \nLine4-abcd']

```

---
### join()
Python join() 方法用于将序列中的元素以指定的字符连接生成一个新的字符串。
#### 用法
```python
str.join(sequence)
```
- sequence -- 要连接的元素序列。
- 返回通过指定字符连接序列中元素后生成的新字符串。
```python
# 实例
str_t = ""
seq = ("a", "b", "c")
print(str_t.join(seq))
# 运行结果
abc
```

---
### strip()
Python strip() 方法用于移除字符串头尾指定的字符（默认为空格或换行符）或字符序列。
- 注意：该方法只能删除开头或是结尾的字符，不能删除中间部分的字符。
#### 用法
```python
str.strip([chars]);
```
- chars -- 移除字符串头尾指定的字符序列。
- 返回移除字符串头尾指定的字符生成的新字符串。
  
```python
# 用法
str_t = "00000003210Runoob01230000000"
print(str_t.strip('0'))     # 去除首尾字符 0
print()
str2 = "   Runoob      "    # 去除首尾空格
print(str2.strip())

# 运行结果
3210Runoob0123

Runoob
```

---
### lower()
Python lower() 方法转换字符串中所有大写字符为小写。
#### 用法
```python
str.lower()
```
- 返回将字符串中所有大写字符转换为小写后生成的字符串。
- > 注意:此方法并不会改变原有列表,而是生成一个新列表

---
### string 模块
import string 
```python
string.ascii_uppercase  所有大写字母
string.ascii_lowercase 所有小写字母
string.ascii_letters  所有字母
string.digits  所有数字
```




---
## dict 
- 字典是另一种可变容器模型，且可存储任意类型对象。
  - 字典是无序的 
- 字典的每个键值 key=>value 对用冒号 : 分割，每个键值对之间用逗号 , 分割，整个字典包括在花括号 {} 中 ,格式如下所示：
  ```python
  d = {key1 : value1, key2 : value2 }
  ```
- 键一般是唯一的，如果重复最后的一个键值对会替换前面的，值不需要唯一。
  ```python
  >>> dict = {'a': 1, 'b': 2, 'b': '3'}
  >>> dict['b']
  '3'
  >>> dict
  {'a': 1, 'b': '3'}
  ```
- 值可以取任何数据类型，但键必须是不可变的，如字符串，数字或元组。
  - 一个简单的字典实例：
    ```python
    dict = {'Alice': '2341', 'Beth': '9102', 'Cecil': '3258'} 
    ```
  - 也可如此创建字典：
    ```python
    dict1 = { 'abc': 456 }
    dict2 = { 'abc': 123, 98.6: 37 }  
    ```

---
### 访问字典里的值
把相应的键放入熟悉的方括弧，如下实例:
```python
# 实例
dict1 = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}

print("dict1['Name']: ", dict1['Name'])
print("dict['Age']: ", dict1['Age'])

# 运行结果
dict1['Name']:  Zara
dict['Age']:  7
```

---
### 修改字典
向字典添加新内容的方法是增加新的键/值对，修改或删除已有键/值对如下
```python
# 实例
dict1 = {'Name': 'Zara', 'Age': 7, 'Class':'First'}

dict1['Age'] = 8                # 更新
dict1['School'] = "RUNOOB"      # 添加

print("dict1['Age']: ", dict1['Age'])
print("dict1['School']: ", dict1['School'])

# 运行结果
dict1['Age']:  8
dict1['School']:  RUNOOB
```

---
### 删除字典元素
- 能删单一的元素也能清空字典，清空只需一项操作。
- 删除一个字典用del命令
```python
del dict['Name']  # 删除键是'Name'的条目
dict.clear()      # 清空字典所有条目
del dict          # 删除字典
```

---
### 字典键的特性
- 字典值可以没有限制地取任何python对象，既可以是标准的对象，也可以是用户定义的，但键不行。
- **两个重要的点**需要记住：
  - 不允许同一个键出现两次。创建时如果同一个键被赋值两次，后一个值会被记住
  - 键必须不可变，所以可以用数字，字符串或元组充当，所以用列表就不行


---
# 文件操作
- 学习目标
  - 熟练掌握内置函数open()的应用
  - 理解字符串编码格式对文本文件操作的影响
  - 熟练掌握上下文管理语句with的用法
  - 了解标准库json对JSON文件的读写方法
  - 了解扩展库python-docx、openpyxl、python-pptx对Office文档的操作
---
- python中的文件对象：
  - 文件对象不仅可以用来访问普通的磁盘文件, 而且也可以访问任何其它类型抽象层面上的"文件".
  - 一旦设置了合适的"钩子", 你就可以访问具有文件类型接口的其它对象, 就好像访问的是普通文件一样.

---
## 文件与文件类型
- 文件是存储在外部介质上的一组相关数据的集合。文件的基本单位是字节。文件名由两部分组成：主文件名和扩展名
- 按文件中的数据组织形式文件分为两类：
  - 文本文件
    - 由字符组成，按ASCII码、UTF-8或Unicode等格式编码，文件内容方便查看和编辑。
  - 二进制文件
    - 由0和1组成的二进制编码。典型的二进制文件包括bmp格式的图片文件、avi格式的视频文件、各种计算机语言编译后生成的文件等。
  - 无论是文本文件还是二进制文件，都可以用“文本文件方式”和“二进制文件方式”打开，但打开后的操作是不同的。


---
## 字符编码
- 编码是用数字来表示符号和文字的一种方式，
  - 是符号、文字存储和显示的基础。  
- 信息传递与编码关系：编码--传递--解码
- 常见的编码
  - ASCII     美国标准信息交换码
    - (1个字节,256个字符)
  - UTF-8    国际通用编码
    - (3个字节表示中文及其他语言)
  - GB2312 中国制定的中文编码
    - (英文1个字节,中文2个字节)
  - GBK      GB2312编码的扩展
    - 完全兼容GB2312标准
  - Unicode    
    - 国际组织制定的可以容纳世界上所有文字和符号的字符编码方案。
---
- 字符串在Python内部的表示是unicode编码
  - 因此，在做编码转换时，通常需要以unicode作为中间编码，
    - 即先将其他编码的字符串解码（decode）成unicode，
    - 再从unicode编码（encode）成另一种编码。
- decode的作用是将其他编码的字符串转换成unicode编码
  -  ```python
     str1.decode('gb2312')
     ```
     表示将gb2312编码的字符串str1转换成unicode编码。
- encode的作用是将unicode编码转换成其他编码的字符串
  - ```python
    str2.encode('gb2312')
    ```
    表示将unicode编码的字符串str2转换成gb2312编码。
- 如：s='中文'
  - 如果是在utf8的文件中，该字符串就是utf8编码，如果是在gb2312的文件中，则其编码为gb2312。
    - 这种情况下，要进行编码转换，都需要先用decode方法将其转换成unicode编码，再使用encode方法将其转换成其他编码。
  - 通常，在没有指定特定的编码方式时，都是使用的系统默认编码创建的代码文件。如下：
    - ```python
      s.decode('utf-8').encode('utf-8')
      ```
- decode():是解码
- encode()是编码
- isinstance(s,unicode):  判断s是否是unicode编码，如果是就返回true,否则返回false

---
## 文件操作基础
### 内置函数open()
- Python内置函数open()使用指定的模式打开指定文件并创建文件对象，该函数完整的用法如下：
  ```python
  open(file, mode='r', buffering=-1, encoding=None,
       errors=None, newline=None, closefd=True, opener=None)
  ```
| 模式 | 说明 |
| -- | -- |
| r | 读模式（默认模式，可省略），如果文件不存在，抛出异常 |
| w | 写模式，如果文件已存在，先清空原有内容；如果文件不存在，创建新文件 |
| x | 写模式，创建新文件，如果文件已存在则抛出异常 |
| a | 追加模式，不覆盖文件中原有内容 |
| b | 二进制模式(可与r、w、x或a模式组合使用) |
| t | 文本模式（默认模式，可省略） |
| + | 读、写模式（可与其他模式组合使用） |

---
### 文件对象常用方法
| 方法 | 功能说明 |
| -- | -- |
| close() | 把缓冲区的内容写入文件，同时关闭文件，释放文件对象 |
| read([size]) | 从文本文件中读取并返回size个字符，或从二进制文件中读取并返回size个字节，省略size参数表示读取文件中全部内容 |
| readline() | 从文本文件中读取并返回一行内容 |
| readlines() | 返回包含文本文件中每行内容的列表 |
| seek(cookie, whence=0, /) | 定位文件指针，把文件指针移动到相对于whence的偏移量为cookie的位置。其中whence为0表示文件头，1表示当前位置，2表示文件尾。对于文本文件，whence=2时cookie必须为0；对于二进制文件，whence=2时cookie可以为负数 |
| write(s) | 把s的内容写入文件，如果写入文本文件则s应该是字符串，如果写入二进制文件则s应该是字节串 |
| writelines(s) | 把列表s中的所有字符串写入文本文件，并不在s中每个字符串后面自动增加换行符。也就是说，如果确实想让s中的每个字符串写入文本文件之后各占一行，应由程序员保证每个字符串以换行符结束 |

### 上下文管理语句with
- 在实际开发中，读写文件应优先考虑使用上下文管理语句with。关键字with可以自动管理资源，不论因为什么原因跳出with块，总能保证文件被正确关闭。除了用于文件操作，with关键字还可以用于数据库连接、网络连接或类似场合。用于文件内容读写时，with语句的语法形式如下：
  - ```python 
    with open(filename, mode, encoding) as fp:
    # 这里写通过文件对象fp读写文件内容的语句块
    ```

---
## 文件的打开或创建的访问模式
```python 
#以只读方式打开
>>> file2=open(“c1.py”,”r”)
#以读/写方式打开，指明文件路径
>>> file3=open(“d:\\python35\\test.txt”,”w+”)
#以读/写方式二进制文件
 >>> file4=open(“tu3.jpg”,”ab+”)
```
```python
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



## 执行结果:
f.read(9): learn pyt
f.readline(): hon

f.readlines(): ['hard work\n', '文本文件\n', '二进制文件']
```
