#include<iostream>
using namespace std;

int main()
{
	double x = 0;				// ����ʽ���
	for (int i = 1; i < 10; i++) {
		double denominator = 0;	// ��ǰ���ĸ(��double��Ϊ����1/denominatorΪdouble��������)
		for (int t = 1; t <= i;t++) {
			denominator += i * pow(10, t - 1);
		}
		x += (1 / (denominator)) * pow(-1, i + 1);
	}
	cout << "����ʽ֮��Ϊ: " << x << endl;
	system("pause");
	return 0;
}