#ifndef GRAPH_H_
#define GRAPH_H_

#define MAX 100

extern int grp[MAX][MAX];	/* 인접행렬 */
extern int vertex;			/* 노드 수 */
extern int edge;			/* 간선 수 */
extern int visited[MAX];	/* 노드 방문 체크 배열 */
extern int stack[MAX];		/* 스택 배열 */
extern int top;				/* 스택 입출점 */
extern int cnt;				/* 그래프 수 카운터 변수 */

void initGraph(void);		/* 인접행렬 초기화 함수 */
void printGraph(void);		/* 인접행렬 출력 함수 */
void createGraph(void);		/* 인접행렬 생성 함수 */
void startDFS(void);		/* DFS검색 유도함수 */
void DFS(int u);			/* DFS검색 재귀함수 */

#endif /* GRAPH_H_ */
