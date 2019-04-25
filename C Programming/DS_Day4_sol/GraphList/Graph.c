#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int visited[MAX_VERTEX];
int queue[MAX_VERTEX];
int front;
int rear;
int cnt;

/*
 * Function Name : initGraph() - �׷��� ���� ����ü �ʱ�ȭ �Լ�
 * Argument		: gp - �׷��� ���� ����ü ������
 * Return		: ����
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
		gp->graph[i] = NULL; // �ٸ�������� ���̳�� ��� ����  
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
 * Function Name : addNode() - �׷��� ���� ����ü �ʱ�ȭ �Լ�
 * Argument		: gp - �׷��� ���� ����ü ������
 * v1 - ������ �����ϴ� ù ��° ���� ��ȣ
 * v2 - ������ �����ϴ� �� ��° ���� ��ȣ
 * Return		: ��� ���� �� �߰� ���� �� 1
 * ���� �� 0
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
 * Function Name : outputGraph() - �׷��� ��� �Լ�
 * Argument		: gp - �׷��� ���� ����ü ������
 * Return		: ����
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
 * Function Name : destroyGraph() - �׷��� ���� ����ü ���� �����Ҵ� ���� �� �ʱ�ȭ �Լ�
 * Argument		: gp - �׷��� ���� ����ü ������
 * Return		: ����
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
 * Function Name : startBFS() - �湮���� ���� ������ Ȯ���ϰ� �ʺ�켱Ž���� �����ϴ� �Լ�
 * Argument		: gp - �׷��� ���� ����ü ������
 * Return		: ����
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
 * Function Name : BFS() - �ʺ�켱Ž�� ���� �Լ�
 * Argument		: gp - �׷��� ���� ����ü ������
 * s - �������
 * Return		: ����
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
