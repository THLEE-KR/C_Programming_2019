#include<stdio.h>
int main()
{
	int  ary[5]  =  { 1, 3, 5, 7, 9 } ;
	int  i, sum ;
	for ( i = sum = 0  ;  i < 5  ;  i++ ) {
		printf("ary[%d] = %d\n", i, ary[i]);
		sum += ary[i] ;
	}
	printf("sum = %d\n" , sum ) ;

	getchar();
	return 0;
}
