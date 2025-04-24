typedef int ElemType;

void input(ElemType& s);
void output(ElemType s);
int equals(ElemType a, ElemType b);

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNnode, * LinkList;

void InitList(LinkList &L);
int ListInsert(LinkList &L, int i, ElemType e);
void ListTraverse(LinkList L, void(*vi)(ElemType));
int ListDelete(LinkList &L, int i, ElemType &e);
int GetElem(LinkList L, int i, ElemType& e);
int LocateElem(LinkList L, ElemType e, int (*equal)(ElemType, ElemType));
void reverse(LinkList& L);
void MergeList(LinkList& La, LinkList& Lb, LinkList& Lc);
