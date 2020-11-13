#include<iostream>
using namespace std;

int main()
{
	int lineNum;				// 菱形行数
	int correctInput = 0;		// 正确输入
	cout << "请输入一个奇数作为菱形的行数: ";
	while (!correctInput) {		// 当输入不正确时选择0重新输入或2放弃
		try {
			cin >> lineNum;
			int functSelect;	// 选择
			if (lineNum % 2 != 1) {
				cout << "该输入并非奇数,输入下列选项并回车以选择相应功能:\n0:重新输入奇数行数;1:退出" << endl;
				cin >> functSelect;
				if (functSelect == 1)
					correctInput = 2;		// 放弃
				else if (functSelect == 0) {}	// 什么都不做,correctInput仍为0,继续循环
				else {
					cout << "您选择的功能不存在,程序已退出" << endl;
					correctInput = 2;	// 相当于放弃输入
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