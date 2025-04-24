#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define  STACK_INIT_SIZE   100  //�洢�ռ��ʼ������ 
#define  STACKINCREMENT    10   //�洢�ռ��������  
typedef int SElemType;

typedef struct SqStack {
	SElemType* base;
	SElemType* top;
	int stacksize;
};

void InitStack(SqStack& S);
void DestroyStack(SqStack& S); // ����ջS��S���ٴ���
void ClearStack(SqStack& S); // ��S��Ϊ��ջ
int StackEmpty(SqStack S); // ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
int StackLength(SqStack S); // ����S��Ԫ�ظ�������ջ�ĳ���
int GetTop(SqStack S, SElemType& e);  // ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
void Push(SqStack& S, SElemType e);    // ����Ԫ��eΪ�µ�ջ��Ԫ��
int Pop(SqStack& S, SElemType& e);   // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
void StackTraverse(SqStack S, void(*visit)(SElemType)); // ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()