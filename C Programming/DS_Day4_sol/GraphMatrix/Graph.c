#include <stdio.h>
#include "Graph.h"

int grp[MAX][MAX];
int vertex;
int edge;
int visited[MAX];
int stack[MAX];
int top;
int cnt;

void initGraph(void) {
	int i;
	int j;

	for (i=0 ; i<vertex ; i++) {
		for (j=0 ; j<vertex ; j++) {
			grp[i][j] = 0;
		}
	}
	vertex = 0;
	edge = 0;
}

void printGraph(void) {
	int i;
	int j;

	printf("%2s", "");
	for (i=0 ; i<vertex ; i++) {
		printf("%2c", i + 'A');
	}
	printf("\n");

	for (i=0 ; i<vertex ; i++) {
		printf("%2c", i + 'A');
		for (j=0 ; j<vertex ; j++) {
			printf("%2d", grp[i][j]);
		}
		printf("\n");
	}
}

void createGraph(void) {
	int i;
	char s;
	char e;

	for (i=1 ; i<=edge ; i++) {
		scanf(" %c %c", &s, &e);
		grp[s - 'A'][e - 'A'] = 1;
		grp[e - 'A'][s - 'A'] = 1;
	}
}

void startDFS(void) {
	int i;

	for (i=0 ; i<vertex ; i++) {
		visited[i] = 0;
	}
	top = 0;
	cnt = 0;

	for (i=0 ; i<vertex ; i++) {
		if (visited[i] == 0) {
			cnt++;
			DFS(i);
			printf("\n");
		}
	}
}

void DFS(int u) {
	int v;
	stack[top++] = u;
	visited[u] = 1;

	while (top > 0) {
		u = stack[--top];
		printf("%2c", u + 'A');
		for (v=0 ; v<vertex ; v++) {
			if ((grp[u][v] == 1) && (visited[v] == 0)) {
				stack[top++] = v;
				visited[v] = 1;
			}
		}
	}
}
