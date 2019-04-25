#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#define MAX 100
#define INF (MAX * MAX)
#define NIL -1

extern int G[MAX][MAX];	/* �׷��� �迭 */
extern int V[MAX];	/* ��� ó�� üũ �迭 */
extern int D[MAX];		/* �ִܰŸ� ���� �迭 */
extern int P[MAX];		/* ������� ���� �迭 */
extern int Q[MAX];		/* ���� ���� ť */
extern int front;			/* ť ��µ����� ���� ���� */
extern int rear;			/* ť �Էµ����� ���� ���� */
extern int vertex;			/* ���� �� ���� �迭 */
extern int edge;			/* ���� �� ���� �迭 */

void initGraph(void);
void printGraph(void);
void createGraph(void);
void dijkstra(int s);
void printPredecessor(void);
void printVisited(void);
void printPath(int s, int t);
void printDistance(int s);

#endif /* DIJKSTRA_H_ */
