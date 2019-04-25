#include<stdio.h>
int main()
{
	int  i,  s = 0 ;
	for( i = 1 ; i <= 10 ; i++ ) {
		printf("i = %d\n", i) ;
		s += i ;
	}
	printf("1 ~ %d = %d \n", i, s) ;

	getchar();
	return 0;
}
