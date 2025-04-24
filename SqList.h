#define INIT_SIZE 5
#define INCREAMENT 10

typedef int ElemType;
void input(ElemType& s);
void output(ElemType s);
int equals(ElemType a, ElemType b);

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;

void InitSqList(SqList& L);
int ListInsert(SqList& L, int i, ElemType e);
int ListDelete(SqList& L, int i, ElemType& e);
void ListTraverse(SqList& L, void(*vi)(ElemType e));
int GetElem(SqList L, int i, ElemType& e);
int LocateElem(SqList L, ElemType e, int (*equals) (ElemType, ElemType));
void reverse(SqList& L);
int MergeList(SqList La, SqList Lb, SqList& Lc);