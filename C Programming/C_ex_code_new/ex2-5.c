#include <stdio.h>
void  sum() ;
int   temp ;
int main()
{
	int  a = 10 ;
	sum () ;
	printf("temp = %d \n" , temp) ;
	printf("a = %d \n" , a) ;

	getchar();
	return 0;
}
void  sum ()
{
	temp += 100 ;
	/* printf(¡°a = %d \n¡± , a) ; */
}
