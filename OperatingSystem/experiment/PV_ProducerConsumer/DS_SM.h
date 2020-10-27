#pragma once
#include<iostream>
#include<string>
using namespace std;

class PoolProducer;		// 前向引用;生产者进程池
class PoolConsumer;		// 前向引用;消费者进程池
class ProducerNode;		// 前向引用;生产者进程结点
class ConsumerNode;		// 前向引用;消费者进程结点


/************************************ 生产者 ********************************************/
// 生产者进程的声明
class Producer {
	string name;		// 进程名
	char state;			// 运行状态
	char block_reason;	// 阻塞原因
	int breakp;			// 断点保护
	void produce();		// 生产操作
public:
	Producer();			// 空构造函数,用于头结点定义
	Producer(char state, char block_reason, int breakp);
	~Producer();
	friend class ProducerNode;	// 使得生产者进程结点可以访问生产者进程的私有数据
	friend class PoolProducer;	// 使得生产者进程池可以访问生产者进程的私有数据
};


// 生产者结点
class ProducerNode : public Producer{
	ProducerNode* priorPN;	// 指向前一个生产者结点的指针
	ProducerNode* nextPN;	// 指向后一个生产者结点的指针
public:
	// 构造函数
	ProducerNode();		// 空构造函数(用于头结点定义)
	ProducerNode(char state, char block_reason, int breakp);
	~ProducerNode();
	void P(int s);					// p操作原语(返回类型为当前的运行状态的类型)
	void V(int s);					// v操作原语
	friend class PoolProducer;	// 使得生产者进程池可以访问生产者进程结点的数据
};


// 生产者进程双向循环列表
class PoolProducer {
	ProducerNode* headPN;			// 头结点
public:
	PoolProducer();					// 空构造函数
	void addPN(ProducerNode* p);	// 加入一个生产者进程结点
};

/***************************************************************************************/


// 消费者进程的声明
class Consumer {
	string name;		// 进程名
	char state;			// 运行状态
	char block_reason;	// 阻塞原因
	int breakp;			// 断点保护
	void consume();		// 消费操作
public:
	Consumer(char state, char block_reason, int breakp);
	~Consumer();
	friend class PoolConsumer;	// 使得消费者进程池可以访问消费者进程的数据
};

// 消费者结点
class ConsumerNode : public Consumer {
	Consumer* priorCN;	// 指向前一个生产者结点的指针
	Consumer* nextCN;	// 指向后一个生产者结点的指针
	ConsumerNode(string name, char state, char block_reason, int breakp);
	~ConsumerNode();
	friend class PoolConsumer;	// 使得消费者进程池可以访问消费者进程结点的数据
};



// 消费者进程池
class PoolConsumer {
	ConsumerNode* headCN;			// 头结点
	ConsumerNode* currentCN;		// 当前结点(最后一个在运行的结点)
public:
	PoolConsumer();					// 空构造函数
	void addCN(ConsumerNode* p);	// 加入一个消费者进程结点
	void delCN(ConsumerNode* p);	// 删除一个消费者进程结点
	void P(int s);					// p操作原语(返回类型为当前的运行状态的类型)
	void V(int s);					// v操作原语
};

/******************************其他函数声明***************************/
char ranChar();		// 模拟生产一份产品							
string itos(int i);	// 将整型数据转化为字符串
string generProdName();	// 生成生产者进程名

void put();
void get();
void gotol();
void nop();
void disp();
void init();
void bornpa();
void bornsa();
void diaodu();








