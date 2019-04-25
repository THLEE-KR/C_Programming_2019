#include <stdio.h>
#define MAX 10
void printArray(int k);

int L[MAX];

void f(int n, int k) {
	int i;

	if (n == k) {
		printArray(k);
		return;
	}
	else {
		for (i=1 ; i<=k ; i++) {
			L[n] = k-i+1;
			f(n + 1, k);
		}
	}
}

int main(void) {
	f(0, 3);
	return 0;
}
void printArray(int k){
	int i;
	for (i=0 ; i<k ; i++) {
		printf("%2d", L[i]);
	}
	printf("\n");
}
