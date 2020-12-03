// f(x) = x**3 + x**2 - 3x - 3 = (x + 1)(x**2 - 3)

#include <cmath>
#include <iostream>
using namespace std;

double f(double x) {
	return x * x * x + x * x - 3 * x - 3;
}

double zeros_correctInput(double a, double b) {
	double x = (a + b) / 2;
	if (f(x) == 0 or fabs(a - b) < pow(10, -6))
		return x;
	else if (f(x) * f(a) < 0)
		return zeros_correctInput(a, x);
	else
		return zeros_correctInput(x, b);
}



int main() {
	int a, b;
	cout << "请输入方程 x**3 + x**2 - 3x - 3 含零点的一个区间的左右端点(中间用空格隔开): ";
	while (true) {
		cin >> a >> b;
		if (f(a) * f(b) < 0) {
			cout << "该方程的一个解为:" << zeros_correctInput(a, b) << endl;
			break;
		}
		else {
			cout << "给入区间内无法确定有无零点,请重新输入区间左右端点(Ctrl+C以退出):";
		}
	}

	system("pause");
	return 0;
}
