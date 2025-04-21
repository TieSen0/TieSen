
#include "LNnode.h"
#include <cstdlib>
#include <iostream>
using namespace std;


void InitList(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNnode));
	if (!L) return;
	L->next = NULL;
}

void input(ElemType &s) {
	cin >> s;
}

void output(ElemType s) {
	cout << s << " ";
}
int ListInsert(LinkList &L, int i,  ElemType e) {
	LinkList p = L, s;

	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j >= i) return 0;

	s = (LinkList)malloc(sizeof(LNnode));
	if (NULL == s) return 0;
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	return 1;
}

int ListDelete(LinkList &L, int i, ElemType &e) {
	LinkList p = L, s;

	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j >= i) return false;

	s = (LinkList)malloc(sizeof(LNnode));
	s = p->next;
	e = s->data;
	p->next = p->next->next;

	delete s;
	return e;

}

void InitStack(SqStack& S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) return;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack& S) {
	if (S.base) {
		delete S.base;
		S.base = NULL;
		S.top = NULL;
		S.stacksize = 0;
	}
}
void ClearStack(SqStack& S) {
	S.top = S.base;
}

int StackEmpty(SqStack S) {
	if (S.top == S.base) {
		return 1;
	}
}

int StackLength(SqStack S) {
	return S.top - S.base;
}

int GetTop(SqStack S, SElemType& e) {
	if (!S.base) return ERROR;
	e = *--S.top;
	return OK;
}

void Push(SqStack& S, SElemType e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)realloc(S.base,(STACK_INIT_SIZE+ STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) return;
		S.top = S.base + STACK_INIT_SIZE;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
}

int Pop(SqStack& S, SElemType& e) {
	if (!S.base) return ERROR;
	e = *--S.top;
	return OK;
}

void StackTraverse(SqStack S, void(*visit)(SElemType)) {
	SElemType* p = S.base;

	while (p < S.top) {
		visit(*p++);
	}
	printf("\n");
	return;
}