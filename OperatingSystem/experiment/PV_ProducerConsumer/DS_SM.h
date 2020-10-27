#pragma once
#include<iostream>
#include<string>
using namespace std;

class PoolProducer;		// ǰ������;�����߽��̳�
class PoolConsumer;		// ǰ������;�����߽��̳�
class ProducerNode;		// ǰ������;�����߽��̽��
class ConsumerNode;		// ǰ������;�����߽��̽��


/************************************ ������ ********************************************/
// �����߽��̵�����
class Producer {
	string name;		// ������
	char state;			// ����״̬
	char block_reason;	// ����ԭ��
	int breakp;			// �ϵ㱣��
	void produce();		// ��������
public:
	Producer();			// �չ��캯��,����ͷ��㶨��
	Producer(char state, char block_reason, int breakp);
	~Producer();
	friend class ProducerNode;	// ʹ�������߽��̽����Է��������߽��̵�˽������
	friend class PoolProducer;	// ʹ�������߽��̳ؿ��Է��������߽��̵�˽������
};


// �����߽��
class ProducerNode : public Producer{
	ProducerNode* priorPN;	// ָ��ǰһ�������߽���ָ��
	ProducerNode* nextPN;	// ָ���һ�������߽���ָ��
public:
	// ���캯��
	ProducerNode();		// �չ��캯��(����ͷ��㶨��)
	ProducerNode(char state, char block_reason, int breakp);
	~ProducerNode();
	void P(int s);					// p����ԭ��(��������Ϊ��ǰ������״̬������)
	void V(int s);					// v����ԭ��
	friend class PoolProducer;	// ʹ�������߽��̳ؿ��Է��������߽��̽�������
};


// �����߽���˫��ѭ���б�
class PoolProducer {
	ProducerNode* headPN;			// ͷ���
public:
	PoolProducer();					// �չ��캯��
	void addPN(ProducerNode* p);	// ����һ�������߽��̽��
};

/***************************************************************************************/


// �����߽��̵�����
class Consumer {
	string name;		// ������
	char state;			// ����״̬
	char block_reason;	// ����ԭ��
	int breakp;			// �ϵ㱣��
	void consume();		// ���Ѳ���
public:
	Consumer(char state, char block_reason, int breakp);
	~Consumer();
	friend class PoolConsumer;	// ʹ�������߽��̳ؿ��Է��������߽��̵�����
};

// �����߽��
class ConsumerNode : public Consumer {
	Consumer* priorCN;	// ָ��ǰһ�������߽���ָ��
	Consumer* nextCN;	// ָ���һ�������߽���ָ��
	ConsumerNode(string name, char state, char block_reason, int breakp);
	~ConsumerNode();
	friend class PoolConsumer;	// ʹ�������߽��̳ؿ��Է��������߽��̽�������
};



// �����߽��̳�
class PoolConsumer {
	ConsumerNode* headCN;			// ͷ���
	ConsumerNode* currentCN;		// ��ǰ���(���һ�������еĽ��)
public:
	PoolConsumer();					// �չ��캯��
	void addCN(ConsumerNode* p);	// ����һ�������߽��̽��
	void delCN(ConsumerNode* p);	// ɾ��һ�������߽��̽��
	void P(int s);					// p����ԭ��(��������Ϊ��ǰ������״̬������)
	void V(int s);					// v����ԭ��
};

/******************************������������***************************/
char ranChar();		// ģ������һ�ݲ�Ʒ							
string itos(int i);	// ����������ת��Ϊ�ַ���
string generProdName();	// ���������߽�����

void put();
void get();
void gotol();
void nop();
void disp();
void init();
void bornpa();
void bornsa();
void diaodu();








