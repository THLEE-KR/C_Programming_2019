#include<stdio.h>
int  main()
{
	int  i, k = 1;
	for (i = 0; i<sizeof(int) * 8; i++) {
		printf("%d회 left shift  =  %d \n", i + 1, k = k << 1);
	}
	getchar();
	return 0;
}
