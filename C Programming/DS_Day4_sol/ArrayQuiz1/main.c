#include <stdio.h>
#define MAX 10


int main(void) {
	freopen("data.txt", "r", stdin);
    int D[MAX][MAX];
	int i;
	int j;
	int k;
	int m;

	int N;
	int M;
	int W;
	int H;
	int sum;
	int max;
	int maxR;
	int maxC;

	scanf("%d %d %d %d", &N, &M, &W, &H);
	for (i=0 ; i<N ; ++i) {
		for (j=0 ; j<M ; ++j) {
			scanf("%d", &D[i][j]);
		}
	}

	max = 0;
	maxR = 0;
	maxC = 0;
	for (i=0 ; i<=(N - W) ; ++i) {
		for (j=0 ; j<=(M - H) ; ++j) {

			sum = 0;
			for (k=0 ; k<W ; ++k) {
				for (m=0 ; m<H ; ++m) {
					sum += D[i + k][j + m];
				}
			}
			if (sum > max) {
				maxR = i;
				maxC = j;
				max = sum;
			}
		}
	}

	for (i=0 ; i<N ; ++i) {
		for (j=0 ; j<M ; ++j) {
			printf("%2d", D[i][j]);
		}
		printf("\n");
	}

	printf("최대 인구 밀도 : %d\n", max);
	printf("최대 인구 지역 : %d, %d\n", maxR, maxC);
	printf("\n");

	return 0;
}
