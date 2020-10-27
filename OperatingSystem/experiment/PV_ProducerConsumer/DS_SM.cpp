#include"DS_SM.h"
#include<iostream>
#include<string>		// ���������������ߵ��ַ�������
#include<sstream>		// ���ڽ����̺Ų��뵽����/�����߽�������

#include<windows.h>		// sleep������������
using namespace std;

#define volume_buffer 10;	// ��������,����������Ϊ10

int mutexP = volume_buffer;	// �����߽��̻����ź�����ֵΪ����������
int mutexC = 0;				// �����߽��̻����ź�����ֵΪ0
int numProd = 0;			// ��ʼ�������߽��̺�
int numCons = 0;			// ��ʼ�������������߽��̺�
PoolProducer processP;		// ��ʼ��һ�������߽����б�
PoolConsumer processC;		// ��ʼ��һ�������߽����б�


// ģ��������λ��������
char ranChar()
{
	char arr[10] = { 'a','b','c','d','e','f','g','h','i','j' };
	return arr[abs(rand() % 10)];
}

// ��int ת����string
string itos(int i){
	stringstream s;
	s << i;
	return s.str();
}


string generProdName() {
	int num = numProd++;
	return("PROD"+itos(num));
}


/********************************��������ض���***********************************/

// �����߽��̺�������

void Producer::produce() {
	char product = ranChar();
	cout << "�������,��ƷΪ:" << product << endl;
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


// �����߽�㺯������
ProducerNode::ProducerNode(char state, char block_reason, int breakp):Producer(state,block_reason,breakp){
	priorPN = nextPN = NULL;
}

ProducerNode::ProducerNode(){
	priorPN = nextPN = NULL;
}

ProducerNode::~ProducerNode(){}

// �����߽��̽��P����
void ProducerNode::P(int s) {
	mutexP -= 1;
	if (mutexP < 0) {
		state = 'B';
		block_reason = 's';
	}
	else {
		state = 'W';
	}
	// ���������߶���
	processP.addPN(this);
}

// �����߽��̽��V����
void ProducerNode::V(int s){
	mutexP += 1;	// �ͷ�һ�������ź���
	// ���ѵ�һ���������Ľ���
	if (mutexP <= 0) {
		ProducerNode* searchN = this;
		while (searchN->state == 'W')
			searchN = searchN->nextPN;
		searchN->state = 'W';
	}
	// ����ǰ���̴ӽ����б����Ƴ�
	priorPN->nextPN = nextPN;
	nextPN->priorPN = priorPN;
	nextPN = priorPN = NULL;
}


// �����߽����б�������

// ���캯��
PoolProducer::PoolProducer(){
	headPN = new ProducerNode();
}

// �������߽����б�β������һ�������߽��
void PoolProducer::addPN(ProducerNode* p){
	p->priorPN = headPN->priorPN;
	p->nextPN = headPN;
	headPN->priorPN->nextPN = p;
	headPN->priorPN = p;
}
























int pc;					// ���������
int s1, s2;				// �����ź���
int i, j;
int in, out;
int m;
char buffer[10];		// ����Ϊ10�Ĺ�������
char c, x;
int pa[6], sa[6];

// ����ԭ�ﶨ��


/*	p����ԭ��
	���ź��� s ��ȥ 1��  �����С�� 0:
	ִ��ԭ��Ľ��̱��óɵȴ��ź��� s ��״̬��
	����:
	ִ��ԭ��Ľ��̾���*/
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


/*	V����ԭ��
	���ź��� s �� 1������������� 0��
	���ͷ�һ���ȴ��ź��� s �Ľ��̡�*/
void Producer::V(int s) {
	s += 1;
	if (s <= 0) {
		this->state = 'W';
	}
	process1->state = 'W';
	return(s);
}



void put() {
	Sleep(1000);	// VC�µ�Sleep����������λ�Ǻ���,���������1s
	buffer[in] = RanChar();
	in = (in + 1) % 10;	// ѭ������
	printf("product a char is %c!\n",buffer[in-1]);
	int k = 0;
	for (m = 0; m < 10; m++) {
		if (buffer[m] != ' ') {
			printf("%c", buffer[m]);
			k = k + 1;
		}
	}
	printf("���������%d����Ʒ\n", k);
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
	printf("���������%d����Ʒ\n", k);
}

void gotol() {
	pc = 0;
}

void nop(){}

// ����������ʾ����,������ʾ��ǰ����
void disp() {
	printf("\n name \t state \t why \t dd \n");
	cout << process1->name << endl;
	cout << process1->state << endl;
	cout << process1->block_reason << endl;
	cout << process1->breakp << endl;
	printf("\n");
}

// ��ʼ������
void init(){
	s1 = 10;/*s1��ʾ�ջ�����������*/
	s2 = 0; /*s2��ʾ��������������*/
	producer.name = 'p';/*�������߽��̳�ʼ��*/
	producer.block_reason = ' ';
	producer.breakp = 0;
	consumer.name = 'c';/*�������߽��̳�ʼ��*/
	consumer.state = 'W';
	consumer.block_reason = ' ';
	consumer.breakp = 0;
	for (int k = 0; k < 10; k++){
		buffer[k] = ' ';
	}
}

// �������߳���װ��pa[]��
void bornpa(){
	for (i = 0; i <= 3; i++){
		pa[i] = i;
	}
}

// �������߳���װ��sa[]��
void bornsa(){
	for (i = 0; i <= 3; i++){
		sa[i] = i;
	}
}

// ���������ȳ���
void diaodu()
{
	while ((producer.state == 'W') || (consumer.state == 'W'))
	{
		x = rand();/*x������һ����*/
		x = x % 2;/*��Xȡ��*/
		if (x == 0)/*��X�����㪩��ִ�������߽��̪���ִ֮������
	  �߽���*/
		{
			process1 = &producer;/*process��ʾ���н��̪������н�
		 ����Ϊ�����߽���*/
			process2 = &consumer;
		}
		else
		{
			process1 = &consumer;
			process2 = &producer;
		}  
		pc = process1->breakp;
		i = pc;/*��ʱ��PC��ֵ����I*/
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
		else if ((process1->name == "c") && (process1->state == 'W'))/*ִ��
	  �����߽����Ҹý��̴��ھ���״̬*/
		{
			process1->state = 'W';
			j = sa[i];
			pc = i + 1;
			switch (j)
			{
			case 0: s2 = P(s2); process1->breakp = pc; break;/*������Դ����û
		 �����뵽����ת*/
			case 1: get(); process1->breakp = pc; break;
			case 2: s1 = v(s1); process1->breakp = pc; break;
			case 3: gotol(); process1->state = 'W'; process1->breakp = pc;
			}
		} /*end else*/
	}/*end while*/
	printf("\nThe program is over!\n");
}

