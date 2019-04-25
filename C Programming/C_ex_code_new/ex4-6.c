#include<stdio.h>
void sub();
int  main()
{
	int  num ;
	scanf("%d",&num) ;
	if (num < 0)  goto  LB1 ;
	else  goto  LB2 ;

	LB1 :
	printf("LB1...\n" ) ;


	LB2 :
	printf("LB2...\n" ) ;

	getchar(); getchar();
	return 0;
}
void sub()
{
	LB3 :
	printf("LB3...\n" ) ;
}
