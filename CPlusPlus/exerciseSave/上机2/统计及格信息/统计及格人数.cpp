#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	double score[10];	// ���ʮ��ѧ���ɼ�
	int countPass = 0;	// ͳ�Ƽ���ѧ������
	double sumPass = 0;	// ͳ�Ƽ���ѧ���ܷ�
	double averPass;	// ����ѧ������
	cout << "����������ʮ��ͬѧ�ĳɼ�:" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> score[i];
		if (score[i] >= 60) {
			countPass++;
			sumPass += score[i];
		}
	}
	averPass = sumPass / countPass;
	cout << "10��ͬѧ����" << countPass << "λѧ������,�ܷ�Ϊ:" << sumPass << "����ѧ������Ϊ:" << setprecision(4) << averPass << endl;
	system("pause");
	return 0;
}