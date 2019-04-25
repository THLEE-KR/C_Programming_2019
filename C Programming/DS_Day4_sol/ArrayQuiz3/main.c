#include <stdio.h>
#define MAX 10

int D[MAX][MAX];

int main(void) {
	int i;
	int j;
	int N;
	int num;

	scanf("%d", &N);
	num = 1;
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<(N - i) ; j++) {
			D[j][j + i] = num++;
		}
	}

	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			printf("%3d", D[i][j]);
		}
		printf("\n");
	}

	return 0;
}
