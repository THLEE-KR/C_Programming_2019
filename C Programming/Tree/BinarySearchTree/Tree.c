#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

/*--------------------------------------------------------------
Function name	: initTree() - Ʈ�� ���� ����ü�� �ʱ�ȭ�ϴ� �Լ�
Parameters		: tp - Tree ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------*/
void initTree(tree_t *tp) {
	tp->root = NULL;
	tp->nodeCnt = 0;
}

/*--------------------------------------------------------------
Function name	: makeNode() - �� ��� ���� �Լ�
Parameters		: data - �� ��忡 ����� ��(������)
				  left - �� ����� left ��� ��
				  right - �� ����� right ��� ��
Returns			: �� ����� �ּ�
				  �޸� �Ҵ� ���� �� NULL pointer
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
Function name	: addNode() - ��带 �����ϴ� �Լ�
Parameters		: tp - Tree ����ü�� �ּ�
				  data - �� ��忡 ����� ������
Returns			: �� ����� �ּ�
				  �޸� �Ҵ� ���� �� NULL pointer
--------------------------------------------------------------*/
node_t *addNode(tree_t *tp, int data) {

	/* 	Ʈ�� ������ �� ��尡 �߰��� ��ġ�� ã�� ��
		Ʈ���� ������ ���� �����ϸ鼭 �߰��Ѵ�.
		(�ߺ� �����ʹ� ���� ������ ����)
		���� �ڽ� ����� �� < �θ� ����� �� < ������ �ڽ� ����� ��
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
Function name	: inorderTraverse() - ���� ��ȸ(���� ������ ���)
Parameters		: np - �湮�� ����� �ּ�
Returns			: ����
--------------------------------------------------------------*/
void inorderTraverse(node_t *np) {

	/*
		���� subtree�� �湮
		�ش� ��� �湮
		������ subtree�� �湮
		(Tip) ��� ȣ��� �ڵ� ����
	*/

	if (np != NULL) {
		inorderTraverse(np->left);
		printf("%d ", np->data);
		inorderTraverse(np->right);
	}
}

/*--------------------------------------------------------------
Function name	: preorderTraverse() - ���� ��ȸ
Parameters		: np - �湮�� ����� �ּ�
Returns			: ����
--------------------------------------------------------------*/
void preorderTraverse(node_t *np) {

	/*
		�ش� ��� �湮
		���� subtree�� �湮
		������ subtree�� �湮
		(Tip) ��� ȣ��� �ڵ� ����
	*/

	if (np != NULL) {
		printf("%d ", np->data);
		preorderTraverse(np->left);
		preorderTraverse(np->right);
	}
}

/*--------------------------------------------------------------
Function name 	: postorderTraverse() - ���� ��ȸ
Parameters		: np - �湮�� ����� �ּ�
Returns			: ����
--------------------------------------------------------------*/
void postorderTraverse(node_t *np) {
	/*
		TO DO
		���� subtree�� �湮
		������ subtree�� �湮
		�ش� ��� �湮
		(Tip) ��� ȣ��� �ڵ� ����
	*/


	if (np != NULL) {
		postorderTraverse(np->left);
		postorderTraverse(np->right);
		printf("%d ", np->data);
	}
}

/*-------------------------------------------------------------
Function name	: searchNode() - data�� �ش��ϴ� ��� �˻�
Parameters		: tp - Tree ����ü�� �ּ�
				  data - �˻��� ������
Returns			: ã�� ����� �ּ�
				  �� ã���� NULL pointer
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
Function name	: deleteNode() - data�� �ش��ϴ� ��� ����
Parameters	 	: tp - Tree ����ü�� �ּ�
				  data - ������ ������
Returns			: ���� �� 1
				  ���� �� 0
--------------------------------------------------------------*/
int deleteNode(tree_t *tp, int data) {
	/*
		(1) tree�� ù��� ���� ���� level�� �������鼭 ������ ��� �˻�

		    ������ ����� parent ���� ���� ��带 ������ ����� �ϹǷ� �˻� �� parent ����� ���� ���ؾ� ��
		(2) ������ ��� ��� parent����� ���ο� �ڽ�(son) ������ �� ��� �����ϱ�
		(2-1) ����1 : ������ ����� �ڽ��� 2�� �� ��� (���� ����Ʈ������ ��ü��� ã��)
		(2-2) ����2 : ��������� �ڽ��� ���� ���
		(2-3) ����3 : ������ ����� �ڽ��� 1�� �� ���
	*/

	node_t *delNode;			// �������
	node_t *delParentNode;		// ��������� �θ���
	node_t *changeNode;			// ��ü���
	node_t *changeParentNode;	// ��ü����� �θ���

	delNode = tp->root;
	delParentNode = delNode;

	/* �������� ��������� �θ��带 �˻��Ѵ�. */
	while (delNode != NULL) {
		/* �����Ͱ� ��ġ�ϸ� */
		if (delNode->data == data) {
			break;
		}

		/* ���� ��带 ��������� �θ���� ���� */
		delParentNode = delNode;
		/* ���� �����Ͱ� �� ���� ��� ���� �ڽ��� �������� */
		if (data < delNode->data) {
			delNode = delNode->left;
		}
		/* ���� �����Ͱ� �� Ŭ ��� ���� �ڽ��� �������� */
		else {
			delNode = delNode->right;
		}
	}

	/* ���� ��尡 �������� ���� ��� */
	if (delNode == NULL) {
		return 0;
	}
	/* ���� ��尡 �����Ѵٸ� */
	else {
		/* �� �ڽ��� ��� �����ϴ� ��� */
		if ((delNode->left != NULL) && (delNode->right != NULL)) {
			/* ������带 ��ü����� �θ���� �����Ѵ�. */
			changeParentNode = delNode;
			/* ��������� ���� �ڽ��� ��ü���� �����Ѵ�. */
			changeNode = delNode->left;

			/* ������ ��ü���κ��� ��ü���� ��ü����� �θ��带 �˻��Ѵ�. */
			while (changeNode->right != NULL) {
				changeParentNode = changeNode;
				changeNode = changeNode->right;
			}

			/* �������� ��ü����� ���� ��ȯ�Ѵ�. */
			int tmp = delNode->data;
			delNode->data = changeNode->data;
			changeNode->data = tmp;

			/* ��������� ���� ��ü����� �θ��� �� ���� ũ�ٸ� ��ü����� ���� �ڽ��� ��ü����� �θ����� ���� �ڽ����� �Ծ��Ѵ�. */
			if (delNode->data > changeParentNode->data) {
				changeParentNode->right = changeNode->left;
			}
			/* ��������� ���� ��ü����� �θ��� �� ���� �۴ٸ� ��ü����� ���� �ڽ��� ��ü����� �θ����� ���� �ڽ����� �Ծ��Ѵ�. */
			else {
				changeParentNode->left = changeNode->left;
			}
			/* ��ü��带 �������� �����Ѵ�. */
			delNode = changeNode;
		}
		/* �� �ڽ��� ��� ���� ��� */
		else if ((delNode->left == NULL) && (delNode->right == NULL)) {
			/* ���� ����� �����Ͱ� ���� ����� �θ� ��庸�� ū ���� ���� ��� */
			if (delNode->data > delParentNode->data) {
				/* ���� ����� �θ� ����� ���� �ڽ��� NULL�� ���� �Ѵ�. */
				delParentNode->right = NULL;
			}
			else {
				/* ���� ����� �θ� ����� ���� �ڽ��� NULL�� ���� �Ѵ�. */
				delParentNode->left = NULL;
			}
		}
		/* �ϳ��� �ڽĸ� ������ ��� */
		else {
			/* ���� ��带 ��ü ����� �θ� ���� �Ѵ�. */
			changeParentNode = delNode;

			/* ���� �ڽ� �� ���� ��� */
			if (delNode->left != NULL) {
				/* ���� �ڽ��� ��ü ��� ��尡 �ȴ�. */
				changeNode = delNode->left;
			}
			/* ���� �ڽ� �� ���� ��� */
			else {
				/* ���� �ڽ��� ��ü ��� ��尡 �ȴ�. */
				changeNode = delNode->right;
			}

			/* ���� ���� ��ü ����� �����͸� ��ü�Ѵ�. */
			int tmp = delNode->data;
			delNode->data = changeNode->data;
			changeNode->data = tmp;

			/* ��ü ����� �ڽ��� ��ü ����� �θ� ��忡 �Ծ��Ѵ�. */
			changeParentNode->left = changeNode->left;
			changeParentNode->right = changeNode->right;

			/* ��ü ��带 ���� ���� �����Ѵ�. */
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
Function name	: destroyTree() - tree ���� ��� ��� ����(tree �Ҹ�)
Parameters		: tp - Tree ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------*/
void destroyTree (tree_t * tp) {

	/*
		postoderDelete()�Լ��� ȣ���Ͽ� tree���� ��� ��� ����
		root ��� NULL pointer������ �ʱ�ȭ, nodeCnt ��� 0���� �ʱ�ȭ
	*/

	postorderDelete(tp->root);
	tp->root = NULL;
	tp->nodeCnt = 0;
}

/*--------------------------------------------------------------
Function name	: postorderDelete() - ���� ��ȸ����� ��� ����
									  (���ȣ�� �Լ�)
Parameters		: np - �湮�� ����� �ּ�
Returns			: ����
--------------------------------------------------------------*/
void postorderDelete(node_t *np) {

	/*
		���� subtree�� �湮
		������ subtree�� �湮
		�ش� ��带 ���� ó��
		(Tip) ��� ȣ��� �ڵ� ����
	*/

	if (np != NULL) {
		postorderDelete(np->left);
		postorderDelete(np->right);
		printf("[%d]���� ", np->data);
		free(np);
	}

}
