# -*- coding: utf-8 -*-
# @Time    : 2020/11/10 18:32
# @Author  : 咸鱼型233
# @File    : 3._numpyPolynomial.py
# @Software: PyCharm
# @Function: numpy求解多项式3x**3 + 2x + 5
import numpy as np

constant_array = np.array([3, 0, 2, 5])
polynomial = np.poly1d(constant_array)
print("多项式为:\n", polynomial)

x_array = np.array([1, 4, 7, 9])
print("当x取（1，4，7，9）时多项式的值为:{0}".format(polynomial(x_array)))

