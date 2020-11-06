#include<iostream>
using namespace std;

int main()
{
	int t;			// 计数器的临时容器
	for (int i = 1000; i < 10000; i++) {
		t = i;
		int sumPow = 0;	// 当前数各位4次方之和
		while (t != 0) {
			sumPow += pow(t % 10, 4);
			t /= 10;	// 舍弃最低位
		}
		if (i == sumPow)
			cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}