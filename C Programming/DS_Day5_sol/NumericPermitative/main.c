#include <stdio.h>
#define MAX 10
void printArray(int m);
int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int L[MAX];
int used[MAX];

void f(int n, int k) {
	int i;

	if (n == k) {
		printArray(k);
	}
	else {
		for (i=0 ; i<k ; i++) {
			if (used[i] == 0) {
				used[i] = 1;
				L[n] = a[i];
				f(n + 1, k);
				used[i] = 0;
			}
		}
	}
}

int main(void) {
	f(0, 4);
	return 0;
}

void printArray(int m){
	int i;
	for (i=0 ; i<m ; i++) {
		printf("%3d", L[i]);
	}
	printf("\n");
}
