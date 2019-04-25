#include <stdio.h>
#include "Graph.h"

int main(void) {
	graph_t grp;

	freopen("data.txt", "r", stdin);

	initGraph(&grp);

	printf("--------------------------------------\n");
	printf("              인접리스트\n");
	printf("--------------------------------------\n");
	outputGraph(&grp);

	printf("--------------------------------------\n");
	printf("        인접리스트 BFS 방문\n");
	printf("--------------------------------------\n");
	startBFS(&grp);
	printf("--------------------------------------\n");
	destroyGraph(&grp);
	printf("전체 그래프의 수 : %d\n", cnt);

	return 0;
}
