#include "GoldbachConjecture.h"
#include<iostream>
#include<cmath>
using namespace std;

// �ж������Ƿ�Ϊ�����������жϱ�ʶ
bool isPrime(int num)
{
    /* ��2->sqrt(num),���γ�num,���������򷵻�false,��ʾ������������
        ѭ��ִ����δ�����򷵻�true,��ʾ����Ϊ���� */
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

// �ж������Ƿ�Ϊ�����������жϱ�ʶ
bool isPrimePro(int num){
    /* ������Ϊ����,���Ǹ�����2��3,��������ض���6�ı�������(����ʽ�ֽⲻ�ѿ���) */
    if (num == 1)
        return 0;
    if (num == 2 || num == 3)
        return 1;
    if (num % 6 != 1 && num % 6 != 5)
        return 0;
    int tmp = sqrt(num);
    /* �����ж�6i, 6i+2, 6i+4,��Ϊ��Щ����ż��,��numΪ����
        �����ж� 6i+3 ��Ϊ num ���ܱ���������num�����ܱ�3����
            ���� num = 6k +- 1 ,�����ܱ�3����,��num�����ܱ�6i+3����*/
    for (int i = 5; i <= tmp; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    return 1;
}


// ���һ������6��ż����������������ַ���
void out_GoldbachConjecture(int num){
    if (num % 2 == 1 || num <= 6)
        cout << "�ⲻ��һ������6��ż��" << endl;
    else {
        if (isPrimePro(num - 3))
            cout << num << "=3+" << num - 3 << endl;
        else {
            for (int i = 5; i <= num / 2; i += 6) {
                if (isPrimePro(i) && isPrimePro(num - i)){
                    cout << num << "=" << i << "+" << num - i << endl;
                    break;  // ��֤ʽ����,�ҵ�һ������
                }
                else if (isPrimePro(i + 2) && isPrimePro(num - i - 2)){
                    cout << num << "=" << i + 2 << "+" << num - i - 2 << endl;
                    break;  // ����ͬ��
                }
                else{
                    // do nothing
                }
            }  
        }
    }
}


