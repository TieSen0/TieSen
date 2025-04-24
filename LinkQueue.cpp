#include "LinkQueue.h"
#include <stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0 
#define OVERFLOW -1

void print(QElemType i) {
	cout << i << " ";
}

void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
}

void DestroyQueue(LinkQueue& Q) {
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

void ClearQueue(LinkQueue& Q) {
	QueuePtr p = Q.front, q;
	Q.front = Q.rear;
	while (p->next != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
}

int QueueEmpty(LinkQueue Q) {
	if (Q.front->next == NULL)
		return TRUE;
	else
		return ERROR;
}

int QueueLength(LinkQueue Q) {
	int i = 0;
	QueuePtr p = Q.front;
	while (p != Q.rear) {
		p = p->next;
		i++;
	}
	return i;
}

int GetHead(LinkQueue Q, QElemType& e) {
	if (Q.front->next != NULL) {
		e = Q.front->next->data;
		return OK;
	}
	else
		return ERROR;
}

int EnQueue(LinkQueue& Q, QElemType e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

int DeQueue(LinkQueue& Q, QElemType& e) {
	if (Q.front->next != Q.rear) {
		QueuePtr p = Q.front->next;
		e = p->data;
		Q.front->next = p->next;
		if (p = Q.rear)
			Q.front = Q.rear;
		free(p);
		return OK;
	}
	else
		return ERROR;
}

void QueueTraverse(LinkQueue Q, void(*vi)(QElemType)) {
	QueuePtr p = Q.front->next;
	while (p != NULL) {
		vi(p->data);
		p = p->next;
	}
	printf("\n");
}
