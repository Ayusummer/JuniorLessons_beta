#pragma once
// 有头结点的双向循环列表
#include<iostream>
using namespace std;

template <class T>
class List;	// 前向引用,用于声明友元

// 结点类
template <class T>
class ListNode {
	T valueLN;
public:
	ListNode<T>* nextLN;
	ListNode<T>* priorLN;
	ListNode() {			// 空构造函数,用于创建头结点
		valueLN = NULL;
		nextLN = NULL;
		priorLN = NULL;
	}
	
	ListNode(T valueT){		// 含参构造函数,用于创建普通结点
		valueLN = valueT;
		nextLN = NULL;
		priorLN = NULL;
	}
	T getValueLN() {		// 获取结点数据值
		return valueLN;
	}
	friend class List<T>;
};

// 链表类
template <class T>
class List {
public:
	ListNode<T> headLN;
	List() {		// 空构造函数,用于创建空链表
		headLN = ListNode<T>();
		headLN.nextLN = &headLN;
		headLN.priorLN = &headLN;
	}
	void addLN(T valueLN) {	// 加入一个结点
		ListNode<T>* LN = new ListNode<T>(valueLN);
		LN->priorLN = headLN.priorLN;
		LN->nextLN = &headLN;
		headLN.priorLN->nextLN = LN;
		headLN.priorLN = LN;
	}
};
