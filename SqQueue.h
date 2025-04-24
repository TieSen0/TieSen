#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int QElemType;

#define MAX_QSIZE 5 // �����г���+1

struct SqQueue
{
	QElemType* base; // ��ʼ���Ķ�̬����洢�ռ�
	int front; // ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear; // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
};

void print(QElemType i);
void InitQueue(SqQueue& Q); // ����һ���ն���Q
void DestroyQueue(SqQueue& Q); // ���ٶ���Q��Q���ٴ���
void ClearQueue(SqQueue& Q); // ��Q��Ϊ�ն���
int QueueEmpty(SqQueue Q); // ������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
int QueueLength(SqQueue Q); // ����Q��Ԫ�ظ����������еĳ���
int GetHead(SqQueue Q, QElemType& e); // �����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
int EnQueue(SqQueue& Q, QElemType e); // ����Ԫ��eΪQ���µĶ�βԪ��
int DeQueue(SqQueue& Q, QElemType& e); // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
void QueueTraverse(SqQueue Q, void(*vi)(QElemType)); // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()  

