#include<stdio.h>
int temp=3; // extern 변수 정의부

void  sub()
{
	temp += 100;
	printf("sub() temp = %d \n" , temp);
}
