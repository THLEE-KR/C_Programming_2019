#include<stdio.h>
int main()
{
	float x = 0.1;
	int i = 1;
	for (i = 1; i <= 10; i++){
		printf("%d. x = %.10f\n", i, x);
		x += 0.1f;
	}

	getchar();
	return 0;
}
