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
		printf("---- %c 기준 최소 비용 및 경로 ---------------\n", i + 'A');
		for (j=0 ; j<vertex ; j++) {
			printf("최소비용 : %c -> %c : %d\n", i + 'A', j + 'A', D[j]);
			printPath(i, j);
		}
		printDistance(i);
		printPredecessor();
	}

	return 0;
}
