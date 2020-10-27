#pragma once
#include<iostream>
#include<string>
using namespace std;


/************************************ ���̿��ƿ� ********************************************/
typedef struct Pcb {
	string name;		// ������
	char state;		    // ����״̬(����,����,����,���)
	string wait_reason;	// �ȴ�ԭ��(�����ź���)
	int breakp;			// �ϵ�
}Pcb, * Process;		// ����struct Pcb Ϊ Pcb,Pcb*ΪProcess

/***************************************************************************************/


/***************************** ģ��Ĵ�����ָ�� ***************************************/
void P(int mutex);		// P����
void V(int mutex);		// V����
void put(char p);		// �������Ĳ�Ʒ���뻺���������Ե�ǰ�������ж��ٲ�Ʒ
void GET(char x);		// �ӻ������л�ȡһ�ݲ�Ʒ
void produce(char c);	// ����һ���ַ�����c��
void consume(char p);	// ����
void GOTOL(int L);		// PC : L
void NOP();				// �ղ���

/***************************************************************************************/

void init();			// ��ʼ������
void scheduling();		// ����������

/******************************������������***************************/


char ranChar();			// ģ������һ�ݲ�Ʒ							
string itos(int i);		// ����������ת��Ϊ�ַ���
string generProdName();	// ���������߽�����
void W(int mutex);		// ���ù��̵Ľ�����Ϊ�ȴ��ź���mutex��״̬
void R(int mutex);		// �ͷ�һ���ȴ��ź���mutex�Ľ���
void processP();		// �����߽���
void processC();		// �����߽���




void disp();

void bornpa();
void bornsa();
void diaodu();





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
	char produce();		// ��������
public:
	Producer();			// �չ��캯��,����ͷ��㶨��
	Producer(char state, char block_reason, int breakp);
	~Producer();
	friend class ProducerNode;	// ʹ�������߽��̽����Է��������߽��̵�˽������
	friend class PoolProducer;	// ʹ�������߽��̳ؿ��Է��������߽��̵�˽������
};


// �����߽��
class ProducerNode : public Producer {
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

/************************************ ������ ********************************************/

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
/***************************************************************************************/

