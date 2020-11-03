# 前言
- 上机作业的提交方式
    - 把源程序代码（.cpp文件）和程序正确运行的界面截图，以附件形式发到我的邮箱：jiangz@ujs.edu.cn.
      - 邮件标题：完整学号+姓名
> 注意：邮件标题必须按照指定方式命名！！！否则不予统计成绩！
# 上机2
## 题目1
将一个三位数(假设个位数不为0)的个位数和百位数进行交换;该数通过键盘输入,请编写代码实现
```C++
	int num;
	cout << "请输入一个三位数: ";
	cin >> num;
	num = (num % 10) * 100 + (num / 10 - (num / 100) * 10)*10 + (num / 100);
	cout << "经交换后输出的数为:" << num << endl;
```
- / 整除(两个整型数据)
  - $624/100=6$
- % 取余
  - $624\%100=24$

## 题目2
```C++
#include "cmath"
#include <iostream>
using namespace std;
int main()
{
	double a, b, c, d;
	cout << "请依次输入多项式的系数abc:  " ;
	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	cout << "一元二次方程"<<a<<"x**2+"<<b<<"x+"<<c<<"的解为:" << endl;
	if (a == 0)
		cout << "x=" << -c / b << endl;
	else {
		if (d >= 0)
			cout << "x1=" << (-b + sqrt(d)) / (2 * a) << "  x2=" << (-b - sqrt(d)) / (2 * a) << endl;
		else
			cout << "x1=" << (-b) / (2 * a) << "+" << (sqrt(-d)) / (2 * a) << "i" << endl << "x2=" << (-b) / (2 * a) << "-" << (sqrt(-d)) / (2 * a) << "i" << endl;
	}
	system("pause");
	return 0;
}
```
1. 设计一个程序，从键盘输入十位同学的成绩（0-100），计算其中及格学生的平均成绩。
```C++
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	double score[10];	// 存放十名学生成绩
	int countPass = 0;	// 统计及格学生个数
	double sumPass = 0;	// 统计及格学生总分
	double averPass;	// 及格学生均分
	cout << "请依次输入十名同学的成绩:" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> score[i];
		if (score[i] >= 60) {
			countPass++;
			sumPass += score[i];
		}
	}
	averPass = sumPass / countPass;
	cout << "10名同学中有" << countPass << "位学生及格,总分为:" << sumPass << "及格学生均分为:" << setprecision(4) << averPass << endl;
	system("pause");
	return 0;
}
```
- setpresision(i)
  - ```C++
    #include<iomainp>
    ```
  - 保留有效位数i位
    - > 注意:不是保留小数后有效位数而是整体的有效位数

---
# 上机3
- 时间:
  - 周四910节课(6点开始)
- 内容:
  - 课堂练习12,13,14题
## 题目1(T12,100内各数字之积小于各数字之和)
```C
void main()
{
	int i,mul,sum ,t;
	for(i=1;i<100;i++)
	{
		t=i;   
 mul=1__  ;  sum=0    	;	
while(t!=0)
		{
			mul*=t%10;
			sum+=t%10;
			   t/=10;       		
         }
		if(mul<sum) printf(“%d  “,i);
}
```

## 题目2(T13)
- 13.编写程序，求
  - $x=1-\frac{1}{22} + \frac{1}{333} - \frac{1}{4444} + \frac{1}{55555} ……+ \frac{1}{999999999}$

## 题目3(T14)类水仙花数
- 14.数学中有一种水仙花数（3位数），它本身恰好等于其各位数值的立方和，
  - 比如：$153 = 1^3 + 5^3 + 7^3$ 
    - 153便是水仙花数。
- 那么是否存在这样的四位数，它本身也恰好等于其各位数值的四次方之和。
	- 试编程求这样的四位数。


## 题目4(T15)
- 15.每个苹果0.8元，第一天买2个苹果，
  - 第二天买前一天的2倍，
  - 直至购买的苹果个数达到不超过100的最大值。
  - 编写程序求每天平均花多少钱？