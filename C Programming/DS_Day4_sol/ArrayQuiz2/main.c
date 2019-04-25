#include <stdio.h>
#define MAX 100
int D[MAX][MAX];

int main(void) {
	int i;
	int j;
	int t;
	int r;
	int b;
	int m;

	int N;
	int num;

	scanf("%d", &N);

	num = 1;
	for (i=0 ; i<(N/2) ; i++) {
		for (t=i ; t<(N-i-1) ; ++t) {
			D[i][t] = num++;
		}

		for (r=i ; r<(N-i-1) ; ++r) {
			D[r][N-i-1] = num++;
		}

		for (b=(N-i-1) ; b>i ; --b) {
			D[N-i-1][b] = num++;
		}

		for (m=(N-i-1) ; m>i ; --m) {
			D[m][i] = num++;
		}
	}
	if ((N % 2) == 1) {
		D[N / 2][N / 2] = num;
	}

	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			printf("%3d", D[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
