# 前言
## 关于点名
- 共16次课,5分
- 课堂抽查
- 得分=$\frac{抽查到的到课次数}{抽查到的总次数}$
- 第12周开始点名送分
  - 没到扣分

---
## 关于作业
- 每章一次作业
- 每次作业都有报告,需要演示

### 作业抽查
- 随机抽查,不会就全部0分,会就直接满分

---
## 关于考题
- 时间复杂度递推公式必考
- 流水作业调度是最优调度的证明必考
- 矩阵连乘和0-1背包问题选考一题
  - 要求画出图解

---
# 第2章 递归与分治策略
## 2.1 递归的概念
### 递归的定义
- 若一个对象部分地包含它自己,或者用它自己给自己定义,则称这个对象是递归的;
- 若一个过程**直接地或间接地调用自己**,则称这个过程是递归的过程;

## 2.2 分治法的基本思想
- 将要求解的**较大规模**的问题分割成**若干个**更小规模的子问题。
- 对这**若干子问题**分别求解。如果子问题的规模仍然不够小，则再划分为若干个子问题，如此**递归**的进行下去，直到问题规模足够小，很容易求出其解为止。
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_e4d691d94b07753a52333888c1de0218.png)

---
### 算法总体思想
- 将求出的小规模的问题的解合并为一个更大规模的问题的解，自底向上逐步求出原来问题的解。
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_f330c38443df2abd2fc340ce293af352.png)
- 分治法的设计思想是，将一个难以直接解决的大问题，分割成一些规模较小的相同问题，以便各个击破，分而治之。
  - 凡治众如治寡，分数是也。
							----孙子兵法
### 分治策略的基本思想
1. 将原始问题划分或者归结为规模较小的子问题
2. 递归或迭代求解每个子问题
3. 将子问题的解综合得到原问题的解

### 合并排序
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_514f48cd890853bb801533402b02982d.png)

### 分治法的基本步骤
```Java
public static void  mergeSort(Comparable a[],int left,int right){
    if(left == right)           // 解决小规模问题
    else if(left < right){      //至少有两个元素
        int i = (left+right)/2; //取中点,分解问题
        mergeSort(a, left, i);
        mergeSort(a, i+1, right);
        merge(a, b, left, i, right);    //合并数组到b
        //复制回数组a,将各子问题的解合并为原问题的解
        copy(a, b, left, right);        
    }
}
```
- 复杂度分析
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_02c411722269e9623b22fa2ec9ff33fa.png)

```Java
divide-and-conquer(P){
    if ( |P| <= n0) adhoc(P);   //解决小规模的问题
    divide P into smaller subinstances P1,P2,...,Pk；//分解问题
    for (i=1,i<=k,i++)
      yi=divide-and-conquer(Pi);  //递归的解各子问题
    return merge(y1,...,yk);  //将各子问题的解合并为原问题的解
}
```
### 分治法的复杂性分析
- 一个分治法将规模为n的问题分成k个规模均为n／m的子问题去解。设分解阀值n0=1，且adhoc解规模为1的问题耗费1个单位时间,设将原问题分解为k个子问题以及用merge将k个子问题的解合并为原问题的解需用f(n)个单位时间。用T(n)表示该分治法解规模为|P|=n的问题所需的计算时间，则有:
- ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_357520b88b08edeee9fdd55d0fd191d0.png)
- 通过迭代法求得方程的解：
- ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_469396c05224c1f0fec839c8dbc14fc1.png)
- 注意：递归方程及其解只给出n等于m的方幂时T(n)的值，但是如果认为T(n)足够平滑，那么由n等于m的方幂时T(n)的值可以估计T(n)的增长速度。通常假定T(n)是单调上升的，从而当mi≤n<mi+1时，T(mi)≤T(n)<T(mi+1)。 
- 人们从大量实践中发现，在用分治法设计算法时，最好使子问题的规模大致相同。即将一个问题分成**大小相等的k个子问题**的处理方法是行之有效的。这种使子问题**规模大致相等**的做法是出自一种**平衡(balancing)子问题**的思想，它几乎总是比子问题规模不等的做法要好。

