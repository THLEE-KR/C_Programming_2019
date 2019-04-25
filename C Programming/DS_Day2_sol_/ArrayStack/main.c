#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "stack.h"
#define MAX 5
int main(void) {
	stack_t stack;
	int r;
	int i;
	srand((unsigned int)time(NULL));

	if(createStack(&stack, MAX)==FALSE){
		return 1;
	}

	printf("***** 입력값  *****\n");
	for (i=0 ; i<(MAX+1) ; i++) {
		r = rand() % MAX + 1;
		printf("%d ", r);
		if (push(&stack, r) == TRUE) {
			printf("입력성공!!!\n");
		}
		else {
			printf("입력실패!!!\n");
		}
	}

	printf("출력값 : ");
	while (!isStackEmpty(&stack)) {
		if (pop(&stack, &r) == TRUE) {
			printf("%d ", r);
		}
	}
	printf("\n"); 
	
	destroyStack(&stack);
	
	return 0;
}
