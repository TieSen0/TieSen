#include "SqQueue.h"
#include <stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

void print(QElemType i) {
	cout << i << " ";
}

void InitQueue(SqQueue& Q) {
	Q.base = (QElemType*)malloc(MAX_QSIZE * sizeof(QElemType));
	if (!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
}

void DestroyQueue(SqQueue& Q) {
	free(Q.base);
	Q.base = NULL;
	Q.front = Q.rear = 0;
}

void ClearQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}

int QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return TRUE;
	else
		return ERROR;
}

int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAX_QSIZE) % MAX_QSIZE;
}

int GetHead(SqQueue Q, QElemType& e) {
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	return OK;
}

int EnQueue(SqQueue& Q, QElemType e) {
	if ((Q.rear + 1) % MAX_QSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX_QSIZE;
	return OK;
}

int DeQueue(SqQueue& Q, QElemType& e) {
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAX_QSIZE;
}

void QueueTraverse(SqQueue Q, void(*vi)(QElemType)) {
	int i = Q.front;
	while (i != Q.rear) {
		vi(Q.base[i]);
		i = (i + 1) % MAX_QSIZE;
	}
	printf("\n");
}