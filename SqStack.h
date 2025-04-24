#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define  STACK_INIT_SIZE   100  //存储空间初始分配量 
#define  STACKINCREMENT    10   //存储空间分配增量  
typedef int SElemType;

typedef struct SqStack {
	SElemType* base;
	SElemType* top;
	int stacksize;
};

void InitStack(SqStack& S);
void DestroyStack(SqStack& S); // 销毁栈S，S不再存在
void ClearStack(SqStack& S); // 把S置为空栈
int StackEmpty(SqStack S); // 若栈S为空栈，则返回TRUE，否则返回FALSE
int StackLength(SqStack S); // 返回S的元素个数，即栈的长度
int GetTop(SqStack S, SElemType& e);  // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
void Push(SqStack& S, SElemType e);    // 插入元素e为新的栈顶元素
int Pop(SqStack& S, SElemType& e);   // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
void StackTraverse(SqStack S, void(*visit)(SElemType)); // 从栈底到栈顶依次对栈中每个元素调用函数visit()