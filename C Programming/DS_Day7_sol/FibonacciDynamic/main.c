#include <stdio.h>
#define MAX 100000

unsigned long long int DT[MAX + 1];
unsigned long long int f(int n);

unsigned long long int f(int n) {
	if (n <= 2) {
		return 1ULL;
	}
	else {
		if (DT[n] == 0) {
			DT[n] = f(n - 1) + f(n - 2);
		}
		return DT[n];
	}
}

int main(void) {
	int i;
	long long int result;

	printf("N : Fibonacci Number\n");
	for (i=1 ; i<50 ; i++) {
		result = f(i);
		printf("%d : %I64d\n", i, result);
	}

	return 0;
}
