#include<stdio.h>
int  main()
{
	int a=5, b[10];
	double c[3];
	printf("¡®A¡¯     size  :  %u \n" , sizeof('A') ) ;
	printf("\"A\"  size  :  %u \n" , sizeof("A") ) ;
	printf("\"AB\" size  :  %u \n" , sizeof("AB") ) ;
	printf("5      size  :  %u \n" , sizeof(5) ) ;
	printf("5.0    size  :  %u \n" , sizeof(5.0) ) ;
	printf("5.0f   size  :  %u \n" , sizeof(5.0f) ) ;
	printf("char    size  :  %u \n" , sizeof(char) ) ;
	printf("int      size  :  %u \n" , sizeof(int) ) ;
	printf("float    size  :  %u \n" , sizeof(float) ) ;
	printf("double   size  :  %u \n" , sizeof(double) ) ;
	printf("a         size  :  %u \n" , sizeof(++a) ) ;
	printf("a = %d\n", a);
	printf("b         size  :  %u \n" , sizeof(b) ) ;
	printf("c         size  :  %u \n" , sizeof(c) ) ;
	getchar();
	return  0;
}
