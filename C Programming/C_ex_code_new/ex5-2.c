#include<stdio.h>
#define MAKENAME(variable, number)  variable##number
#define PRN(var, num) printf(#var #num"=%d\n", MAKENAME(var, num))
int main()
{
	int MAKENAME(a,1) = 10;
	int MAKENAME(x,2) = 20;
	PRN(a,1);
	PRN(x,2);
	//PRN(y,3);

	getchar();
	return 0;
}
