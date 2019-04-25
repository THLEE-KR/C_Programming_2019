#include <stdio.h>
#include "tree.h"

int main(void) {
	freopen("data.txt", "r", stdin);

	createTree();
	printf("노드 순회 : ");
	DLR(1);
	printf("\n");
	printf("방문한 노드 수 : %d\n", cnt);
	printf("5의 조상 : %d\n", FND(5));

	return 0;
}

