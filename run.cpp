#include "LNnode.h"
#include <iostream>
#include <stack>
using namespace std;

int main() {
	LinkList A;
	InitList(A);
	ElemType e;

	int i, n;
	cout << "������ٽ�㣺 ";
	cin >> n;
	
	for (i = 1; i <= n; i++) {
		cout << "�������ֵ�� ";
		cin >> e;

		ListInsert(A, i, e);
	}

	LinkList p = A;
	output(p->next->data);
	cout << endl;

	if (ListDelete(A, 1, e)) {
		cout << "ɾ���ɹ�" << endl;
		cout << "ɾ����ֵ�� " << e << endl;
	}
	else {
		cout << "ɾ��ʧ��" << endl;
	}
	
	
}