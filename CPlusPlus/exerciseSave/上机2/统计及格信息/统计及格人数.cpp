#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	double score[10];	// 存放十名学生成绩
	int countPass = 0;	// 统计及格学生个数
	double sumPass = 0;	// 统计及格学生总分
	double averPass;	// 及格学生均分
	cout << "请依次输入十名同学的成绩:" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> score[i];
		if (score[i] >= 60) {
			countPass++;
			sumPass += score[i];
		}
	}
	averPass = sumPass / countPass;
	cout << "10名同学中有" << countPass << "位学生及格,总分为:" << sumPass << "及格学生均分为:" << setprecision(4) << averPass << endl;
	system("pause");
	return 0;
}