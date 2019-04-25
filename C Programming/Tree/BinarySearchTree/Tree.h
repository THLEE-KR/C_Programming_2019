#ifndef TREE_H_
#define TREE_H_

typedef struct _node {
	int data;   							/* 데이터 저장 멤버 */
	struct _node *left; 					/* 왼쪽 자식 노드를 가리키는 포인터 멤버 */
	struct _node *right;					/* 오른쪽 자신 노드를 가리키는 포인터 멤버 */
} node_t;

typedef struct _tree {
	node_t *root; 							/* 트리의 head node를 가리키는 포인터 멤버 */
	int nodeCnt; 							/* 총 노드의 개수 */
} tree_t;

void initTree(tree_t *tp);					/* 트리 관리 구조체를 초기화 하는 함수 */
node_t *makeNode(int data);					/* 새 노드를 생성하여 반환하는 함수 */
node_t *addNode(tree_t *tp, int data);		/* 노드를 삽입하는 함수 */
void inorderTraverse(node_t *np); 			/* 중위순회(정렬 순서로 출력) */
void preorderTraverse(node_t *np);			/* 전위순회 */
void postorderTraverse(node_t *np); 		/* 후위순회 */
node_t *searchNode(tree_t *tp, int data);	/* data에 해당하는 노드 검색 함수 */
int deleteNode(tree_t *tp, int data);		/* data에 해당하는 노드 삭제 함수 */
void destroyTree (tree_t *tp);				/* tree내의 모든 노드 삭제 함수 */
void postorderDelete(node_t *np);			/* postorder(후위 순회)방식의 노드 삭제 재귀호출 함수 */

#endif /* TREE_H_ */