### 分治法的适用条件
分治法所能解决的问题一般具有以下几个特征：
- 该问题的规模缩小到一定的程度就可以容易地解决；
- 该问题可以分解为若干个规模较小的**相同**问题，即该问题具有**最优子结构**性质
- 利用该问题分解出的子问题的解可以**合并**为该问题的解；
- 该问题所分解出的各个子问题是**相互独立**的，即子问题之间不包含公共的子问题。 
  - 这条特征涉及到分治法的效率，如果各子问题是不独立的，则分治法要做许多不必要的工作，重复地解公共的子问题，此时虽然也可用分治法，但一般用动态规划较好。
 
## 2.3 二分搜索技术
给定已按升序排好序的n个元素a[0:n-1]，现要在这n个元素中找出一特定元素x。


## 2.4 大整数的乘法问题
请设计一个**有效的算法**，可以进行**两个n位大整数**的乘法运算
- 小学的方法：O($n^2$)
  - 效率太低
- 分治法:   
X = $a \times 2 ^ \frac{n}{2} + b$    
Y = c 2n/2 + d   
XY = ac 2n + (ad+bc) 2n/2 + bd   
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_2c32d5836382e445e018310aa117ef4f.png)
- 为了降低时间复杂度，必须减少乘法的次数。
- XY = ac 2n + ((a-c)(b-d)+ac+bd) 2n/2 + bd
- ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_ca9001b61f67100857d7c2f38b48a262.png)
- 细节问题：两个XY的复杂度都是O(nlog3)，但考虑到a+c,b+d可能得到m+1位的结果，使问题的规模变大，故不选择第2种方案。    
- 如果将大整数分成更多段，用更复杂的方式把它们组合起来，将有可能得到更优的算法。
- 最终的，这个思想导致了**快速傅利叶变换**(Fast Fourier Transform)的产生。该方法也可以看作是一个复杂的分治算法，对于大整数乘法，它能在**O(nlogn)**时间内解决。
- 是否能找到**线性时间的算法？？？**目前为止还没有结果。

## 2.5 Strassen矩阵乘法
- 传统方法：O(n3)
- A和B的乘积矩阵C中的元素C[i,j]定义为:
- ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_d4162477758d9455fc1976715f91799c.png)
- 若依此定义来计算A和B的乘积矩阵C，则每计算C的一个元素C[i][j]，需要做n次乘法和n-1次加法。因此，算出矩阵C的 个元素所需的计算时间为O(n3)

## 2.6 棋盘覆盖问题
- 在一个2k×2k 个方格组成的棋盘中，**恰有一个方格**与其他方格不同，称该方格为一**特殊方格**，且称该棋盘为一**特殊棋盘**。在棋盘覆盖问题中，要用图示的**4种不同形态**的L型骨牌覆盖给定的特殊棋盘上**除特殊方格以外**的所有方格，且**任何2个L型骨牌不得重叠覆盖**。
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_eea2f899622199adb059b0d39a16cc6f.png)
> 每个L型骨牌在棋盘上的摆放位置都是有限的,所以我认为可以依次摆放四个L型骨牌
- 当**k>0**时，将2k×2k棋盘分割为4个2k-1×2k-1 子棋盘(a)所示。
- **特殊方格必位于4个较小子棋盘之一中**，**其余3个**子棋盘中无特殊方格。为了将这3个无特殊方格的子棋盘转化为特殊棋盘，可以用一个L型骨牌覆盖这3个较小棋盘的会合处，如 (b)所示，从而将原问题转化为4个较小规模的棋盘覆盖问题。递归地使用这种分割，直至棋盘简化为棋盘1×1。 
- ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_5d6e879805ce381c2c5ed41a9a2160fd.png)
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_afb19a8b4cb4156a02cf51c96dde4657.png)
- **到这里算法就结束了,设计方面要写报告作为平时作业**

