#include<stdio.h>
int  main()
{
	int  num = 0x0f0f0f0f  ,  res ;
	res  =  ~ num ;
	printf ( "num = %#x     res = %#x \n" , num , res ) ;

	getchar();
	return  0;
}
