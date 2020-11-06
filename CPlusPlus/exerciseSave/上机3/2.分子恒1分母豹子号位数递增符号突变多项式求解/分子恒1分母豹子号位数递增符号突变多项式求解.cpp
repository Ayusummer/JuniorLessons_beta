#include<iostream>
using namespace std;

int main()
{
	double x = 0;				// 多项式结果
	for (int i = 1; i < 10; i++) {
		double denominator = 0;	// 当前项分母(用double是为了让1/denominator为double类型数据)
		for (int t = 1; t <= i;t++) {
			denominator += i * pow(10, t - 1);
		}
		x += (1 / (denominator)) * pow(-1, i + 1);
	}
	cout << "多项式之和为: " << x << endl;
	system("pause");
	return 0;
}