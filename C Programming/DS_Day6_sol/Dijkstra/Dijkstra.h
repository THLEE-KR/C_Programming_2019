#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#define MAX 100
#define INF (MAX * MAX)
#define NIL -1

extern int G[MAX][MAX];	/* 그래프 배열 */
extern int V[MAX];	/* 노드 처리 체크 배열 */
extern int D[MAX];		/* 최단거리 저장 배열 */
extern int P[MAX];		/* 직전노드 저장 배열 */
extern int Q[MAX];		/* 정점 저장 큐 */
extern int front;			/* 큐 출력데이터 참조 변수 */
extern int rear;			/* 큐 입력데이터 참조 변수 */
extern int vertex;			/* 정점 수 저장 배열 */
extern int edge;			/* 간선 수 저장 배열 */

void initGraph(void);
void printGraph(void);
void createGraph(void);
void dijkstra(int s);
void printPredecessor(void);
void printVisited(void);
void printPath(int s, int t);
void printDistance(int s);

#endif /* DIJKSTRA_H_ */
