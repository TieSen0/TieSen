#include <stdio.h>
#include <iostream>
using namespace std;
#include "SqList.h"

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

void InitSqList(SqList& L) {
	L.elem = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
	if (!L.elem) return;
	L.length = 0;
	L.listsize = INIT_SIZE;
}

int ListInsert(SqList& L, int i, ElemType e) {
	ElemType* newbase, * q, * p;
	if (i < 1 || i > L.length + 1)
		return 0;
	if (L.length >= L.listsize) {
		if (!(newbase = (ElemType*)realloc(L.elem, (L.listsize + INCREAMENT) * sizeof(ElemType))))
			return 0;
		L.elem = newbase;
		L.listsize += INCREAMENT;
	}
	q = L.elem + i - 1;
	for (p = L.elem + L.length - 1; p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return 1;
}

int ListDelete(SqList& L, int i, ElemType& e) {
	ElemType* q, * p;
	if (i < 1 || i > L.length)
		return 0;
	p = L.elem + i - 1;
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p <= q; p++)
		*(p - 1) = *p;
	--L.length;
	return 1;
}

void ListTraverse(SqList& L, void(*vi)(ElemType e)) {
	ElemType* p;
	p = L.elem;
	int i;
	for (i = 0; i < L.length; i++)
		vi(*p);
	printf("\n");
}

int GetElem(SqList L, int i, ElemType& e) {
	if (i < 1 || i > L.length)
		return 0;
	e = *(L.elem + i - 1);
	return 1;
}

int LocateElem(SqList L, ElemType e, int (*equals) (ElemType, ElemType)) {
	int i = 1;
	ElemType* p;
	p = L.elem;
	while (i <= L.length) {
		if (!equals(*p++, e))
			i++;
		else
			break;
	}
	return i <= L.length ? i : 0;
}

void reverse(SqList& L) {
	int i;
	for (i = 0; i < L.length / 2 ; i++) {
		ElemType p = L.elem[i];
		L.elem[i] = L.elem[L.length - i - 1];
		L.elem[L.length - i - 1] = p;
	}
}

int MergeList(SqList La, SqList Lb, SqList& Lc) {
	Lc.listsize = Lc.length = La.length + Lb.length;
	ElemType* pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem) exit(-1);
	ElemType* pa = La.elem;
	ElemType* pa_last = La.elem + La.length - 1;
	ElemType* pb = Lb.elem;
	ElemType* pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while(pa <= pa_last) *pc++ = *pa++;
	while (pb <= pb_last) *pc++ = *pb++;
}
