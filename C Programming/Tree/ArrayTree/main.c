#include <stdio.h>
#include "tree.h"

int main(void) {
	freopen("data.txt", "r", stdin);

	createTree();
	printf("��� ��ȸ : ");
	DLR(1);
	printf("\n");
	printf("�湮�� ��� �� : %d\n", cnt);
	printf("5�� ���� : %d\n", FND(5));

	return 0;
}

