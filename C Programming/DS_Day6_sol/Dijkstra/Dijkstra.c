#include <stdio.h>
#include "Dijkstra.h"

int G[MAX][MAX];	/* �׷��� �迭 */
int V[MAX];			/* ��� ó�� üũ �迭 */
int D[MAX];			/* �ִܰŸ� ���� �迭 */
int P[MAX];			/* ������� ���� �迭 */
int vertex;			/* ���� �� ���� �迭 */
int edge;			/* ���� �� ���� �迭 */

/*--------------------------------------------------------------------------------------
�Լ��� �� ���	: dijkstra() - ���޵� �׷������� ���õ� �������� ���� ������ ����������
			�ּ� ����ġ�� ����ϰ� �θ��ڽ� ���踦 ������
��������		: s - ���õ� ���� ��ȣ
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void dijkstra(int s) {
	/* distance�� predecessor, visited �迭 �ʱ�ȭ */
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
�Լ��� �� ���: pathPrint() - ���� ����->�� ���������� path �� ����ġ ���
��������:  parent - �θ�, �ڽİ��踦 ������ �迭�� �����ּ�
			weightArray - ����ġ ���� �迭�� �����ּ�
			startVNum - ���� ���� ��ȣ
			endVNum - ���� ���� ��ȣ
���ϰ�: ����
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
		printf("�̵���� : %c -> ", s + 'A');
		while (top > 0) {
			printf("%c", stack[--top] + 'A');
			if (top > 0) {
				printf(" -> ");
			}
		}
		printf("\n");
	}
	else {
		printf("���� �Ұ���!!!\n");
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
				printf("%3s", "��");
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
