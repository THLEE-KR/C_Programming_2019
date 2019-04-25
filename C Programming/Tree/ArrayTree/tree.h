#ifndef TREE_H_
#define TREE_H_
#define MAX 10			/* 최대 노드 수 */

extern int PN[];		/* 부모 노드 정보 저장 배열 */
extern int CL[];		/* 좌측 자식 정보 저장 배열 */
extern int CR[];		/* 우측 자식 정보 저장 배열 */
extern int cnt;			/* 순회 시 방문 노드 카운터 변수 */

void createTree(void);	/* 트리 생성 함수 */
void DLR(int n);		/* 트리 순회 재귀 함수 */
int FND(int n);			/* 조상 노드 탐색 함수 */

#endif /* TREE_H_ */
