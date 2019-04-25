#include<stdio.h>
#define LIMIT 100
void sub();
int main()
{
	printf("%d\n", LIMIT);
	sub();
	printf("%d\n", LIMIT);
	getchar();
	return 0;
}
void sub()
{
#undef LIMIT
#define LIMIT 150
	printf("%d\n", LIMIT);
}
