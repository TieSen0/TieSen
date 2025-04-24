#include "SqStack.h"
#include <cstdlib>
#include <iostream>
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
		SElemType* newbase = (SElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType));
		S.base = newbase;
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