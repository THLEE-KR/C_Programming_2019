#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int visited[MAX_VERTEX];
int queue[MAX_VERTEX];
int front;
int rear;
int cnt;

/*
 * Function Name : initGraph() - 그래프 관리 구조체 초기화 함수
 * Argument		: gp - 그래프 관리 구조체 포인터
 * Return		: 없음
 */
bool_t initGraph(graph_t *gp) {
	int i;
	char s;
	char e;

	if (gp == NULL) {
		return false;
	}

	scanf("%d %d", &gp->vertexCnt, &gp->edgeCnt);
	
	for (i=0 ; i<gp->vertexCnt ; i++) {
		gp->graph[i] = NULL; // 다른방식으로 더미노드 사용 가능  
	}

	for (i=0 ; i<gp->edgeCnt ; i++) {
		scanf(" %c %c", &s, &e);
		if (!addNode(gp, s - 'A', e - 'A')) {
			destroyGraph(gp);
			return false;
		}
	}
	return true;
}

/*
 * Function Name : addNode() - 그래프 관리 구조체 초기화 함수
 * Argument		: gp - 그래프 관리 구조체 포인터
 * v1 - 간선을 구성하는 첫 번째 정점 번호
 * v2 - 간선을 구성하는 두 번째 정점 번호
 * Return		: 노드 생성 및 추가 성공 시 1
 * 실패 시 0
 */
bool_t addNode(graph_t *gp, int v1, int v2) {
	node_t *n1;
	node_t *n2;
	if (gp == NULL) {
		return false;
	}
	n1 = (node_t *)malloc(sizeof(node_t));
	if (n1 == NULL) {
		return false;
	}
	n2 = (node_t *)malloc(sizeof(node_t));
	if (n2 == NULL) {
		free(n1);
		return false;
	}
	n1->vertex = v1;
	n1->next = NULL;
	n2->vertex = v2;
	n2->next = NULL;

	n1->next = gp->graph[v2];
	gp->graph[v2]= n1;
	
	n2->next = gp->graph[v1];
	gp->graph[v1] = n2;

	return true;
}

/*
 * Function Name : outputGraph() - 그래프 출력 함수
 * Argument		: gp - 그래프 관리 구조체 포인터
 * Return		: 없음
 */
void outputGraph(graph_t *gp) {
	int i;
	node_t *cur;

	if (gp == NULL) {
		return;
	}

	for (i=0 ; i<gp->vertexCnt; i++) {
		printf("%2c", i + 'A');

		cur = gp->graph[i];
		while (cur != NULL) {
			printf(" > %2c ", cur->vertex + 'A');
			cur = cur->next;
		}
		printf("\n");
	}
}


/*
 * Function Name : destroyGraph() - 그래프 관리 구조체 내의 동적할당 해제 및 초기화 함수
 * Argument		: gp - 그래프 관리 구조체 포인터
 * Return		: 없음
 */
void destroyGraph(graph_t *gp) {
	int i;
	node_t *delNode;

	if (gp == NULL) {
		return;
	}

	for (i=0 ; i<gp->vertexCnt ; i++) {
		while (gp->graph[i] != NULL) {
			delNode = gp->graph[i];
			gp->graph[i] = delNode->next;
			free(delNode);
		}
	}

	gp->vertexCnt = 0;
	gp->edgeCnt = 0;
}

/*
 * Function Name : startBFS() - 방문하지 않은 정점을 확인하고 너비우선탐색을 수행하는 함수
 * Argument		: gp - 그래프 관리 구조체 포인터
 * Return		: 없음
 */
void startBFS(graph_t *gp) {
	int i;

	if (gp == NULL) {
		return;
	}

	for (i=0 ; i<gp->vertexCnt ; i++) {
		visited[i] = 0;
	}
	front = 0;
	rear = 0;
	cnt = 0;

	for (i=0 ; i<gp->vertexCnt ; i++) {
		if (visited[i] == 0) {
			cnt++;
			BFS(gp, i);
			printf("\n");
		}
	}
}

/*
 * Function Name : BFS() - 너비우선탐색 수행 함수
 * Argument		: gp - 그래프 관리 구조체 포인터
 * s - 출발정점
 * Return		: 없음
 */
void BFS(graph_t *gp, int s) {
	int v;
	node_t *cur;

	if (gp == NULL) {
		return;
	}

	queue[rear++] = s;
	visited[s] = 1;

	while (front != rear) {
		v = queue[front++];
		printf("%2c", v + 'A');

		cur = gp->graph[v];
		while (cur != NULL) {
			if (visited[cur->vertex] == 0) {
				queue[rear++] = cur->vertex;
				visited[cur->vertex] = 1;
			}
			cur = cur->next;
		}
	}
}
