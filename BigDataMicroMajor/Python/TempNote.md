# Pandas

---
## Pandas数据分析
- pandas的名称来自于panel data(面板数据）和data analysis(数据分析)。
- 是基于扩展库numpy和matplotlib的数据分析模块，是一个开源项目。
- Pandas提供了大量标准数据模型和高效操作大型数据集所需要的函数和方法，是使得Python能够成为高效且强大的数据分析工具的重要因素之一。

---
## pandas数据结构
-  Pandas常用的数据结构有：
   - 1）Series，带标签的一维数组；
   - 2）DatetimeIndex，时间序列；
   - 3）DataFrame，带标签且大小可变的二维表格结构；
   - 4）Panel，带标签且大小可变的三维数组。

---
### Series
- pandas提供的类似于一维数组的字典结构的对象，
  - 由**索引**（数据标签）和**数据**两部分组成。
- 如果在创建时没有明确指定索引则会自动使用从0开始的非负整数作为索引。

---
- Series对象
    ```Python
    a = pd.Series([23, 54, 32, 65, 87, 54])
    # print(a)
    0    23
    1    54
    2    32
    3    65
    4    87
    5    54
    dtype: int64
    ```
    - 通常默认索引从0开始
    - 自定义索引
        ```Python
        b = pd.Series([23, 54, 32, 65, 87, 54],
                    index=[chr(i + ord('A')) for i in range(6)])
        # 输出b
        A    23
        B    54
        C    32
        D    65
        E    87
        F    54
        dtype: int64
        ```

---
#### 常用创建方法
```python
from pandas import Series
import numpy as np

# 1.使用列表创建Series
s1 = Series([1, 2, 3, 4])
# 2. 使用range创建Series
s2 = Series(range(3))
# 3.使用numpy一维数组创建Series
s3 = Series(np.array([1, 2, 3, 4]))
s4 = Series(np.arange(6, 10))
# 4.使用字典创建Series，其中字典的键，就是索引
s5 = Series({'语文': 90, '数学': 87})
# 创建Series时不指定索引，默认生成从0开始的序列，也可自行指定索引
s6 = Series([12, 3, 4], index=['A', 'B', 'C'])
s7 = Series([12.3, 34.5, 3.6, ], ['I', 'II', 'III'])
print("s1 = Series([1, 2, 3, 4]):\n{0}\n"
      "s2 = Series(range(3)):\n{1}\n"
      "s3 = Series(np.array([1, 2, 3, 4])):\n{2}\n"
      "s4 = Series(np.arange(6, 10)):\n{3}\n"
      .format(s1, s2, s3, s4))
print(r"s5 = Series({'语文': 90, '数学': 87}):")
print(s5)
print("s6 = Series([12, 3, 4], index=['A', 'B', 'C']):\n{0}"
      "s7 = Series([12.3, 34.5, 3.6, ], ['I', 'II', 'III']):\n{0}"
      .format(s6, s7))


# 运行结果
s1 = Series([1, 2, 3, 4]):
0    1
1    2
2    3
3    4
dtype: int64
s2 = Series(range(3)):
0    0
1    1
2    2
dtype: int64
s3 = Series(np.array([1, 2, 3, 4])):
0    1
1    2
2    3
3    4
dtype: int32
s4 = Series(np.arange(6, 10)):
0    6
1    7
2    8
3    9
dtype: int32

s5 = Series({'语文': 90, '数学': 87}):
语文    90
数学    87
dtype: int64
s6 = Series([12, 3, 4], index=['A', 'B', 'C']):
A    12
B     3
C     4
dtype: int64s7 = Series([12.3, 34.5, 3.6, ], ['I', 'II', 'III']):
A    12
B     3
C     4
dtype: int64
```

---
#### 常用运算
```Python
from pandas import Series

s1 = Series(range(4))
s2 = Series({'语文': 90, '数学': 87, '英语': 67, '程序设计': 78})
s3 = Series({'语文': 20, '数学': 80, '英语': 67, '程序设计': 78, 'w': 23})
print("s1:\n{0}\ns2:\n{1}\ns3:\n{2}".format(s1, s2, s3))
s1:
0    0
1    1
2    2
3    3
dtype: int64
s2:
语文      90
数学      87
英语      67
程序设计    78
dtype: int64
s3:
语文      20
数学      80
英语      67
程序设计    78
w       23
dtype: int64
```
- 同索引等长的Series可进行算术运算
    ```Python
    print("s2 - s3:\n{0}\ns2 + s3:\n{1}\ns2 * s3:\n{2}\ns2 / s3:\n{3}".format(s2 - s3, s2 + s3, s2 * s3, s2 / s3))
    ```
    ![](../../res/img/BigDataMicroMajor/Python/Pandas.Series-四则运算.png)
    - 没有的部分自动补齐`NotANumber`
- 不同索引运算其相对应的值控制为NaN
    ```python
    print("s1+s2:\n{0}".format(s1 + s2))
    ```
    ![](../../res/img/BigDataMicroMajor/Python/Pandas.Series-NAN.png)
- Series对象与标量进行算术运算
    ```python
    print("s3*2:\n{0}\ns3**0.5:\n{1}".format(s3 * 2, s3 ** 0.5))
    ```
    ![](../../res/img/BigDataMicroMajor/Python/Pandas.Series-Series对象与标量进行算术运算.png)
- Series对象的关系运算
    ```python
    print("\ns2[s2 >= 80]:\n{0}".format(s2[s2 >= 80]))
    ```
    ![](../../res/img/BigDataMicroMajor/Python/Pandas.Series-Series对象的关系运算.png)
- 计算Series对象的中值
    ```Python
    print("\ns3.median():\n{0}".format(s3.median()))
    ```
    ![](../../res/img/BigDataMicroMajor/Python/Pandas.Series-计算Series对象的中值.png)
- 计算s2中最小的1个值
    ```Python
    print('\ns2.nsmallest(1)：\n', s2.nsmallest(1))
    ```
    ![](../../res/img/BigDataMicroMajor/Python/Pandas.Series-计算s2中最小的1个值.png)
- 计算s2中最大的1个值
    ```python
    print('s2.nlargest(1)：\n', s2.nlargest(1))
    ```
    ![](../../res/img/BigDataMicroMajor/Python/Pandas.Series-计算s2中最大的1个值.png)

---
#### values的访问与修改
- 访问与修改都可通过索引、切片实现。
```Python
from pandas import Series

s1 = Series(range(1, 11))
s2 = Series({'语文': 90, '数学': 87, '英语': 67, '程序设计': 78})
```
- 通过索引，切片访问Series的value
    ```python 
    print("s1[4] : {0}\ns2['英语'] : {1}".format(s1[4], s2['英语']))
    print("s1[1:4]:\n{0}\n"
        "s2[1:3]:\n{1}".format(s1[1:4], s2[1:3]))
    ```
    ![](../../res/img/BigDataMicroMajor/Python/Pandas.Series-通过索引，切片访问Series的value.png)
- 通过索引修改Series的value，注意字典的键为索引
    ```python 
    s2['程序设计'] = 89
    print("s2:\n{0}".format(s2))
    ```
    ![](../../res/img/BigDataMicroMajor/Python/Pandas.Series-通过索引修改Series的value，注意字典的键为索引.png)

---
