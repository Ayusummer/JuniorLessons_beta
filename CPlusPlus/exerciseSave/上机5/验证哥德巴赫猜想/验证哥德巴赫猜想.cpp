#include"GoldbachConjecture.h"

#include<iostream>
using namespace std;

int main() {
	// 程序前置说明
	cout << "轻量型验证,数据类型为int,请尽量使用十位以内的数据验证" << endl;
	int num;			// 待输入数据
	int break_or_not;	// 是否继续输入
	while (1) {
		cout << "请输入一个大于6的偶数:";
		cin >> num;	// cin自带换行
		if (num > 1000000000){
			cout << "这不是一个十位以内的数据,程序即将退出" << endl;
			break;
		}
		else
			out_GoldbachConjecture(num);
		cout << "输入0并回车以退出程序,输入其他数据并回车以继续输入:";
		cin >> break_or_not;
		if (break_or_not == 0)
			break;
	}
	system("pause");
	return 0;
}