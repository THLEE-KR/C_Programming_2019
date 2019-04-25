#ifndef LISTSTACK_H_
#define LISTSTACK_H_

typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _node {
	int data;					/* int ������ ���� */
	struct _node *next;			/* ���� ��带 ����Ű�� ������ ���� */
} node_t;

typedef struct _stack {			/* stack ���� ����ü */
	node_t *head;				/* head pointer(head node ����Ŵ) */
	node_t *tail;				/* tail pointer(tail node ����Ŵ) */
} stack_t;

bool_t createStack(stack_t *sp);		/* ��ũ�� ����Ʈ�� �����Ǵ� ���� ���� �Լ� */
bool_t isStackEmpty(stack_t *sp);		/* ������ ������ ��� �ִ°� �˻� */
bool_t push(stack_t *sp, int indata);	/* ���ÿ� ������ �����ϴ� �Լ� */
bool_t pop(stack_t *sp, int *popData);	/* ���ÿ��� �����͸� ������ �Լ� */
/* ���� ���� ��� �����͸� ����ϴ�  �Լ� */
void printStack(const stack_t *sp);
void destroyStack(stack_t *sp);			/* ���� �޸� ���� �Լ� */

#endif /* LISTSTACK_H_ */
