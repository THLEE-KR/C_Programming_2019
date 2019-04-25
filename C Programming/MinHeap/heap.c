#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/*--------------------------------------------------------------
Function name	: createHeap() - 힙 생성 함수
Parameters		: hp - 힙 구조체의 주소
				  size - 힙의 크기(저장 가능한 데이터의 개수)
Returns			: 생성 성공하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------*/
bool_t createHeap(heap_t *hp, int size) {

	if (hp == NULL) {
		return FALSE;
	}

	hp->heap = (int *)calloc(size + 1, sizeof(int));
	if (hp->heap == NULL) {
		return FALSE;
	}

	hp->size = size;
	hp->count = 0;

	return TRUE;
}

/*--------------------------------------------------------------
Function name	: isHeapEmpty() - 힙이 완전히 비어 있는가 검사
Parameters		: hp - 힙 구조체의 주소
Returns			: 완전히 비어 있으면 TRUE
				  비어 있지 않으면 FALSE
--------------------------------------------------------------*/
bool_t isHeapEmpty(heap_t *hp) {

	if (hp->count == 0) {
		return TRUE;
	}
	return FALSE;
}

/*--------------------------------------------------------------
Function name	: isHeapFull() - 힙이 꽉 차 있는가 검사
Parameters		: hp - 힙 구조체의 주소
Returns			: 꽉 차 있으면 TRUE
				  꽉 차 있지 않으면 FALSE 리턴
--------------------------------------------------------------*/
bool_t isHeapFull(heap_t *hp) {

	if (hp->count == hp->size) {
		return TRUE;
	}
	return FALSE;
}

/*--------------------------------------------------------------
Function name	: insertHeap () - 힙에 데이터  하나를 추가
Parameters		: hp - 힙 구조체의 주소
				  intData - 힙에 저장할 데이터
Returns			: 성공적으로 삭제하면 TRUE 리턴, 실패하면 FALSE 리턴
--------------------------------------------------------------*/
bool_t insertHeap(heap_t *hp, int inData) {

	if (hp == NULL) {
		return FALSE;
	}

	if (isHeapFull(hp)) {
		return FALSE;
	}

	hp->count++;
	hp->heap[hp->count] = inData;
	reHeapUp(hp, hp->count);

	return TRUE;
}

/*----------------------------------------------------------------------
Function name	: deleteDownHeap() - 힙에 데이터 하나를 삭제
Parameters		: hp - 힙 구조체의 주소
				  getData - 힙에 꺼낸 데이터 저장변수의 주소
Returns			: 성공적으로 삭제하면 TRUE, 실패하면 FALSE
----------------------------------------------------------------------*/
bool_t deleteHeap(heap_t *hp, int *getData) {

	if (hp == NULL) {
		return FALSE;
	}

	if (isHeapEmpty(hp)) {
		return FALSE;
	}
	
	*getData = hp->heap[1];
	hp->heap[1] = hp->heap[hp->count];
	hp->count--;
	reHeapDown(hp, 1);

	return TRUE;
}

/*--------------------------------------------------------------
Function name	: reHeapUp() - 지정 노드를 위치에 맞게 down 시킴
Parameters		: hp - 힙 구조체의 주소
				  child - heapUp 대상 인덱스
Returns			: 없음
--------------------------------------------------------------*/
void reHeapUp(heap_t *hp, int child) {

	int parent;
	int tmp;
	if (hp == NULL) {
		return;
	}
	while (child > 1) {
		parent = child / 2;
		if (hp->heap[parent] <= hp->heap[child]) {
			break;
		}
		tmp = hp->heap[parent];
		hp->heap[parent] = hp->heap[child];
		hp->heap[child] = tmp;
		child = parent;
	}
}

/*--------------------------------------------------------------
Function name	: reHeapDown() - 지정 노드를 위치에 맞게 down 시킴
Parameters		: hp - 힙 구조체의 주소
				  child - heapDown 대상 데이터 인덱스
Returns			: 없음
--------------------------------------------------------------*/
void reHeapDown(heap_t *hp, int parent) {
	int left, right;
	int min, tmp;
	if(hp==NULL){
		return;
	}
	while (1) {
		left = parent * 2;
		right = (parent * 2) + 1;
		if (left > hp->count) {
			break;
		}
		if (left == hp->count) {
			min = left;
		}
		else if (hp->heap[left] < hp->heap[right]) {
			min = left;
		}
		else {
			min = right;
		}
		if (hp->heap[parent] <= hp->heap[min]) {
			break;
		}
		tmp = hp->heap[parent];
		hp->heap[parent] = hp->heap[min];
		hp->heap[min] = tmp;
		parent = min;
	}
}

/*--------------------------------------------------------------
Function name	: printHeape() - 힙 내의 데이터 출력(상위->하위 방향)
Parameters		: hp - 힙 구조체의 주소
Returns			: 없음
--------------------------------------------------------------*/
void printHeap(const heap_t *hp) {

	int i;
	if(hp==NULL){
		return;
	}
	for (i=1 ; i<=hp->count ; i++) {
		printf("%d ", hp->heap[i]);
	}
	printf("\n");

}

/*--------------------------------------------------------------
Function name	: destroyHeap() - 힙 소멸 함수
Parameters		: hp - 힙 구조체의 주소
Returns			: 없음
--------------------------------------------------------------*/
void destroyHeap(heap_t *hp) {

	if (hp == NULL) {
		return;
	}

	free(hp->heap);
	hp->heap = NULL;
	hp->size = 0;
	hp->count = 0;

}
