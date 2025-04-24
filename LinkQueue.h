typedef int QElemType;

typedef struct QNode {
	QElemType data;
	QNode* next;
}*QueuePtr;

typedef struct LinkQueue {
	QueuePtr front, rear;
};

void print(QElemType i);
void InitQueue(LinkQueue& Q); // ����һ���ն���Q
void DestroyQueue(LinkQueue& Q); // ���ٶ���Q��Q���ٴ���
void ClearQueue(LinkQueue& Q); // ��Q��Ϊ�ն���
int QueueEmpty(LinkQueue Q); // ������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
int QueueLength(LinkQueue Q); // ����Q��Ԫ�ظ����������еĳ���
int GetHead(LinkQueue Q, QElemType& e); // �����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
int EnQueue(LinkQueue& Q, QElemType e); // ����Ԫ��eΪQ���µĶ�βԪ��
int DeQueue(LinkQueue& Q, QElemType& e); // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
void QueueTraverse(LinkQueue Q, void(*vi)(QElemType)); // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()  