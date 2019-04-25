#include <stdio.h>
#include "Tree.h"

int main(void) {
	int cnt;
	int num;
	tree_t tree;
	int i;

	freopen("data.txt", "r", stdin);

	initTree(&tree);
	scanf("%d", &cnt);
	for (i=0 ; i<cnt ; i++) {
		scanf("%d", &num);
		addNode(&tree, num);
	}

	num = 4;	printf("\n************* %d �˻� *************\n", num);
	(searchNode(&tree, num) != NULL) ? printf("����!!!") : printf("����!!!");
	num = 6;	printf("\n************* %d �˻� *************\n", num);
	(searchNode(&tree, num) != NULL) ? printf("����!!!") : printf("����!!!");

	num = 8;	printf("\n************* %d ���� *************\n", num);
	(deleteNode(&tree, num) == 1) ? printf("����!!!") : printf("����!!!");
	num = 3;	printf("\n************* %d ���� *************\n", num);
	(deleteNode(&tree, num) == 1) ? printf("����!!!") : printf("����!!!");
	num = 9;	printf("\n************* %d ���� *************\n", num);
	(deleteNode(&tree, num) == 1) ? printf("����!!!") : printf("����!!!");

	printf("\n************* �����˻� ************\n");
	inorderTraverse(tree.root);
	printf("\n************* �����˻� ************\n");
	postorderTraverse(tree.root);
	printf("\n************* �����˻� ************\n");
	preorderTraverse(tree.root);
	printf("\n");

	printf("\n*********** ��ü������ ***********\n");
	destroyTree(&tree);
	return 0;
}
