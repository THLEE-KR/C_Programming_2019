#include <stdio.h>
#include "nqueen.h"

int main(void) {
	int i;

	for (i=1 ; i<=MAX_CNT ; i++) {
		N = i;
		placementCnt = 0;

		nQueen(1);
		printf("N = %2d  ��ġ ���� ����� �� : %d\n", N, placementCnt);
	}

	return 0;
}
