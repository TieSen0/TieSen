#include "LNnode.h"
#include <iostream>
#include <stack>
using namespace std;

int main() {
	LinkList A;
	InitList(A);
	ElemType e;

	int i, n;
	cout << "输入多少结点： ";
	cin >> n;
	
	for (i = 1; i <= n; i++) {
		cout << "输入结点的值： ";
		cin >> e;

		ListInsert(A, i, e);
	}

	LinkList p = A;
	output(p->next->data);
	cout << endl;

	if (ListDelete(A, 1, e)) {
		cout << "删除成功" << endl;
		cout << "删除的值： " << e << endl;
	}
	else {
		cout << "删除失败" << endl;
	}
	
	
}