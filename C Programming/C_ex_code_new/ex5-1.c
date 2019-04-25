#include  <stdio.h>
#define   PRINT(x)   printf(#x " = %d\n", x)

int main()
{
	int  a = 5, b = 10;
	PRINT(a + b) ;
	PRINT(a * 3) ;
	PRINT(b / 5) ;
	PRINT( (100 + a) * 2 ) ;

	getchar();
	return 0;
}
