import numpy as np

A = np.array([1, 2, 3, 4, 5])
B = np.diag(A)
C = np.linspace(1, 50, 49, dtype=int).reshape(7, 7)
C = np.mat(C)
row = len(C)
col = len(C[0, :])
D = np.diagonal(C)  # D为C对角线上的元素,即为
D_diag = np.diag(D) # D_diag是以D为对角元素生成的方阵
E = np.diag(np.diag(C))
E_M = np.mat(E)
F = np.tril(C)
F_1 = np.tril(C, -1)
F1 = np.triu(C)
F1_1 = np.triu(C, 1)
print(F1_1)

