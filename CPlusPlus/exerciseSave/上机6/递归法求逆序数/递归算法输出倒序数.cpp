#include <cmath>
#include <iostream>
using namespace std;

int reverseNum_assist(int x, int x_reverse) {
	if (x != 0) {
		x_reverse = x_reverse * 10 + x % 10;
		x = x / 10;
		reverseNum_assist(x, x_reverse);
	}
	else
		return x_reverse;
}


int reverseNum(int x) {
	int	x_reverse = x % 10;	// 取出x的最低位
	x = x / 10;				// x去掉最低位
	return reverseNum_assist(x, x_reverse);
}


int main()
{
	int x;
	cout << "请输入一个整数: ";
	cin >> x;
	cout << "该数的逆序数为:" << reverseNum(x) << endl;
	system("pause");
	return 0;
}
