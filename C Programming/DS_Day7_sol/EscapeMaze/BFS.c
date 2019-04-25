#include <stdio.h>
#include "BFS.h"

int map[MAX + 1][MAX + 1]; 			/* 맵 배열 */
coord_t queue[MAX + 1];				/* 방문순서저장 큐 */
int N; 								/* 맵 행의 수 */
int M; 								/* 맵 열의 수 */
coord_t start; 						/* 출발 좌표 */
coord_t goal; 						/* 도착 좌표 */
int front;							/* 큐 출력 참조변수 */
int rear;							/* 큐 입력 참조변수 */
int dr[] = { 1, 0, -1, 0 };			/* 탐색대상 행의 상대 좌표 */
int dc[] = { 0, 1, 0, -1 };			/* 탐색대상 열의 상대좌표 */

void initMap(void) {
	int i;
	int j;

	for (i=1 ; i<=MAX ; i++) {
		for (j=1 ; j<=MAX ; j++) {
			map[i][j] = 0;
		}
	}
	N = MAX;
	M = MAX;
}

void createMap(void) {
	int i;
	int j;
	int ch;

	scanf("%d %d\n", &N, &M);
	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=M ; j++) {
			ch = fgetc(stdin);

			switch (ch) {
			case (int)'.':			/* 도로인 경우 */
				map[i][j] = -1;
				break;
			case (int)'S':			/* 출발점인 경우 */
				map[i][j] = -1;
				start.row = i;
				start.col = j;
				break;
			case (int)'G':			/* 도착점인 경우 */
				map[i][j] = -1;
				goal.row = i;
				goal.col = j;
				break;
			default:				/* 그 이외(벽)의 경우 */
				map[i][j] = -2;
				break;
			}
		}
		fgetc(stdin);
	}
}

void printMap(void) {
	int i;
	int j;

	printf("\n** 미로출력 **\n");
	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=M ; j++) {

			if ((i == start.row) && (j == start.col)) {		/* 출발점인 경우 */
				printf("%3c", 'S');
			}
			else if (map[i][j] == -1) {						/* 도로인 경우 */
				if ((i == goal.row) && (j == goal.col)) {	/* 도착점인 경우 */
					printf("%3c", 'G');
				}
				else {
					printf("%3c", '.');
				}
			}
			else if (map[i][j] == -2) {						/* 벽인 경우 */
				printf("%3c", '#');
			}
			else {											/* 그 이외의 경우 */
				printf("%3d", map[i][j]);
			}
		}
		printf("\n");
	}
}

int BFS(coord_t s, coord_t g) {
	int i;
	/* 큐 초기화 */
	front = 0;
	rear = 0;

	/* 출발점 enQueue 및 값 초기화 */
	queue[rear++] = s;
	map[s.row][s.col] = 0;

	while (front != rear) {
		coord_t u = queue[front++];

		for (i=0 ; i<4 ; i++) {
			coord_t v = { u.row + dr[i], u.col + dc[i] };
			
			if ((v.row >= 1) && (v.row <= N) && (v.col >= 1) && (v.row <= M)) {
				
				if (map[v.row][v.col] == -1) {
					/* 해당 좌표에 값을 지정 후 좌표값을 enQueue */
					map[v.row][v.col] = map[u.row][u.col] + 1;
					queue[rear++] = v;
				}
			}
		}
	}
	return map[goal.row][goal.col];
}

