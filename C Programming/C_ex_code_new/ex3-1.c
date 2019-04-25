#include<stdio.h>
int  main()
{
	int  x = 5, *ptr ;
	ptr = &x ;
	printf ( "%p  %p  %p  %d  %d \n" , &ptr , ptr , &x , x ,*ptr);
	getchar();
	return  0;
}
