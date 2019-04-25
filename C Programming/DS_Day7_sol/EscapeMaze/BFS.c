#include <stdio.h>
#include "BFS.h"

int map[MAX + 1][MAX + 1]; 			/* �� �迭 */
coord_t queue[MAX + 1];				/* �湮�������� ť */
int N; 								/* �� ���� �� */
int M; 								/* �� ���� �� */
coord_t start; 						/* ��� ��ǥ */
coord_t goal; 						/* ���� ��ǥ */
int front;							/* ť ��� �������� */
int rear;							/* ť �Է� �������� */
int dr[] = { 1, 0, -1, 0 };			/* Ž����� ���� ��� ��ǥ */
int dc[] = { 0, 1, 0, -1 };			/* Ž����� ���� �����ǥ */

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
			case (int)'.':			/* ������ ��� */
				map[i][j] = -1;
				break;
			case (int)'S':			/* ������� ��� */
				map[i][j] = -1;
				start.row = i;
				start.col = j;
				break;
			case (int)'G':			/* �������� ��� */
				map[i][j] = -1;
				goal.row = i;
				goal.col = j;
				break;
			default:				/* �� �̿�(��)�� ��� */
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

	printf("\n** �̷���� **\n");
	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=M ; j++) {

			if ((i == start.row) && (j == start.col)) {		/* ������� ��� */
				printf("%3c", 'S');
			}
			else if (map[i][j] == -1) {						/* ������ ��� */
				if ((i == goal.row) && (j == goal.col)) {	/* �������� ��� */
					printf("%3c", 'G');
				}
				else {
					printf("%3c", '.');
				}
			}
			else if (map[i][j] == -2) {						/* ���� ��� */
				printf("%3c", '#');
			}
			else {											/* �� �̿��� ��� */
				printf("%3d", map[i][j]);
			}
		}
		printf("\n");
	}
}

int BFS(coord_t s, coord_t g) {
	int i;
	/* ť �ʱ�ȭ */
	front = 0;
	rear = 0;

	/* ����� enQueue �� �� �ʱ�ȭ */
	queue[rear++] = s;
	map[s.row][s.col] = 0;

	while (front != rear) {
		coord_t u = queue[front++];

		for (i=0 ; i<4 ; i++) {
			coord_t v = { u.row + dr[i], u.col + dc[i] };
			
			if ((v.row >= 1) && (v.row <= N) && (v.col >= 1) && (v.row <= M)) {
				
				if (map[v.row][v.col] == -1) {
					/* �ش� ��ǥ�� ���� ���� �� ��ǥ���� enQueue */
					map[v.row][v.col] = map[u.row][u.col] + 1;
					queue[rear++] = v;
				}
			}
		}
	}
	return map[goal.row][goal.col];
}

