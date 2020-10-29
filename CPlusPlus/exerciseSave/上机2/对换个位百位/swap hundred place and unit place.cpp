//TEST£ºWrite a program£¬input a three-figure number£¬exchange its hundred place and unit place.
#include<iostream>
using namespace std;
int main()
{
	int i;
	cout << "please input a three-figure number: " << endl;
	cin >> i;
	cout << "loading..." << endl;
	i = (i % 10) * 100 + (i / 10 - (i / 100) * 10) * 10 + (i / 100);
	/*
	(i % 10) * 100:
	hundreds place changed to the unit: i%10 save to the unit at first step, then mutiply 100 times, changed to hundred place.
	(i / 10 - (i / 100) * 10) * 10:
	changed the hundred place of initial number to decade place. And because of the input function of i is "int",so the result is an integer.
	After that minus i divide 100 mutiply 10, for minus the original unit number, then the total result mutiply 10 get the decade place integer number.
	i/100 we get unit part.

	EXAMPLE: we input i as 521
	(i%10)*100 we got 1 as remainder of arithmetic, mutiplied 100 times we got 100.
	i/10 if we caculate by normal pattern, we will get 52.1, but now by the "int", we got 52 as result.
	(i/100)*10 the same as i/10, we got 5 at first, after mutiplied 10 times we got 50.
	(i / 10 - (i / 100) * 10) * 10this part's final result=(52-50)*10=2*10=20
	i/100 we got 5.
	At last we put them together to complete this combo:100+20+5=125.
	It can work! so we have successed.
	*/
	cout << "The result of swap is: " << i << endl;
	system("pause");
	return 0;
}