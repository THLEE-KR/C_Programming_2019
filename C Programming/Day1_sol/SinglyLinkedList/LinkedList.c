#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*----------------------------------------------------------------
Function name	: createList() - 연결 리스트 생성 및 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------*/
bool_t createList(list_t *lp) {

	if(lp==NULL){
		return FALSE;
	}
	lp->head = (node_t *) malloc(sizeof(node_t));  // head node 할당 
	if(lp->head==NULL){
		return FALSE;
	}
	lp->tail = (node_t *) malloc(sizeof(node_t)); // tail node 할당
	if(lp->tail == NULL){
		free(lp->head);
		return FALSE;
	}
	lp->head->next = lp->tail;
	lp->tail->next = lp->tail;
	lp->size = 0;

	return TRUE;
}

/*--------------------------------------------------------------
Function name	: addFirst() - head node 뒤에 node 추가(역순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
--------------------------------------------------------------*/
bool_t addFirst(list_t *lp, int data) {
	if(lp==NULL){
		return FALSE;
	}
	newp = (node_t *) malloc(sizeof(node_t)); 
	if(newp==NULL){
		return FALSE;
	}
	newp->data = data;
	newp->next = lp->head->next;
	lp->head->next = newp;
	
	lp->size++;
	
	return TRUE;
}


/*----------------------------------------------------------------
Function name	: 	addLast() - tail node 앞에 새 node 추가(정순 저장)
Parameters		: 	lp - 리스트 관리 구조체의 주소
					data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------*/
bool_t addLast(list_t *lp, int data) {

	node_t *pp, *newp;
	if(lp==NULL){
		return FALSE;
	}
	newp = (node_t *) malloc(sizeof(node_t));
	if(newp == NULL){
		return FALSE;
	}
	pp = lp->head;
	while(pp->next != lp->tail){
		pp = pp->next;
	}
	newp->data = data;
	pp->next = newp;
	newp->next = lp->tail;
	lp->size++;
	return TRUE;
}

/*----------------------------------------------------------------
Function name	: displayList() - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------*/
void displayList(list_t *lp) {

	/* lp포인터 NULL check */
	/* 첫 번째 데이터 노드를 지정한 후 */
	/* 마지막 노드까지의 데이터를 출력한다. */
	node_t *tp;
	if(lp==NULL){
		return;
	}
	tp = lp->head->next;
	while(tp != lp->tail){
		printf("%5d", tp->data);
		tp=tp->next;
	}
	printf("\n");
}

/*----------------------------------------------------------------
Function name	: searchNode() - data와 일치하는 첫 번째 node 검색
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 검색할 데이터
Returns			: 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
----------------------------------------------------------------*/
node_t *searchNode(list_t *lp, int data) {
	node_t *tp;
	if(lp==NULL){
		return NULL;
	}
	
	tp=lp->head->next;
	
	while(tp!=lp->tail){
		if(tp->data == data){
			return tp;
		}
		tp= tp->next;
	}
	return NULL;
}

/*----------------------------------------------------------------
Function name	: removeNode() - data와 일치하는 첫 번째 노드 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 삭제할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------*/
bool_t removeNode(list_t *lp, int data) {
	node_t *pp, *dp;
	if(lp==NULL){
		return FALSE;
	}
	
	pp = lp->head;
	dp = lp->head->next;  // dp = pp->next;
	while(dp != lp->tail){
		if(dp->data == data){
			pp->next = dp->next;
			free(dp);
			lp->size--;
			return TRUE;
		}
		pp = dp;
		dp = dp->next;  // dp = pp->next;
	}
	return FALSE;
}

/*----------------------------------------------------------------
Function name	: sortList() - 노드 정렬(오름차순)
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------*/
void sortList(list_t *lp) {

	node_t *np;
	node_t *tp;
	int tmp;

	if (lp == NULL) {
		return;
	}

	np = lp->head->next;

	while (np->next != lp->tail) {
		while (tp != lp->tail) {
			if (np->data > tp->data) {
				tmp = np->data;
				np->data = tp->data;
				tp->data = tmp;
			}
			tp = tp->next;
		}
		np = np->next;
	}

}

/*----------------------------------------------------------------
Function name	: destoryList - 리스트 내의 모든 노드
				  (head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------*/
void destoryList(list_t *lp) {
	node_t *np, *tp;
	if(lp==NULL){
		return;
	}

	tp=lp->head->next;
	while(tp!=lp->tail){
		np = tp->next;
		//printf("[%d] ", tp->data);
		free(tp);
		tp = np;
	}
	free(lp->head);
	free(lp->tail);
	lp->head = lp->tail = NULL;
	lp->size = 0;
}
