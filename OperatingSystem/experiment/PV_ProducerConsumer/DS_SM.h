#pragma once
#include<iostream>
#include<string>
using namespace std;


/************************************ 进程控制块 ********************************************/
typedef struct Pcb {
	string name;		// 进程名
	char state;		    // 运行状态(阻塞,就绪,运行,完成)
	string wait_reason;	// 等待原因(两个信号量)
	int breakp;			// 断点
}Pcb, * Process;		// 定义struct Pcb 为 Pcb,Pcb*为Process

/***************************************************************************************/


/***************************** 模拟的处理器指令 ***************************************/
void P(int mutex);		// P操作
void V(int mutex);		// V操作
void put(char p);		// 将生产的产品放入缓冲区并回显当前缓冲区有多少产品
void GET(char x);		// 从缓冲区中获取一份产品
void produce(char c);	// 生产一个字符放入c中
void consume(char p);	// 消费
void GOTOL(int L);		// PC : L
void NOP();				// 空操作

/***************************************************************************************/

void init();			// 初始化程序
void scheduling();		// 处理器调度

/******************************其他函数声明***************************/


char ranChar();			// 模拟生产一份产品							
string itos(int i);		// 将整型数据转化为字符串
string generProdName();	// 生成生产者进程名
void W(int mutex);		// 调用过程的进程置为等待信号量mutex的状态
void R(int mutex);		// 释放一个等待信号量mutex的进程
void processP();		// 生产者进程
void processC();		// 消费者进程




void disp();

void bornpa();
void bornsa();
void diaodu();





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
	char produce();		// 生产操作
public:
	Producer();			// 空构造函数,用于头结点定义
	Producer(char state, char block_reason, int breakp);
	~Producer();
	friend class ProducerNode;	// 使得生产者进程结点可以访问生产者进程的私有数据
	friend class PoolProducer;	// 使得生产者进程池可以访问生产者进程的私有数据
};


// 生产者结点
class ProducerNode : public Producer {
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

/************************************ 消费者 ********************************************/

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
/***************************************************************************************/

