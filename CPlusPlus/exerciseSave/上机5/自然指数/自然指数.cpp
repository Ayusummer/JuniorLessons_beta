#include<iostream>
#include<cmath>
using namespace std;

long long factorial(int num) {
	int i;					// ѭ��������
	long long answer = 1;	// 0�Ľ׳���1
	for (i = 1; i <= num; i++) {
			answer *= i;
	}
	return answer;
}


long double eExponential(double num) {
	long double answer = 0;
	long double current_num;
	int i = 0;			// ������
	while (true) {
		cout << pow(num, i) <<"   " << factorial(i) <<"    " << pow(num, i) / factorial(i) << endl;
		current_num = pow(num, i) / factorial(i);
		if (current_num < pow(10, -6)) {
			answer += current_num;
			break;
		}
		else{
			answer += current_num;
			i++;
		}
	}
	return answer;
}



int main() {
	double num;			// ����������
	int break_or_not;	// �Ƿ��������
	while (true) {
		cout << "������ָ��:";
		cin >> num;	// cin�Դ�����
		cout << "�Ը���Ϊָ������Ȼָ����ֵԼΪ:" << eExponential(num) << endl;
		cout << "����0���س����˳�����,�����������ݲ��س��Լ�������:";
		cin >> break_or_not;
		if (break_or_not == 0)
			break;
	}
	system("pause");
	return 0;
}