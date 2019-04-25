#ifndef LISTSTACK_H_
#define LISTSTACK_H_

typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _node {
	int data;					/* int 데이터 영역 */
	struct _node *next;			/* 다음 노드를 가리키는 포인터 영역 */
} node_t;

typedef struct _stack {			/* stack 관리 구조체 */
	node_t *head;				/* head pointer(head node 가리킴) */
	node_t *tail;				/* tail pointer(tail node 가리킴) */
} stack_t;

bool_t createStack(stack_t *sp);		/* 링크드 리스트로 관리되는 스택 생성 함수 */
bool_t isStackEmpty(stack_t *sp);		/* 스택이 완전히 비어 있는가 검사 */
bool_t push(stack_t *sp, int indata);	/* 스택에 데이터 저장하는 함수 */
bool_t pop(stack_t *sp, int *popData);	/* 스택에서 데이터를 꺼내는 함수 */
/* 스택 내의 모든 데이터를 출력하는  함수 */
void printStack(const stack_t *sp);
void destroyStack(stack_t *sp);			/* 스택 메모리 해제 함수 */

#endif /* LISTSTACK_H_ */
