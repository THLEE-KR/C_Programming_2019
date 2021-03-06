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

	num = 4;	printf("\n************* %d 검색 *************\n", num);
	(searchNode(&tree, num) != NULL) ? printf("성공!!!") : printf("실패!!!");
	num = 6;	printf("\n************* %d 검색 *************\n", num);
	(searchNode(&tree, num) != NULL) ? printf("성공!!!") : printf("실패!!!");

	num = 8;	printf("\n************* %d 삭제 *************\n", num);
	(deleteNode(&tree, num) == 1) ? printf("성공!!!") : printf("실패!!!");
	num = 3;	printf("\n************* %d 삭제 *************\n", num);
	(deleteNode(&tree, num) == 1) ? printf("성공!!!") : printf("실패!!!");
	num = 9;	printf("\n************* %d 삭제 *************\n", num);
	(deleteNode(&tree, num) == 1) ? printf("성공!!!") : printf("실패!!!");

	printf("\n************* 중위검색 ************\n");
	inorderTraverse(tree.root);
	printf("\n************* 전위검색 ************\n");
	postorderTraverse(tree.root);
	printf("\n************* 후위검색 ************\n");
	preorderTraverse(tree.root);
	printf("\n");

	printf("\n*********** 전체노드삭제 ***********\n");
	destroyTree(&tree);
	return 0;
}
