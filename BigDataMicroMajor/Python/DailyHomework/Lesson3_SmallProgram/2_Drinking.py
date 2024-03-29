# 李白街上走，提壶去买酒。遇店加一倍，见花喝一斗。店不相邻开，花不成双长。三遇店和花，喝光壶中酒。请问此壶中，原有多少酒？
# 设计思想：要计算酒壶中原有多少酒，可以从后向前倒推，最后喝完为0，往前遇到鲜花加1斗，再往前遇到酒店减为一半，如此操作三次之后，得到的数字即为初始状态时酒的数量。
# 参考源程序：
wine = 0                # 酒已喝完
for _ in range(3):
    wine += 1           # 遇到花喝一斗,倒退反一斗
    wine /= 2
print('酒壶中原有的酒:', wine, "斗")
