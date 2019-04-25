#include <stdio.h>
#include "Dijkstra.h"

int G[MAX][MAX];	/* 그래프 배열 */
int V[MAX];			/* 노드 처리 체크 배열 */
int D[MAX];			/* 최단거리 저장 배열 */
int P[MAX];			/* 직전노드 저장 배열 */
int vertex;			/* 정점 수 저장 배열 */
int edge;			/* 간선 수 저장 배열 */

/*--------------------------------------------------------------------------------------
함수명 및 기능	: dijkstra() - 전달된 그래프내에 선택된 정점으로 부터 나머지 정점까지의
			최소 가중치를 계산하고 부모자식 관계를 연산함
전달인자		: s - 선택된 정점 번호
리턴값: 없음
--------------------------------------------------------------------------------------*/
void dijkstra(int s) {
	/* distance와 predecessor, visited 배열 초기화 */
	int i;
	int j;

	for (i=0 ; i<vertex ; i++) {
		D[i] = G[s][i];
		V[i] = 0;
		if (G[s][i] != INF) {
			P[i] = s;
		}
		else {
			P[i] = NIL;
		}
	}

	V[s] = 1;
	for (i=0 ; i<vertex ; i++) {
		int minIndex = 0;
		int minValue = INF;
		for (j=0 ; j<vertex ; j++) {
			if ((V[j] == 0) && (D[j] < minValue)) {
				minIndex = j;
				minValue = D[j];
			}
		}
		V[minIndex] = 1;

		for (j=0 ; j<vertex ; j++) {
			if (V[j] == 0) {
				if ((D[minIndex] + G[minIndex][j]) < D[j]) {
					D[j] = D[minIndex] + G[minIndex][j];
					P[j] = minIndex;
				}
			}
		}
	}
}

void printVisited(void) {
	int i;

	printf("-------------------------------------\n");
	for (i=0 ; i<vertex ; i++) {
		printf("%2c", i + 'A');
	}
	printf("\n");

	for (i=0 ; i<vertex ; i++) {
		printf("%2d", V[i]);
	}
	printf("\n");
	printf("-------------------------------------\n");
}

void printPredecessor(void) {
	int i;

	for (i=0 ; i<vertex ; i++) {
		printf("%2c ", i + 'A');
	}
	printf("\n");

	for (i=0 ; i<vertex ; i++) {
		printf("%2c ", P[i] + 'A');
	}
	printf("\n");
}

/*--------------------------------------------------------------------------------------
함수명 및 기능: pathPrint() - 시작 정점->끝 정점까지의 path 및 가중치 출력
전달인자:  parent - 부모, 자식관계를 저장한 배열의 시작주소
			weightArray - 가중치 저장 배열의 시작주소
			startVNum - 시작 정점 번호
			endVNum - 도착 정점 번호
리턴값: 없음
--------------------------------------------------------------------------------------*/
void printPath(int s, int t) {
	int stack[MAX] = { 0 };
	int top = 0;

	stack[top++] = t;
	while (P[t] != s) {
		t = P[t];
		stack[top++] = t;
	}

	if (s == P[t]) {
		printf("이동경로 : %c -> ", s + 'A');
		while (top > 0) {
			printf("%c", stack[--top] + 'A');
			if (top > 0) {
				printf(" -> ");
			}
		}
		printf("\n");
	}
	else {
		printf("도달 불가능!!!\n");
	}
}

void printDistance(int s) {
	int i;

	printf("%c > ", s + 'A');
	for (i=0 ; i<vertex ; i++) {
		printf("%2c", i + 'A');
	}
	printf("\n");

	printf("    ");
	for (i=0 ; i<vertex ; i++) {
		if (D[i] == INF) {
			printf("%2c", 'x');
		}
		else {
			printf("%2d", D[i]);
		}
	}
	printf("\n");
}

void initGraph(void) {
	int i;
	int j;

	for (i=0 ; i<MAX ; i++) {
		for (j=0 ; j<MAX ; j++) {
			if (i == j) {
				G[i][j] = 0;
			}
			else {
				G[i][j] = INF;
			}
		}
	}
}

void printGraph(void) {
	int i;
	int j;

	printf("%2s", "");
	for (i=0 ; i<vertex ; i++) {
		printf("%2c", 'A' + i);
	}
	printf("\n");

	for (i=0 ; i<vertex ; i++) {
		printf("%2c", 'A' + i);
		for (j=0 ; j<vertex ; j++) {
			if (G[i][j] == INF) {
				printf("%3s", "∞");
			}
			else {
				printf("%2d", G[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void createGraph(void) {
	int i;
	char s;
	char t;
	int w;

	scanf("%d %d", &vertex, &edge);
	for (i=0 ; i<edge ; i++) {
		scanf(" %c %c %d", &s, &t, &w);
		G[s - 'A'][t - 'A'] = w;
		G[t - 'A'][s - 'A'] = w;
	}
}
