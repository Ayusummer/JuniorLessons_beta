#include"DS_SM.h"
#include<iostream>
#include<string>		// 用于生产者消费者的字符串命名
#include<sstream>		// 用于将进程号插入到生产/消费者进程名中

#include<windows.h>		// sleep函数的依赖库
using namespace std;

const int volume_buffer = 10;	// 根据题设,缓冲区容量为10

char buffer[volume_buffer];		// 定义缓冲区
int currentSumBuffer = 0;		// 定义当前缓冲区中产品的数量
// 互斥信号量定义
int mutexP = volume_buffer;		// 生产者进程互斥信号量初值为缓冲区容量
int mutexC = 0;					// 消费者进程互斥信号量初值为0
int subP = 0;					// 生产者存数组下标定义
int subC = 0;					// 消费者取数组下标定义
int PC;							// 程序计数器
int PA[5], SA[5];				// 生产/消费者模拟指令入口地址数组
Pcb producer, consumer;			// 生产者,消费者进程控制块








/************************* 模拟的处理器指令 *******************************/
// 模拟生产单位函数定义
char ranChar()
{
	char arr[10] = { 'a','b','c','d','e','f','g','h','i','j' };
	return arr[abs(rand() % 10)];
}

// 调用过程的进程置为等待信号量s的状态
void W(int mutex) {

}

// 释放一个等待信号量mutex的进程
void R(int mutex) {

}

// P操作
void P(int mutex) {
	mutex--;
	if (mutex < 0)
		W(mutex);
}

// V操作
void V(int mutex) {
	mutex++;
	if (mutex <= 0)
		R(mutex);
}

// 将生产的产品放入缓冲区并回显当前缓冲区有多少产品
void put(char p) {
	Sleep(1000);	// 程序挂起1s
	buffer[subP] = p;
	subP = (subP + 1) % 10;
	cout << "产品产出:" << p << endl;
	cout << "缓冲区中有" << ++currentSumBuffer << "个产品" << endl;
}

// 从缓冲区中获取一份产品
void GET(char x) {
	Sleep(1000);	// 模拟获取时间,程序挂起1s
	x = buffer[subC];
	subC = (subC + 1) % 10;
	cout << "已从缓冲区获得一份产品:" << x << endl;
	cout << "缓冲区中有" << --currentSumBuffer << "个产品" << endl;
}

// 生产一个字符放入c中
void produce(char c) {
	c = ranChar();
}

// 模拟消费过程
void consume(char p){
	cout << "产品" << p << "已被消费" << endl;
}

// PC : L
void GOTOL(int L) {
	PC = L;
}

// 空操作
void NOP() {}

/*************************************************************************/


// 生产者进程定义
void processP(){
	char c;
	produce(c);
	while (true){
		P(mutexP);
		put(c);
		V(mutexC);
	}
}

// 消费者进程定义
void processC(){
	char x;
	while (true){
		GET(x);
		V(mutexP);
		consume(x);
	}
}


/******************************* 初始化程序 ******************************/
void init() {
	mutexP = volume_buffer;		// 缓冲区初始空位最大值可供生产者使用
	mutexC = 0;					// 缓冲区最初无产品供消费者使用
	// 初始化生产者进程控制块数据
	producer.name = "生产者";
	producer.state = 'W';
	producer.breakp = 0;
	producer.wait_reason = "";
	// 初始化消费者进程控制块数据
	consumer.name = "消费者";
	consumer.state = 'W';
	consumer.breakp = 0;
	consumer.wait_reason = "";
	// 将现行进程设置为生产者进程并将程序计数器置零
	
	PC = 0;



	// 初始化缓冲区
	for (int k = 0; k < 10; k++) {
		buffer[k] = ' ';
	}
}

// 处理器调度
void scheduling() {

}

