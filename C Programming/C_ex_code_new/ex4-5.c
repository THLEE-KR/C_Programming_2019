#include<stdio.h>
int  main()
{
	int   num ;
	for( num = 1 ; num < 10 ; num++ ) {
		if ( num == 5 )  break ;
		printf("%3d", num ) ;
	}

	printf("\n") ;
	for( num = 1 ; num < 10 ; num++ ) {
		if ( num == 5 )  continue ;
		printf("%3d", num ) ;
	}
	getchar();
	return 0;
}
