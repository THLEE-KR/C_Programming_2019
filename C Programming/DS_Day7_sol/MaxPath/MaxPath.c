#include <stdio.h>
#include "MaxPath.h"

int map[MAX + 1][MAX + 1];
int dir[MAX + 1][MAX + 1];
int N;

void initMap(void) {
	int i;
	int j;

	for (i=1 ; i<=MAX ; i++) {
		for (j=1 ; j<=MAX ; j++) {
			map[i][j] = 0;
		}
	}
}

void createMap(void) {
	int i;
	int j;

	scanf("%d", &N);
	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=N ; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void printMap(void) {
	int i;
	int j;

	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=N ; j++) {
			printf("%3d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printDir(void) {
	int i;
	int j;

	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=N ; j++) {
			printf("%2d", dir[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int calc(void) {
	int i;
	int j;

	/* Dynamic Table 초기화 */
	for (i=0 ; i<=N ; i++) {
		for (j=0 ; j<=N ; j++) {
			dir[i][j] = 0;
		}
	}

	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=N ; j++) {
			/* 좌측칸의 값이 위쪽칸의 값 보다 크다면 */
			if (map[i][j-1] > map[i-1][j]) {
				map[i][j] +=  map[i][j-1];
				dir[i][j] = LEFT;
			}
			else {
				map[i][j] +=  map[i-1][j];
				dir[i][j] = UP;
			}
		}
	}
	return map[N][N];
}

void printPath(void) {
	int cRow = N;
	int cCol = N;
	int stack[MAX * MAX] = { 0 };
	int top;

	while (dir[cRow][cCol] != 0) {
		stack[top++] = map[cRow][cCol];
		if (dir[cRow][cCol] == UP) {
			cRow--;
		}
		else {
			cCol--;
		}
	}

	while (top > 0) {
		printf("%d", stack[--top]);
		if (top > 0) {
			printf(" + ");
		}
	}

}
