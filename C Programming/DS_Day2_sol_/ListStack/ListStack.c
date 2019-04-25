#include <stdio.h>
#include <stdlib.h>
#include "ListStack.h"

/* --------------------------------------------------------------------------------------------------------------
Function name	: createStack() - 링크드 리스트로 관리되는 스택 생성 함수
Parameters		: sp - 스택 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
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
Function name	: isStackEmpty() - 스택이 완전히 비어 있는지 검사
Parameters		: sp - 스택 관리 구조체의 주소
Returns			: 스택이 완전히 비어 있으면 TRUE 리턴, 아니면 FALSE 리턴
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
Function name	: push() - 스택에 데이터 하나를 저장함
Parameters		: sp - 스택 관리 구조체의 주소
				  pushData - 스택에 저장할 데이터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
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
Function name	: pop() - 스택에서 데이터 하나를 꺼냄
Parameters		: sp - 스택 관리 구조체의 주소
				  popData -  꺼낸 데이터를 저장할 기억 공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
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
Function name	: printStack() - 스택의 모든 데이터 출력
								(pop하면 나오는 순서대로 출력)
Parameters		: sp - 스택 관리 구조체의 주소
Returns		: 없음
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
Function name	: destroyStack() -  스택 소멸 함수
Parameters		: sp - 스택 관리 구조체의 주소
Returns			: 없음
---------------------------------------------------------------------------------------------------------------*/
void destroyStack(stack_t *sp) {

	node_t *cur;

	if (sp == NULL) {
		return;
	}

	cur = sp->head->next;
	while (cur != sp->tail) {
		sp->head->next = cur->next;
		//printf("[%d] ", cur->data); // 해제 데이터 출력 
		free(cur);
		cur = sp->head->next;
	}
	free(sp->head);
	free(sp->tail);
	sp->head = NULL;
	sp->tail = NULL;
}
