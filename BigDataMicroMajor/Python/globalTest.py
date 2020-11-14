import numpy as np

A = np.mat([(1, 2, -1), (3, 1, 0), (-1, 0, -2)])
C = np.mat([[1, 2], [3, 4], [5, 6]])
D = np.mat([[11, 22, 33], [44, 55, 66], [77, 88, 99]])
print("A×3:\n{0}".format(A*3))
print("A+D:\n{0}\nA*C:\n{1}\n".format(A+D, A*C))
