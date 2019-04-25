#ifndef GRAPH_H_
#define GRAPH_H_

#define MAX_VERTEX 100
typedef enum _bool { false = 0, true = 1, FALSE = false, TRUE = true } bool_t;

typedef struct _node {	/* 정점 정보 저장 노드 구조체 */
	int vertex;			/* 정점 번호 */
	struct _node *next;	/* 다음 노드 주소 */
} node_t;

typedef struct {		/* 그래프 관리 구조체 */
	node_t *graph[MAX_VERTEX];	/* 인접리트스 표기배열 */
	int vertexCnt;				/* 연결 정점 수 */
	int edgeCnt;				/* 간선 수 */
} graph_t;

extern int visited[];	/* 정점 방문 체크 배열 */
extern int queue[];		/* 정점 저장 큐 */
extern int front;		/* 큐 출력 참조 변수 */
extern int rear;		/* 큐 입력 참조 변수 */
extern int cnt;			/* 그래프 수 카운터 변수 */

bool_t initGraph(graph_t *gp);	/* 그래프 초기화 및 생성 함수 */
void outputGraph(graph_t *gp);	/* 그래프 출력 함수 */
bool_t addNode(graph_t *gp, int v1, int v2); /* 정점노드 생성 및 추가 함수 */
void destroyGraph(graph_t *gp);	/* 그래프내의 노드 삭제 및 초기화 함수 */
void startBFS(graph_t *gp); 	/* 방문하지 않은 노드에 대한 BFS탐색 호출 함수 */
void BFS(graph_t *gp, int s);	/* BFS탐색 함수 */

#endif /* GRAPH_H_ */
