#include"list.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	cout << "1000以内的完数如下所示:" << endl;
	for (int i = 1; i <= 1000; i++)	// 第一个循环遍历1-1000所有的数
	{
		int sumFactor = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
				sumFactor += j;
		}
		if (sumFactor == i) {
			List<int> factorList;
			for (int k = 1; k < i; k++) {
				if (i % k == 0) {
					factorList.addLN(k);
				}
			}
			cout << i << "->";
			ListNode<int>* p = factorList.headLN.nextLN;
			while (p != factorList.headLN.priorLN) {
				cout << p->getValueLN() << ",";
				p = p->nextLN;
			}
			cout << p->getValueLN() << endl;

		}
			
	}
	system("pause");
	return 0;
}