## 2.9 线性时间选择
- 给定线性序集中n个元素和一个整数k，1≤k≤n，要求找出这**n**个元素中**第k小**的元素。（**比如求中位数**）
```java
private static Comparable randomizedSelect(int p,int r,int k)
   {
      if (p==r) return a[p];
      int i=randomizedpartition(p,r),
          j=i-p+1;
      if (k<=j) return randomizedSelect(p,i,k);
      else return randomizedSelect(i+1,r,k-j);
   }
```
- 在最坏情况下，算法randomizedSelect需要O(n2)计算时间但可以证明，算法randomizedSelect可以在O(n)平均时间内找出n个输入元素中的第k小元素。
- 如果能在**线性时间**内找到一个**划分基准**，使得按这个基准所划分出的**2个子数组**的长度都至少为原数组长度的**ε**倍(0<ε<1是某个正常数)，那么就可以在最坏情况下用O(n)时间完成选择任务。
  - 例如，若ε=9/10，算法递归调用所产生的子数组的长度至少缩短1/10。所以，在最坏情况下，算法所需的计算时间T(n)满足递归式T(n)≤T(9n/10)+O(n) 。由此可得T(n)=O(n)。
- 将n个输入元素划分成$\lceil n/5 \rceil$个组，每组5个元素，只可能有一个组不是5个元素。用任意一种排序算法，将每组中的元素排好序，并取出每组的中位数，共n/5个。

```Java
private static Comparable select (int p, int r, int k)
   {
      if (r-p<5) {
        //用某个简单排序算法对数组a[p:r]排序;
        bubbleSort(p,r);
        return a[p+k-1];
        }
      //将a[p+5*i]至a[p+5*i+4]的第3小元素
      //与a[p+i]交换位置;
      //找中位数的中位数，r-p-4即上面所说的n-5
      for ( int i = 0; i<=(r-p-4)/5; i++ )
      {
         int s=p+5*i,
             t=s+4;
         for (int j=0;j<3;j++) bubble(s,t-j);
         MyMath.swap(a, p+i, s+2);
      }
      Comparable x = select(p, p+(r-p-4)/5, (r-p+6)/10);
      int i=partition(p,r,x),
          j=i-p+1;
      if (k<=j) return select(p,i,k);
      else return select(i+1,r,k-j);
   }
```

---
## 分治法的适用条件  
分治法所能解决的问题一般具有以下几个特征
- 该问题的规模缩小到一定的程度就可以容易地解决；
- 该问题可以分解为若干个规模较小的相同问题，即该问题具有最优子结构性质
- 利用该问题分解出的子问题的解可以合并为该问题的解；
- 该问题所分解出的各个子问题是相互独立的，即子问题之间不包含公共的子问题。 


---
# 第3章 动态规划

## 3.8 流水作业调度
### 作业
- 证明流水作业调度满足最优调度:  
  $min \{ b_{π(i)}, a_{π(j)} \} \geq min \{ b_{π(j)}, a_{π(i)} \}$


---
## 3.9 0-1背包问题
### 例题
- 价值数组
  - v={8,10,6,3,7,2}
- 重量数组
  - w={4,6,2,2,5,1}
- 背包容量
  - C=12
- 价值/重量数组
  - $\frac{v}{M} = \{ 2, \frac{5}{3}, 3, 1.5, \frac{7}{5}, 2 \}$
- 价重比递减索引+1
  - indexVM =  {3, 1, 6, 2, 4, 5}
  - indexVMW = {2, 4, 1, 6, 2, 5}
  - 答案{3,1,6,5}
  - 价值为24

---
# 第4章 贪心算法

---
## 4.2 贪心算法的基本要素



---
## 4.5 单源最短路径


---
# 第5章 回溯法

## n后问题
- python解法1
```python
global N
N = 4


def printSolution(board):
    for i in range(N):
        for j in range(N):
            print(board[i][j], end="")
        print()
    print()


def isSafe(board, row, col):
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


def solveNQUtil(board, col):
    if col >= N:
        printSolution(board)
    else:
        for i in range(N):
            if isSafe(board, i, col):
                board[i][col] = 1
                solveNQUtil(board, col + 1)
                board[i][col] = 0
    return False


def solveNQ():
    # 写成这样更具适应性
    # board = [[0 for i in range(N)] for j in range(N)]
    board = [[0, 0, 0, 0],
             [0, 0, 0, 0],
             [0, 0, 0, 0],
             [0, 0, 0, 0]
             ]

    if not solveNQUtil(board, 0):
        print("Solution does not exist")
        return False

    printSolution(board)
    return True


if __name__ == "__main__":
    solveNQ()

# output
# 0010
# 1000
# 0001
# 0100

# 0100
# 0001
# 1000
# 0010
```