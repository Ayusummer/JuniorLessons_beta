#include<iostream>
using namespace std;

int main()
{
	int i;			// ������
	int mul, sum;	// ��λ֮��/��
	int t;			// i����ʱ����
	cout << "100�������㡰��λ����֮��С������֮�͡�����������:" << endl;
	for (i = 1; i < 100; i++)	// ����1 -> 100
	{
		t = i;					// ��ʱȡ����ǰ������i
		mul = 1;  sum = 0;		// ��ʼ���˻�,��
		while (t != 0)	
		{
			mul *= t % 10;		// ȡ����ǰ���λ����
			sum += t % 10;		// ȡ����ǰ���λ����
			t /= 10;			// ������ǰ���λ
		}
		if (mul < sum)
			cout << i << " ";
	}
	system("pause");
	return 0;
}