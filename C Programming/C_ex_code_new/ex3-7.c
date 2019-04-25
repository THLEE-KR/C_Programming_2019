#include<stdio.h>
int  main()
{
	int ary[10] = { 1,2,3,4,5,-5,-4,-3,-2,-1 };
	unsigned int n;
	
	printf("Input Index = ");
	scanf("%u", &n);

	if ((n < 10) && ary[n] >= 0) {
		printf("In range : Positive or Zero\n");
	}
	else if((n < 10) && ary[n] < 0) {
		printf("In range : Negative\n");
	}
	else {
		printf("Out of range");
	}
	getchar();
	return 0;
}