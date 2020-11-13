#pragma once
// ��ͷ����˫��ѭ���б�
#include<iostream>
using namespace std;

template <class T>
class List;	// ǰ������,����������Ԫ

// �����
template <class T>
class ListNode {
	T valueLN;
public:
	ListNode<T>* nextLN;
	ListNode<T>* priorLN;
	ListNode() {			// �չ��캯��,���ڴ���ͷ���
		valueLN = NULL;
		nextLN = NULL;
		priorLN = NULL;
	}
	
	ListNode(T valueT){		// ���ι��캯��,���ڴ�����ͨ���
		valueLN = valueT;
		nextLN = NULL;
		priorLN = NULL;
	}
	T getValueLN() {		// ��ȡ�������ֵ
		return valueLN;
	}
	friend class List<T>;
};

// ������
template <class T>
class List {
public:
	ListNode<T> headLN;
	List() {		// �չ��캯��,���ڴ���������
		headLN = ListNode<T>();
		headLN.nextLN = &headLN;
		headLN.priorLN = &headLN;
	}
	void addLN(T valueLN) {	// ����һ�����
		ListNode<T>* LN = new ListNode<T>(valueLN);
		LN->priorLN = headLN.priorLN;
		LN->nextLN = &headLN;
		headLN.priorLN->nextLN = LN;
		headLN.priorLN = LN;
	}
};
