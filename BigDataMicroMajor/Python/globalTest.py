list_x = [3, 8, 2, 6, 8]
list_w = [2000, 3000, 2500, 1000, 1500]
list_c = [0.050, 0.050, 0.075, 0.075, 0.075]
wc = map(lambda w, c: w * c, list_c, list_w)
wcx = map(lambda w, c, x: w * c * x, list_c, list_w, list_x)
a = sum(wcx)
b = sum(wc)
print(type(a), type(b))
x1 = a / b
print(x1)
print(sum(wc), type(sum(wcx)), type(sum(wc)))
x1 = sum(wcx) / sum(wc)
print(x1)