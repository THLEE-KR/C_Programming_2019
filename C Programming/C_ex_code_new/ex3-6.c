#include<stdio.h>
int  main()
{
	int a = 0, b = 0;
	a++;  b++;
	printf ("a = %d  b = %d \n", a , b );
	b = a++;
	printf ("a = %d  b = %d \n", a , b );
	b = ++a;
	printf ("a = %d  b = %d \n", a , b );
	printf ("a = %d  b = %d \n", a ++,  ++b );
	printf ("a = %d  b = %d \n", a , b );

	getchar();
	return  0;
}
