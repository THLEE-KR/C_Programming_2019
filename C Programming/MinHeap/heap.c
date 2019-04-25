#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/*--------------------------------------------------------------
Function name	: createHeap() - �� ���� �Լ�
Parameters		: hp - �� ����ü�� �ּ�
				  size - ���� ũ��(���� ������ �������� ����)
Returns			: ���� �����ϸ� TRUE, �����ϸ� FALSE ����
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
Function name	: isHeapEmpty() - ���� ������ ��� �ִ°� �˻�
Parameters		: hp - �� ����ü�� �ּ�
Returns			: ������ ��� ������ TRUE
				  ��� ���� ������ FALSE
--------------------------------------------------------------*/
bool_t isHeapEmpty(heap_t *hp) {

	if (hp->count == 0) {
		return TRUE;
	}
	return FALSE;
}

/*--------------------------------------------------------------
Function name	: isHeapFull() - ���� �� �� �ִ°� �˻�
Parameters		: hp - �� ����ü�� �ּ�
Returns			: �� �� ������ TRUE
				  �� �� ���� ������ FALSE ����
--------------------------------------------------------------*/
bool_t isHeapFull(heap_t *hp) {

	if (hp->count == hp->size) {
		return TRUE;
	}
	return FALSE;
}

/*--------------------------------------------------------------
Function name	: insertHeap () - ���� ������  �ϳ��� �߰�
Parameters		: hp - �� ����ü�� �ּ�
				  intData - ���� ������ ������
Returns			: ���������� �����ϸ� TRUE ����, �����ϸ� FALSE ����
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
Function name	: deleteDownHeap() - ���� ������ �ϳ��� ����
Parameters		: hp - �� ����ü�� �ּ�
				  getData - ���� ���� ������ ���庯���� �ּ�
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE
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
Function name	: reHeapUp() - ���� ��带 ��ġ�� �°� down ��Ŵ
Parameters		: hp - �� ����ü�� �ּ�
				  child - heapUp ��� �ε���
Returns			: ����
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
Function name	: reHeapDown() - ���� ��带 ��ġ�� �°� down ��Ŵ
Parameters		: hp - �� ����ü�� �ּ�
				  child - heapDown ��� ������ �ε���
Returns			: ����
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
Function name	: printHeape() - �� ���� ������ ���(����->���� ����)
Parameters		: hp - �� ����ü�� �ּ�
Returns			: ����
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
Function name	: destroyHeap() - �� �Ҹ� �Լ�
Parameters		: hp - �� ����ü�� �ּ�
Returns			: ����
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
