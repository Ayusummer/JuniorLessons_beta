#include"DS_SM.h"
#include<iostream>
#include<string>		// 用于生产者消费者的字符串命名
#include<sstream>		// 用于将进程号插入到生产/消费者进程名中

#include<windows.h>		// sleep函数的依赖库
using namespace std;

#define volume_buffer 10;	// 根据题设,缓冲区容量为10

int mutexP = volume_buffer;	// 生产者进程互斥信号量初值为缓冲区容量
int mutexC = 0;				// 消费者进程互斥信号量初值为0
int numProd = 0;			// 初始化生产者进程号
int numCons = 0;			// 初始化消费者消费者进程号
PoolProducer processP;		// 初始化一个生产者进程列表
PoolConsumer processC;		// 初始化一个消费者进程列表


// 模拟生产单位函数定义
char ranChar()
{
	char arr[10] = { 'a','b','c','d','e','f','g','h','i','j' };
	return arr[abs(rand() % 10)];
}

// 将int 转换成string
string itos(int i){
	stringstream s;
	s << i;
	return s.str();
}


string generProdName() {
	int num = numProd++;
	return("PROD"+itos(num));
}


/********************************生产者相关定义***********************************/

// 生产者进程函数定义

void Producer::produce() {
	char product = ranChar();
	cout << "生产完成,物品为:" << product << endl;
}

Producer::Producer(){
	this->name = " ";
	this->state = 'U';			// Unknown
	this->block_reason = 'U';	// Unknown
	this->breakp = -1;
}

Producer::Producer(char state, char block_reason, int breakp){
	this->name = generProdName();
	this->state = state;
	this->block_reason = block_reason;
	this->breakp = breakp;
}

Producer::~Producer(){}


// 生产者结点函数定义
ProducerNode::ProducerNode(char state, char block_reason, int breakp):Producer(state,block_reason,breakp){
	priorPN = nextPN = NULL;
}

ProducerNode::ProducerNode(){
	priorPN = nextPN = NULL;
}

ProducerNode::~ProducerNode(){}

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
	processP.addPN(this);
}

// 生产者进程结点V操作
void ProducerNode::V(int s){
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
PoolProducer::PoolProducer(){
	headPN = new ProducerNode();
}

// 在生产者进程列表尾部加入一个生产者结点
void PoolProducer::addPN(ProducerNode* p){
	p->priorPN = headPN->priorPN;
	p->nextPN = headPN;
	headPN->priorPN->nextPN = p;
	headPN->priorPN = p;
}
























int pc;					// 程序计数器
int s1, s2;				// 两个信号量
int i, j;
int in, out;
int m;
char buffer[10];		// 容量为10的共享缓冲区
char c, x;
int pa[6], sa[6];

// 操作原语定义


/*	p操作原语
	将信号量 s 减去 1，  若结果小于 0:
	执行原语的进程被置成等待信号量 s 的状态。
	否则:
	执行原语的进程就绪*/
char Producer::P(int s){
	s -= 1;
	if (s < 0) {
		this->state = 'B';
		this->block_reason = 's';
	}
	else {
		this->state = 'W';
	}
	return this->state;
}


/*	V操作原语
	将信号量 s 加 1，若结果不大于 0，
	则释放一个等待信号量 s 的进程。*/
void Producer::V(int s) {
	s += 1;
	if (s <= 0) {
		this->state = 'W';
	}
	process1->state = 'W';
	return(s);
}



void put() {
	Sleep(1000);	// VC下的Sleep函数变量单位是毫秒,即程序挂起1s
	buffer[in] = RanChar();
	in = (in + 1) % 10;	// 循环自增
	printf("product a char is %c!\n",buffer[in-1]);
	int k = 0;
	for (m = 0; m < 10; m++) {
		if (buffer[m] != ' ') {
			printf("%c", buffer[m]);
			k = k + 1;
		}
	}
	printf("缓冲池中有%d个产品\n", k);
}

void get() {
	Sleep(1000);
	x = buffer[out];
	printf("\n%c get a char from buffer", x);
	printf("\n");
	buffer[out] = ' ';
	out = (out + 1) % 10;
	int k = 0;
	for (m = 0; m < 10; m++) {
		if (buffer[m] != ' ') {
			printf("%c", buffer[m]);
			k = k + 1;
		}
	}
	printf("缓冲池中有%d个产品\n", k);
}

void gotol() {
	pc = 0;
}

void nop(){}

// 建立进程显示函数,用于显示当前进程
void disp() {
	printf("\n name \t state \t why \t dd \n");
	cout << process1->name << endl;
	cout << process1->state << endl;
	cout << process1->block_reason << endl;
	cout << process1->breakp << endl;
	printf("\n");
}

// 初始化程序
void init(){
	s1 = 10;/*s1表示空缓冲区的数量*/
	s2 = 0; /*s2表示满缓冲区的数量*/
	producer.name = 'p';/*对生产者进程初始化*/
	producer.block_reason = ' ';
	producer.breakp = 0;
	consumer.name = 'c';/*对消费者进程初始化*/
	consumer.state = 'W';
	consumer.block_reason = ' ';
	consumer.breakp = 0;
	for (int k = 0; k < 10; k++){
		buffer[k] = ' ';
	}
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

