#include<stdio.h>
int temp=3; // extern ���� ���Ǻ�

void  sub()
{
	temp += 100;
	printf("sub() temp = %d \n" , temp);
}
