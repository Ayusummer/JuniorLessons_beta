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