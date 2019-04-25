#include <stdio.h>
#include "heap.h"

int main(void) {
	int num;
	int cnt;
	heap_t heap;
	int i;

	freopen("data.txt", "r", stdin);

	createHeap(&heap, MAX);
	scanf("%d", &cnt);
	for (i=0 ; i<cnt ; i++) {
		scanf("%d", &num);
		insertHeap(&heap, num);
	}
	printHeap(&heap);

	for (i=0 ; i<=cnt ; i++) {
		deleteHeap(&heap, &num) ? printf("[%d]출력\n", num) : printf("출력실패!!!\n");
		printHeap(&heap);
	}

	destroyHeap(&heap);

	return 0;
}
