#include<iostream>
#include<cmath>
using namespace std;

long long factorial(int num) {
	int i;					// 循环计数器
	long long answer = 1;	// 0的阶乘是1
	for (i = 1; i <= num; i++) {
			answer *= i;
	}
	return answer;
}


long double eExponential(double num) {
	long double answer = 0;
	long double current_num;
	int i = 0;			// 计数器
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
	double num;			// 待输入数据
	int break_or_not;	// 是否继续输入
	while (true) {
		cout << "请输入指数:";
		cin >> num;	// cin自带换行
		cout << "以该数为指数的自然指数的值约为:" << eExponential(num) << endl;
		cout << "输入0并回车以退出程序,输入其他数据并回车以继续输入:";
		cin >> break_or_not;
		if (break_or_not == 0)
			break;
	}
	system("pause");
	return 0;
}