#include <stdio.h>
void  sub();
extern int   temp;  // extern���� �����
int main()
{
	printf("main() temp = %d \n", temp);
	sub();
	printf("main() temp = %d \n", temp);
	getchar();
	return 0;
}
