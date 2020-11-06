#include<iostream>
using namespace std;

int main()
{
	int i;			// 计数器
	int mul, sum;	// 各位之积/和
	int t;			// i的临时容器
	cout << "100以内满足“各位数字之积小于数字之和”的整数如下:" << endl;
	for (i = 1; i < 100; i++)	// 遍历1 -> 100
	{
		t = i;					// 临时取出当前遍历数i
		mul = 1;  sum = 0;		// 初始化乘积,和
		while (t != 0)	
		{
			mul *= t % 10;		// 取出当前最低位做乘
			sum += t % 10;		// 取出当前最低位做和
			t /= 10;			// 舍弃当前最低位
		}
		if (mul < sum)
			cout << i << " ";
	}
	system("pause");
	return 0;
}