#include <stdio.h>
#include "Dijkstra.h"

int main(void) {
	int i;
	int j;

	freopen("data.txt", "r", stdin);

	initGraph();
	createGraph();
	printGraph();

	for (i=0 ; i<vertex ; i++) {
		dijkstra(i);
		printf("---- %c ���� �ּ� ��� �� ��� ---------------\n", i + 'A');
		for (j=0 ; j<vertex ; j++) {
			printf("�ּҺ�� : %c -> %c : %d\n", i + 'A', j + 'A', D[j]);
			printPath(i, j);
		}
		printDistance(i);
		printPredecessor();
	}

	return 0;
}
