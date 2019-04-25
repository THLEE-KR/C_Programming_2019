#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ListStack.h"
#define MAX 10

int main(void) {
	int i;
	stack_t stack;
	int r;
	srand((unsigned int)time(NULL));

	createStack(&stack);

	printf("***** 입력값  *****\n");
	for (i=0 ; i<MAX ; i++) {
		r = rand() % MAX + 1;
		printf("%2d ", r);
		if (push(&stack, r) == TRUE) {
			printf("입력성공!!!\n");
		}
		else {
			printf("입력실패!!!\n");
		}
	}
	
	printStack(&stack);
	pop(&stack, &r);
	pop(&stack, &r);
	pop(&stack, &r);
	printStack(&stack);
	
	/*printf("출력값 : ");
	while (!isStackEmpty(&stack)) {
		if (pop(&stack, &r) == TRUE) {
			printf("%d ", r);
		}
	}
	printf("\n");
	*/
	
	destroyStack(&stack);
	return 0;
}
