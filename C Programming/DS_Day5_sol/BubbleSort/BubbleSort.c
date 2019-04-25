#include <stdio.h>
#include <time.h>		/* time() */
#include <stdlib.h>		/* rand(), srand() */
#include "BubbleSort.h"

void initArray(int *ary, int n) {
	int i;
	for(i=0; i<n; ++i) {
		ary[i] = rand() % 20 + 1;
	}
}

void printArray(int *ary, int n) {
	int i;
	printf("배열 내용 : ");
	for(i=0; i<n; ++i) {
		printf("%4d", ary[i]);
	}
	printf("\n");
}

/*----------------------------------------------------------------
Function Name	: bubbleSort() - 거품정렬 함수
Argument		: ary - 정렬 데이터 저장 배열
 	 	 	 	  n - 배열 원소의 수
Return			: 없음
----------------------------------------------------------------*/
void bubbleSort(int *ary, int n) {
    /*
     * TO DO
     */
	int i;
	int j;
	int temp;

	for (i=(n-1) ; i>0 ; --i) {
		for (j=0 ; j<i ; j++) {
			if (ary[j] > ary[j+1]) {
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
}
