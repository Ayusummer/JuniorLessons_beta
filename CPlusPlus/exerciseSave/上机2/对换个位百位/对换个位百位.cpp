#include<iostream>
using namespace std;

int main() {
	int num;
	cout << "������һ����λ��: ";
	cin >> num;
	num = (num % 10) * 100 + (num / 10 - (num / 100) * 10)*10 + (num / 100);
	cout << "���������������Ϊ:" << num << endl;
	system("pause");
	return 0;
}