#include"GoldbachConjecture.h"

#include<iostream>
using namespace std;

int main() {
	// ����ǰ��˵��
	cout << "��������֤,��������Ϊint,�뾡��ʹ��ʮλ���ڵ�������֤" << endl;
	int num;			// ����������
	int break_or_not;	// �Ƿ��������
	while (1) {
		cout << "������һ������6��ż��:";
		cin >> num;	// cin�Դ�����
		if (num > 1000000000){
			cout << "�ⲻ��һ��ʮλ���ڵ�����,���򼴽��˳�" << endl;
			break;
		}
		else
			out_GoldbachConjecture(num);
		cout << "����0���س����˳�����,�����������ݲ��س��Լ�������:";
		cin >> break_or_not;
		if (break_or_not == 0)
			break;
	}
	system("pause");
	return 0;
}