#include<iostream>
using namespace std;

int main()
{
	int lineNum;				// ��������
	int correctInput = 0;		// ��ȷ����
	cout << "������һ��������Ϊ���ε�����: ";
	while (!correctInput) {		// �����벻��ȷʱѡ��0���������2����
		try {
			cin >> lineNum;
			int functSelect;	// ѡ��
			if (lineNum % 2 != 1) {
				cout << "�����벢������,��������ѡ��س���ѡ����Ӧ����:\n0:����������������;1:�˳�" << endl;
				cin >> functSelect;
				if (functSelect == 1)
					correctInput = 2;		// ����
				else if (functSelect == 0) {}	// ʲô������,correctInput��Ϊ0,����ѭ��
				else {
					cout << "��ѡ��Ĺ��ܲ�����,�������˳�" << endl;
					correctInput = 2;	// �൱�ڷ�������
				}
			}
			else correctInput = 1;
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
	}
	if(correctInput == 1){
		for (int b = 1; b <= (lineNum + 1) / 2; b++)
		{
			for (int c = 1; c <= (lineNum + 1) / 2 - b; c++)
				cout << " ";
			for (int c = 1; c <= (b * 2) - 1; c++)
				cout << "*";
			cout << endl;
		}
		for (int b = (lineNum + 1) / 2 + 1; b <= lineNum; b++)
		{
			for (int c = 1; c <= b - (lineNum + 1) / 2; c++)
				cout << " ";
			for (int c = 1; c <= (lineNum + 1 - b) * 2 - 1; c++)
				cout << "*";
			cout << endl;
		}
	}
	system("pause");
	return 0;
}