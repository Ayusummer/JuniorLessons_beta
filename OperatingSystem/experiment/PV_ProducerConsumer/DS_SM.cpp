#include"DS_SM.h"
#include<iostream>
#include<string>		// ���������������ߵ��ַ�������
#include<sstream>		// ���ڽ����̺Ų��뵽����/�����߽�������

#include<windows.h>		// sleep������������
using namespace std;

const int volume_buffer = 10;	// ��������,����������Ϊ10

char buffer[volume_buffer];		// ���建����
int currentSumBuffer = 0;		// ���嵱ǰ�������в�Ʒ������
// �����ź�������
int mutexP = volume_buffer;		// �����߽��̻����ź�����ֵΪ����������
int mutexC = 0;					// �����߽��̻����ź�����ֵΪ0
int subP = 0;					// �����ߴ������±궨��
int subC = 0;					// ������ȡ�����±궨��
int PC;							// ���������
int PA[5], SA[5];				// ����/������ģ��ָ����ڵ�ַ����
Pcb producer, consumer;			// ������,�����߽��̿��ƿ�








/************************* ģ��Ĵ�����ָ�� *******************************/
// ģ��������λ��������
char ranChar()
{
	char arr[10] = { 'a','b','c','d','e','f','g','h','i','j' };
	return arr[abs(rand() % 10)];
}

// ���ù��̵Ľ�����Ϊ�ȴ��ź���s��״̬
void W(int mutex) {

}

// �ͷ�һ���ȴ��ź���mutex�Ľ���
void R(int mutex) {

}

// P����
void P(int mutex) {
	mutex--;
	if (mutex < 0)
		W(mutex);
}

// V����
void V(int mutex) {
	mutex++;
	if (mutex <= 0)
		R(mutex);
}

// �������Ĳ�Ʒ���뻺���������Ե�ǰ�������ж��ٲ�Ʒ
void put(char p) {
	Sleep(1000);	// �������1s
	buffer[subP] = p;
	subP = (subP + 1) % 10;
	cout << "��Ʒ����:" << p << endl;
	cout << "����������" << ++currentSumBuffer << "����Ʒ" << endl;
}

// �ӻ������л�ȡһ�ݲ�Ʒ
void GET(char x) {
	Sleep(1000);	// ģ���ȡʱ��,�������1s
	x = buffer[subC];
	subC = (subC + 1) % 10;
	cout << "�Ѵӻ��������һ�ݲ�Ʒ:" << x << endl;
	cout << "����������" << --currentSumBuffer << "����Ʒ" << endl;
}

// ����һ���ַ�����c��
void produce(char c) {
	c = ranChar();
}

// ģ�����ѹ���
void consume(char p){
	cout << "��Ʒ" << p << "�ѱ�����" << endl;
}

// PC : L
void GOTOL(int L) {
	PC = L;
}

// �ղ���
void NOP() {}

/*************************************************************************/


// �����߽��̶���
void processP(){
	char c;
	produce(c);
	while (true){
		P(mutexP);
		put(c);
		V(mutexC);
	}
}

// �����߽��̶���
void processC(){
	char x;
	while (true){
		GET(x);
		V(mutexP);
		consume(x);
	}
}


/******************************* ��ʼ������ ******************************/
void init() {
	mutexP = volume_buffer;		// ��������ʼ��λ���ֵ�ɹ�������ʹ��
	mutexC = 0;					// ����������޲�Ʒ��������ʹ��
	// ��ʼ�������߽��̿��ƿ�����
	producer.name = "������";
	producer.state = 'W';
	producer.breakp = 0;
	producer.wait_reason = "";
	// ��ʼ�������߽��̿��ƿ�����
	consumer.name = "������";
	consumer.state = 'W';
	consumer.breakp = 0;
	consumer.wait_reason = "";
	// �����н�������Ϊ�����߽��̲����������������
	
	PC = 0;



	// ��ʼ��������
	for (int k = 0; k < 10; k++) {
		buffer[k] = ' ';
	}
}

// ����������
void scheduling() {

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



/*************************** �ָ��� ********************************/
int i, j;

int m;

char c, x;


// ����������ʾ����,������ʾ��ǰ����
void disp() {
	printf("\n name \t state \t why \t dd \n");
	cout << process1->name << endl;
	cout << process1->state << endl;
	cout << process1->block_reason << endl;
	cout << process1->breakp << endl;
	printf("\n");
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


















int numProd = 0;				// ��ʼ�������߽��̺�
int numCons = 0;				// ��ʼ�������������߽��̺�
PoolProducer poolP;				// ��ʼ��һ�������߽����б�
PoolConsumer poolC;				// ��ʼ��һ�������߽����б�


// ��int ת����string
string itos(int i) {
	stringstream s;
	s << i;
	return s.str();
}

// ���������߽��̽����
string generProdName() {
	int num = numProd++;
	return("PROD" + itos(num));
}



/********************************��������ض���***********************************/

// �����߽��̺�������

// ��������
char Producer::produce() {
	char product = ranChar();
	cout << "�������,��ƷΪ:" << product << endl;
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


// �����߽�㺯������
ProducerNode::ProducerNode(char state, char block_reason, int breakp) :Producer(state, block_reason, breakp) {
	priorPN = nextPN = NULL;
}

ProducerNode::ProducerNode() {
	priorPN = nextPN = NULL;
}

ProducerNode::~ProducerNode() {}

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
	poolP.addPN(this);
}

// �����߽��̽��V����
void ProducerNode::V(int s) {
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
PoolProducer::PoolProducer() {
	headPN = new ProducerNode();
	headPN->priorPN = headPN;
	headPN->nextPN = headPN;
}

// �������߽����б�β������һ�������߽��
void PoolProducer::addPN(ProducerNode* p) {
	p->priorPN = headPN->priorPN;
	p->nextPN = headPN;
	headPN->priorPN->nextPN = p;
	headPN->priorPN = p;
}

/***********************************************************************/








