#include<iostream>
using namespace std;

int main()
{
	int t;			// ����������ʱ����
	for (int i = 1000; i < 10000; i++) {
		t = i;
		int sumPow = 0;	// ��ǰ����λ4�η�֮��
		while (t != 0) {
			sumPow += pow(t % 10, 4);
			t /= 10;	// �������λ
		}
		if (i == sumPow)
			cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}