// 处理器调度程序
void diaodu()
{
	while ((producer.state == 'W') || (consumer.state == 'W'))
	{
		x = rand();/*x随机获得一个数*/
		x = x % 2;/*对X取于*/
		if (x == 0)/*若X等于零则执行生产者进程反之执行消费
	  者进程*/
		{
			process1 = &producer;/*process表示现行进程将现行进
		 程置为生产者进程*/
			process2 = &consumer;
		}
		else
		{
			process1 = &consumer;
			process2 = &producer;
		}
		pc = process1->breakp;
		i = pc;/*此时把PC的值付给I*/
		if ((process1->name == "p") && (process1->state == 'W'))
		{
			j = pa[i];
			pc = i + 1;
			switch (j)
			{

			case 0: s1 = P(s1); process1->breakp = pc; break;
			case 1: put(); process1->state = 'W'; process1->breakp = pc; break;
			case 2: s2 = v(s2); process1->breakp = pc; break;
			case 3: gotol(); process1->state = 'W'; process1->breakp = pc;
			}
		}
		else if ((process1->name == "c") && (process1->state == 'W'))/*执行
	  消费者进程且该进程处于就绪状态*/
		{
			process1->state = 'W';
			j = sa[i];
			pc = i + 1;
			switch (j)
			{
			case 0: s2 = P(s2); process1->breakp = pc; break;/*申请资源若没
		 有申请到则跳转*/
			case 1: get(); process1->breakp = pc; break;
			case 2: s1 = v(s1); process1->breakp = pc; break;
			case 3: gotol(); process1->state = 'W'; process1->breakp = pc;
			}
		} /*end else*/
	}/*end while*/
	printf("\nThe program is over!\n");
}



/*************************** 分割线 ********************************/
int i, j;

int m;

char c, x;


// 建立进程显示函数,用于显示当前进程
void disp() {
	printf("\n name \t state \t why \t dd \n");
	cout << process1->name << endl;
	cout << process1->state << endl;
	cout << process1->block_reason << endl;
	cout << process1->breakp << endl;
	printf("\n");
}



// 将生产者程序装入pa[]中
void bornpa(){
	for (i = 0; i <= 3; i++){
		pa[i] = i;
	}
}

// 将消费者程序装入sa[]中
void bornsa(){
	for (i = 0; i <= 3; i++){
		sa[i] = i;
	}
}


















int numProd = 0;				// 初始化生产者进程号
int numCons = 0;				// 初始化消费者消费者进程号
PoolProducer poolP;				// 初始化一个生产者进程列表
PoolConsumer poolC;				// 初始化一个消费者进程列表


// 将int 转换成string
string itos(int i) {
	stringstream s;
	s << i;
	return s.str();
}

// 生成生产者进程结点名
string generProdName() {
	int num = numProd++;
	return("PROD" + itos(num));
}



/********************************生产者相关定义***********************************/

// 生产者进程函数定义

// 生产操作
char Producer::produce() {
	char product = ranChar();
	cout << "生产完成,物品为:" << product << endl;
	return product;
}

Producer::Producer() {
	this->name = " ";
	this->state = 'U';			// Unknown
	this->block_reason = 'U';	// Unknown
	this->breakp = -1;
}

Producer::Producer(char state, char block_reason, int breakp) {
	this->name = generProdName();
	this->state = state;
	this->block_reason = block_reason;
	this->breakp = breakp;
}

Producer::~Producer() {}


// 生产者结点函数定义
ProducerNode::ProducerNode(char state, char block_reason, int breakp) :Producer(state, block_reason, breakp) {
	priorPN = nextPN = NULL;
}

ProducerNode::ProducerNode() {
	priorPN = nextPN = NULL;
}

ProducerNode::~ProducerNode() {}

// 生产者进程结点P操作
void ProducerNode::P(int s) {
	mutexP -= 1;
	if (mutexP < 0) {
		state = 'B';
		block_reason = 's';
	}
	else {
		state = 'W';
	}
	// 进入生产者队列
	poolP.addPN(this);
}

// 生产者进程结点V操作
void ProducerNode::V(int s) {
	mutexP += 1;	// 释放一个互斥信号量
	// 唤醒第一个被阻塞的进程
	if (mutexP <= 0) {
		ProducerNode* searchN = this;
		while (searchN->state == 'W')
			searchN = searchN->nextPN;
		searchN->state = 'W';
	}
	// 将当前进程从进程列表中移出
	priorPN->nextPN = nextPN;
	nextPN->priorPN = priorPN;
	nextPN = priorPN = NULL;
}


// 生产者进程列表函数定义

// 构造函数
PoolProducer::PoolProducer() {
	headPN = new ProducerNode();
	headPN->priorPN = headPN;
	headPN->nextPN = headPN;
}

// 在生产者进程列表尾部加入一个生产者结点
void PoolProducer::addPN(ProducerNode* p) {
	p->priorPN = headPN->priorPN;
	p->nextPN = headPN;
	headPN->priorPN->nextPN = p;
	headPN->priorPN = p;
}

/***********************************************************************/








