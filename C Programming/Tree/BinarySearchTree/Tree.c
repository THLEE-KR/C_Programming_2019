#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

/*--------------------------------------------------------------
Function name	: initTree() - 트리 관리 구조체를 초기화하는 함수
Parameters		: tp - Tree 구조체의 주소
Returns			: 없음
--------------------------------------------------------------*/
void initTree(tree_t *tp) {
	tp->root = NULL;
	tp->nodeCnt = 0;
}

/*--------------------------------------------------------------
Function name	: makeNode() - 새 노드 생성 함수
Parameters		: data - 새 노드에 저장될 값(데이터)
				  left - 새 노드의 left 멤버 값
				  right - 새 노드의 right 멤버 값
Returns			: 새 노드의 주소
				  메모리 할당 실패 시 NULL pointer
--------------------------------------------------------------*/
node_t * makeNode(int data) {
	node_t *node = (node_t *)calloc(1,sizeof(node_t));
	if (node != NULL) {
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}

	return node;
}

/*--------------------------------------------------------------
Function name	: addNode() - 노드를 삽입하는 함수
Parameters		: tp - Tree 구조체의 주소
				  data - 새 노드에 저장될 데이터
Returns			: 새 노드의 주소
				  메모리 할당 실패 시 NULL pointer
--------------------------------------------------------------*/
node_t *addNode(tree_t *tp, int data) {

	/* 	트리 내에서 새 노드가 추가될 위치를 찾은 후
		트리의 데이터 구조 유지하면서 추가한다.
		(중복 데이터는 없는 것으로 간주)
		왼쪽 자식 노드의 값 < 부모 노드의 값 < 오른쪽 자식 노드의 값
	*/

	node_t *cur = NULL;
	node_t *prev = NULL;
	node_t *node = makeNode(data);
	if (node == NULL) {
		return NULL;
	}

	if (tp->root == NULL) {
		tp->root = node;
		tp->nodeCnt++;
	}
	else {
		cur = tp->root;

		while (cur != NULL) {
			if (data < cur->data) {
				prev = cur;
				cur = cur->left;
			}
			else if (data > cur->data) {
				prev = cur;
				cur = cur->right;
			}
			else {
				free(node);
				return NULL;
			}
		}

		if (node->data < prev->data) {
			prev->left = node;
			tp->nodeCnt++;
		}
		else {
			prev->right = node;
			tp->nodeCnt++;
		}
	}

	return node;
}

/*--------------------------------------------------------------
Function name	: inorderTraverse() - 중위 순회(정렬 순서로 출력)
Parameters		: np - 방문할 노드의 주소
Returns			: 없음
--------------------------------------------------------------*/
void inorderTraverse(node_t *np) {

	/*
		왼쪽 subtree를 방문
		해당 노드 방문
		오른쪽 subtree를 방문
		(Tip) 재귀 호출로 코딩 가능
	*/

	if (np != NULL) {
		inorderTraverse(np->left);
		printf("%d ", np->data);
		inorderTraverse(np->right);
	}
}

/*--------------------------------------------------------------
Function name	: preorderTraverse() - 전위 순회
Parameters		: np - 방문할 노드의 주소
Returns			: 없음
--------------------------------------------------------------*/
void preorderTraverse(node_t *np) {

	/*
		해당 노드 방문
		왼쪽 subtree를 방문
		오른쪽 subtree를 방문
		(Tip) 재귀 호출로 코딩 가능
	*/

	if (np != NULL) {
		printf("%d ", np->data);
		preorderTraverse(np->left);
		preorderTraverse(np->right);
	}
}

/*--------------------------------------------------------------
Function name 	: postorderTraverse() - 후위 순회
Parameters		: np - 방문할 노드의 주소
Returns			: 없음
--------------------------------------------------------------*/
void postorderTraverse(node_t *np) {
	/*
		TO DO
		왼쪽 subtree를 방문
		오른쪽 subtree를 방문
		해당 노드 방문
		(Tip) 재귀 호출로 코딩 가능
	*/


	if (np != NULL) {
		postorderTraverse(np->left);
		postorderTraverse(np->right);
		printf("%d ", np->data);
	}
}

/*-------------------------------------------------------------
Function name	: searchNode() - data에 해당하는 노드 검색
Parameters		: tp - Tree 구조체의 주소
				  data - 검색할 데이터
Returns			: 찾은 노드의 주소
				  못 찾으면 NULL pointer
-------------------------------------------------------------*/
node_t * searchNode(tree_t *tp, int data) {
	/*
		TO DO
	*/

	node_t *cur = tp->root;

	while (cur != NULL) {
		if (cur->data == data) {
			break;
		}

		if (data < cur->data) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}

	return cur;
}

