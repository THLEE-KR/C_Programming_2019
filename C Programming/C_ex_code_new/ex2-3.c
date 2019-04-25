#include <stdio.h>
int  a=7;
void sub1(int);
void sub2(int);
int main()
{
	int a=10;

	sub1(a);
	sub2(a);
	printf("main a = %d\n", a);

	getchar();
	return 0;
}
void  sub1(int  a)
{
	a*=2;
	printf("sub1 a = %d\n", a);
}

void  sub2(int  x)
{
	x*=3;
	printf("sub2 x = %d\n", x);
	printf("sub2 a = %d\n", a);
}

