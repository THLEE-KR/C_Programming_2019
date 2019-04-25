#include <stdio.h>
void  sub() ;
int main()
{
	int  i ;
	for ( i = 0 ; i < 3 ; i++ )	{
		sub () ;
		printf("main  i = %d \n" , i) ;
	}

	getchar();
	return  0;
}
void  sub ()
{
	static  int  i = 1;
	auto   int  k = 3;
	printf("sub  i = %d \t k = %d \t" , i++ , k++) ;
}
