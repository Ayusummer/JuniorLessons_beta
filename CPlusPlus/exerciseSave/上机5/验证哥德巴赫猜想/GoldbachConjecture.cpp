#include "GoldbachConjecture.h"
#include<iostream>
#include<cmath>
using namespace std;

// 判断数字是否为素数并返回判断标识
bool isPrime(int num)
{
    /* 从2->sqrt(num),依次除num,若能整除则返回false,表示该数不是素数
        循环执行完未返回则返回true,表示该数为素数 */
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

// 判断数字是否为素数并返回判断标识
bool isPrimePro(int num){
    /* 若该数为素数,除非该数是2或3,否则该数必定与6的倍数相邻(用因式分解不难看出) */
    if (num == 1)
        return 0;
    if (num == 2 || num == 3)
        return 1;
    if (num % 6 != 1 && num % 6 != 5)
        return 0;
    int tmp = sqrt(num);
    /* 不用判断6i, 6i+2, 6i+4,因为这些都是偶数,而num为奇数
        不用判断 6i+3 因为 num 若能被其整除则num至少能被3整除
            但是 num = 6k +- 1 ,不可能被3整除,故num不可能被6i+3整除*/
    for (int i = 5; i <= tmp; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    return 1;
}


// 输出一个大于6的偶数由两个素数求和字符串
void out_GoldbachConjecture(int num){
    if (num % 2 == 1 || num <= 6)
        cout << "这不是一个大于6的偶数" << endl;
    else {
        if (isPrimePro(num - 3))
            cout << num << "=3+" << num - 3 << endl;
        else {
            for (int i = 5; i <= num / 2; i += 6) {
                if (isPrimePro(i) && isPrimePro(num - i)){
                    cout << num << "=" << i << "+" << num - i << endl;
                    break;  // 验证式函数,找到一个即可
                }
                else if (isPrimePro(i + 2) && isPrimePro(num - i - 2)){
                    cout << num << "=" << i + 2 << "+" << num - i - 2 << endl;
                    break;  // 理由同上
                }
                else{
                    // do nothing
                }
            }  
        }
    }
}


