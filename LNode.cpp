#include "LNode.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void input(ElemType& s) {
	cin >> s;
}
void output(ElemType s) {
	cout << s << " ";
}
int equals(ElemType a, ElemType b) {
	if (a == b)
		return 1;
	else
		return 0;
}

void InitList(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
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

	s = (LinkList)malloc(sizeof(LNode));
	if (NULL == s) return 0;
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	return 1;
}

void ListTraverse(LinkList L, void(*vi)(ElemType)) {
	LinkList p = L->next;;
	while (p) {
		vi(p->data);
		p = p->next;
	}
	printf("\n");
}

int ListDelete(LinkList &L, int i, ElemType &e) {
	LinkList p = L, s;

	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j >= i) return false;

	s = (LinkList)malloc(sizeof(LNode));
	s = p->next;
	e = s->data;
	p->next = p->next->next;

	free(s);
	return e;
}

int GetElem(LinkList L, int i, ElemType& e) {
	LinkList p = L->next;
	int j = 1;
	while (p && j < i) {
		j++;
		p = p->next;
	}
	if (!p || j > i) return 0;
	e = p->data;
	return 1;
}

int LocateElem(LinkList L, ElemType e, int (*equal)(ElemType, ElemType)) {
	int i = 1;
	LinkList p = L->next;
	while (p) {
		if (equals(p->data, e)) return i;
		p = p->next;
		i++;
	}
	return 0;
}

void reverse(LinkList& L) {
	LinkList p, q;
	p = L->next;
	L->next = NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		q->next = L->next;
		L->next = q;
	}
}

void MergeList(LinkList& La, LinkList& Lb, LinkList& Lc) {
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	Lc = La;
	pc = Lc;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}