/*--------------------------------------------------------------
Function name	: deleteNode() - data에 해당하는 노드 삭제
Parameters	 	: tp - Tree 구조체의 주소
				  data - 삭제할 데이터
Returns			: 성공 시 1
				  실패 시 0
--------------------------------------------------------------*/
int deleteNode(tree_t *tp, int data) {
	/*
		(1) tree의 첫노드 부터 하위 level로 내려가면서 삭제할 노드 검색

		    삭제할 노드의 parent 노드와 하위 노드를 연결을 해줘야 하므로 검색 시 parent 노드의 값도 구해야 함
		(2) 삭제된 노드 대신 parent노드의 새로운 자식(son) 역할을 할 노드 결정하기
		(2-1) 유형1 : 삭제할 노드의 자식이 2개 인 경우 (왼쪽 서브트리에서 대체노드 찾음)
		(2-2) 유형2 : 삭제노드의 자식이 없는 경우
		(2-3) 유형3 : 삭제할 노드의 자식이 1개 인 경우
	*/

	node_t *delNode;			// 삭제노드
	node_t *delParentNode;		// 삭제노드의 부모노드
	node_t *changeNode;			// 교체노드
	node_t *changeParentNode;	// 교체노드의 부모노드

	delNode = tp->root;
	delParentNode = delNode;

	/* 삭제노드와 삭제노드의 부모노드를 검색한다. */
	while (delNode != NULL) {
		/* 데이터가 일치하면 */
		if (delNode->data == data) {
			break;
		}

		/* 현재 노드를 삭제노드의 부모노드로 지정 */
		delParentNode = delNode;
		/* 삭제 데이터가 더 작을 경우 좌측 자식을 삭제노드로 */
		if (data < delNode->data) {
			delNode = delNode->left;
		}
		/* 삭제 데이터가 더 클 경우 우측 자식을 삭제노드로 */
		else {
			delNode = delNode->right;
		}
	}

	/* 삭제 노드가 존재하지 않을 경우 */
	if (delNode == NULL) {
		return 0;
	}
	/* 삭제 노드가 존재한다면 */
	else {
		/* 두 자식이 모두 존재하는 경우 */
		if ((delNode->left != NULL) && (delNode->right != NULL)) {
			/* 삭제노드를 교체노드의 부모노드로 지정한다. */
			changeParentNode = delNode;
			/* 삭제노드의 좌측 자식을 교체노드로 지정한다. */
			changeNode = delNode->left;

			/* 현재의 교체노드로부터 교체노드와 교체노드의 부모노드를 검색한다. */
			while (changeNode->right != NULL) {
				changeParentNode = changeNode;
				changeNode = changeNode->right;
			}

			/* 삭제노드와 교체노드의 값을 교환한다. */
			int tmp = delNode->data;
			delNode->data = changeNode->data;
			changeNode->data = tmp;

			/* 삭제노드의 값이 교체노드의 부모노드 값 보다 크다면 교체노드의 좌측 자식을 교체노드의 부모노드의 우측 자식으로 입양한다. */
			if (delNode->data > changeParentNode->data) {
				changeParentNode->right = changeNode->left;
			}
			/* 삭제노드의 값이 교체노드의 부모노드 값 보다 작다면 교체노드의 좌측 자식을 교체노드의 부모노드의 좌측 자식으로 입양한다. */
			else {
				changeParentNode->left = changeNode->left;
			}
			/* 교체노드를 삭제노드로 지정한다. */
			delNode = changeNode;
		}
		/* 두 자식이 모두 없을 경우 */
		else if ((delNode->left == NULL) && (delNode->right == NULL)) {
			/* 삭제 노드의 데이터가 삭제 노드의 부모 노드보다 큰 값을 가진 경우 */
			if (delNode->data > delParentNode->data) {
				/* 삭제 노드의 부모 노드의 우측 자식을 NULL로 지정 한다. */
				delParentNode->right = NULL;
			}
			else {
				/* 삭제 노드의 부모 노드의 좌측 자식을 NULL로 지정 한다. */
				delParentNode->left = NULL;
			}
		}
		/* 하나의 자식만 존재할 경우 */
		else {
			/* 삭제 노드를 교체 노드의 부모 노드로 한다. */
			changeParentNode = delNode;

			/* 좌측 자식 만 가질 경우 */
			if (delNode->left != NULL) {
				/* 좌측 자식이 교체 대상 노드가 된다. */
				changeNode = delNode->left;
			}
			/* 우측 자식 만 가질 경우 */
			else {
				/* 우측 자식이 교체 대상 노드가 된다. */
				changeNode = delNode->right;
			}

			/* 삭제 노드와 교체 노드의 데이터를 교체한다. */
			int tmp = delNode->data;
			delNode->data = changeNode->data;
			changeNode->data = tmp;

			/* 교체 노드의 자식을 교체 노드의 부모 노드에 입양한다. */
			changeParentNode->left = changeNode->left;
			changeParentNode->right = changeNode->right;

			/* 교체 노드를 삭제 노드로 지정한다. */
			delNode = changeNode;
		}

		free(delNode);
		if (delNode == tp->root) {
			tp->root = NULL;
		}
	}

	return 1;
}

/*--------------------------------------------------------------
Function name	: destroyTree() - tree 내의 모든 노드 삭제(tree 소멸)
Parameters		: tp - Tree 구조체의 주소
Returns			: 없음
--------------------------------------------------------------*/
void destroyTree (tree_t * tp) {

	/*
		postoderDelete()함수를 호출하여 tree내의 모든 모드 삭제
		root 멤버 NULL pointer값으로 초기화, nodeCnt 멤버 0으로 초기화
	*/

	postorderDelete(tp->root);
	tp->root = NULL;
	tp->nodeCnt = 0;
}

/*--------------------------------------------------------------
Function name	: postorderDelete() - 후위 순회방식의 노드 삭제
									  (재귀호출 함수)
Parameters		: np - 방문할 노드의 주소
Returns			: 없음
--------------------------------------------------------------*/
void postorderDelete(node_t *np) {

	/*
		왼쪽 subtree를 방문
		오른쪽 subtree를 방문
		해당 노드를 삭제 처리
		(Tip) 재귀 호출로 코딩 가능
	*/

	if (np != NULL) {
		postorderDelete(np->left);
		postorderDelete(np->right);
		printf("[%d]삭제 ", np->data);
		free(np);
	}

}
