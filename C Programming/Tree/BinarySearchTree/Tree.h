#ifndef TREE_H_
#define TREE_H_

typedef struct _node {
	int data;   							/* ������ ���� ��� */
	struct _node *left; 					/* ���� �ڽ� ��带 ����Ű�� ������ ��� */
	struct _node *right;					/* ������ �ڽ� ��带 ����Ű�� ������ ��� */
} node_t;

typedef struct _tree {
	node_t *root; 							/* Ʈ���� head node�� ����Ű�� ������ ��� */
	int nodeCnt; 							/* �� ����� ���� */
} tree_t;

void initTree(tree_t *tp);					/* Ʈ�� ���� ����ü�� �ʱ�ȭ �ϴ� �Լ� */
node_t *makeNode(int data);					/* �� ��带 �����Ͽ� ��ȯ�ϴ� �Լ� */
node_t *addNode(tree_t *tp, int data);		/* ��带 �����ϴ� �Լ� */
void inorderTraverse(node_t *np); 			/* ������ȸ(���� ������ ���) */
void preorderTraverse(node_t *np);			/* ������ȸ */
void postorderTraverse(node_t *np); 		/* ������ȸ */
node_t *searchNode(tree_t *tp, int data);	/* data�� �ش��ϴ� ��� �˻� �Լ� */
int deleteNode(tree_t *tp, int data);		/* data�� �ش��ϴ� ��� ���� �Լ� */
void destroyTree (tree_t *tp);				/* tree���� ��� ��� ���� �Լ� */
void postorderDelete(node_t *np);			/* postorder(���� ��ȸ)����� ��� ���� ���ȣ�� �Լ� */

#endif /* TREE_H_ */
