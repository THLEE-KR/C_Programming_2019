#include <stdio.h>
#include "KnapSack.h"

int dp[MAX + 1][MAX + 1];
int V[MAX + 1];
int W[MAX + 1];
int C;
int J;

void initData(void) {
	int i;
	int j;

	for (i=0 ; i<=MAX ; i++) {
		V[i] = 0;
		W[i] = 0;

		for (j=0 ; j<=MAX ; j++) {
			dp[i][j] = 0;
		}
	}
}

void createData(void) {
	int i;

	scanf("%d %d", &C, &J);
	for (i=1 ; i<=C ; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}
}

void printData(void) {
	int i;

	for (i=1 ; i<=C ; i++) {
		printf("%d %d\n", W[i], V[i]);
	}
}

int calc(void) {
	int i;
	int j;

	/* Dynamic 테이블 초기화 */
	for (i=0 ; i<=C ; i++) {
		for (j=0 ; j<=J ; j++) {
			dp[i][j] = 0;
		}
	}

	for (i=1 ; i<=C ; i++) {
		for (j=1 ; j<=J ; j++) {
			if (W[i] > j) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				if (dp[i-1][j] > (dp[i-1][j-W[i]] + V[i])) {
					dp[i][j] = dp[i-1][j];
				}
				else {
					dp[i][j] = dp[i-1][j-W[i]] + V[i];
				}
			}
		}
	}

	return dp[C][J];
}
