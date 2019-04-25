#include <stdio.h>
#include <stdlib.h>
#include "ListStack.h"

/* --------------------------------------------------------------------------------------------------------------
Function name	: createStack() - ��ũ�� ����Ʈ�� �����Ǵ� ���� ���� �Լ�
Parameters		: sp - ���� ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
---------------------------------------------------------------------------------------------------------------*/
bool_t createStack(stack_t *sp) {
	if (sp == NULL) {
		return FALSE;
	}

	sp->head = (node_t *)calloc(1, sizeof(node_t));
	if (sp->head == NULL) {
		return FALSE;
	}

	sp->tail = (node_t *)calloc(1, sizeof(node_t));
	if (sp->tail == NULL) {
		free(sp->head);
		return FALSE;
	}

	sp->head->next = sp->tail;
	sp->tail->next = sp->tail;

	return TRUE;
}

/* --------------------------------------------------------------------------------------------------------------
Function name	: isStackEmpty() - ������ ������ ��� �ִ��� �˻�
Parameters		: sp - ���� ���� ����ü�� �ּ�
Returns			: ������ ������ ��� ������ TRUE ����, �ƴϸ� FALSE ����
---------------------------------------------------------------------------------------------------------------*/
bool_t isStackEmpty(stack_t *sp) {
	
	if (sp == NULL) {
		return TRUE;
	}
	
	if (sp->head->next == sp->tail) {
		return TRUE;
	}
	return FALSE;
}

/* --------------------------------------------------------------------------------------------------------------
Function name	: push() - ���ÿ� ������ �ϳ��� ������
Parameters		: sp - ���� ���� ����ü�� �ּ�
				  pushData - ���ÿ� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
---------------------------------------------------------------------------------------------------------------*/
bool_t push(stack_t *sp, int pushData) {

	node_t *node;
	if (sp == NULL) {
		return FALSE;
	}

	node = (node_t *)calloc(1, sizeof(node_t));
	if (node == NULL) {
		return FALSE;
	}

	node->data = pushData;
	node->next = sp->head->next;
	sp->head->next = node;

	return TRUE;
}

/* --------------------------------------------------------------------------------------------------------------
Function name	: pop() - ���ÿ��� ������ �ϳ��� ����
Parameters		: sp - ���� ���� ����ü�� �ּ�
				  popData -  ���� �����͸� ������ ��� ������ �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
---------------------------------------------------------------------------------------------------------------*/
bool_t pop(stack_t *sp, int *popData) {

	node_t *del;
	if (sp == NULL) {
		return FALSE;
	}

	if (isStackEmpty(sp)==TRUE) {
		return FALSE;
	}

	del = sp->head->next;
	*popData = del->data;
	sp->head->next = del->next;
	free(del);

	return TRUE;
}

/* --------------------------------------------------------------------------------------------------------------
Function name	: printStack() - ������ ��� ������ ���
								(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���� ���� ����ü�� �ּ�
Returns		: ����
---------------------------------------------------------------------------------------------------------------*/
void printStack(const stack_t *sp) {
	node_t *cur;

	if (sp == NULL) {
		return;
	}
	if (isStackEmpty((stack_t *)sp)==TRUE) {
		return;
	}

	cur = sp->head->next;
	while (cur != sp->tail) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/* --------------------------------------------------------------------------------------------------------------
Function name	: destroyStack() -  ���� �Ҹ� �Լ�
Parameters		: sp - ���� ���� ����ü�� �ּ�
Returns			: ����
---------------------------------------------------------------------------------------------------------------*/
void destroyStack(stack_t *sp) {

	node_t *cur;

	if (sp == NULL) {
		return;
	}

	cur = sp->head->next;
	while (cur != sp->tail) {
		sp->head->next = cur->next;
		//printf("[%d] ", cur->data); // ���� ������ ��� 
		free(cur);
		cur = sp->head->next;
	}
	free(sp->head);
	free(sp->tail);
	sp->head = NULL;
	sp->tail = NULL;
}
