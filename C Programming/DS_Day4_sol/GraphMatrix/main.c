#include <stdio.h>
#include "Graph.h"

int main(void) {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &vertex, &edge);

	createGraph();
	printf("--------------------------------------\n");
	printf("              인접리스트\n");
	printf("--------------------------------------\n");
	printGraph();
	printf("--------------------------------------\n");
	printf("        인접행렬 DFS 방문\n");
	printf("--------------------------------------\n");
	startDFS();
	printf("--------------------------------------\n");
	printf("전체 그래프의 수 : %d\n", cnt);
	initGraph();

	return 0;
}

