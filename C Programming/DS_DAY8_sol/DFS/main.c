#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100     // 맵의 가로 세로 최대 크기
#define ROAD -1     // 도로 표시 값
#define WALL -2     // 벽 표시 값

typedef struct {    // 좌표 구조체
	int row;
	int col;
} coord_t;

struct {            // 상대좌표 연산용 구조체 변수
	int row[4];
	int col[4];
	int dir;
} rc = {{-1, 0, 1, 0}, {0, -1, 0, 1}, 4 };

int gMap[MAX][MAX]; // 맵 배열
int gRow;           // 맵의 세로 크기
int gCol;           // 맵의 가로 크기
coord_t gStart;     // 출발 점
coord_t gGoal;      // 도착 점
int minV;           // 출발점에서 도착점까지의 최소거리 저장 변수
int maxV;           // 출발점에서 도착점까지의 최대거리 저장 변수
int rootCnt;        // 출발점에서 도착점까지의 경로의 수 저장 변수

// 맵 초기화 함수
void init(void) {
	int i;
	int j;

	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			gMap[i][j] = -1;
		}
	}
	gRow = 0;
	gCol = 0;
}

// 맵 생성 함수
void create(void) {
	int i;
	int j;
	char ch;

	scanf("%d %d", &gRow, &gCol);
	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			scanf(" %c", &ch);
			switch(ch) {
			case 'S':               // 출발점인 경우
				gMap[i][j] = ROAD;
				gStart.row = i;
				gStart.col = j;
				break;
			case 'G':               // 도착점인 경우
				gGoal.row = i;
				gGoal.col = j;
				gMap[i][j] = ROAD;
				break;
			case '.':               // 도로인 경우
				gMap[i][j] = ROAD;
				break;
			default:                // 그 외의 경우
				gMap[i][j] = WALL;
				break;
			}
		}
	}
}

// 깊이 우선 탐색 (DFS) 함수
// 첫 번째 인수 : 탐색 좌표
// 두 번째 인수 : 탐색 이동 횟수
void dfs(coord_t s, int c) {
	int i;
	int orig;
	coord_t v;
	// 첫 번째 인수의 좌표가 도착점이라면
	if ((s.row == gGoal.row) && (s.col == gGoal.col)) {
		if (c < minV) {             // 최소거리 여부 및 값 저장
			minV = c;
		}
		if (c > maxV) {             // 최대거리 여부 및 값 저장
			maxV = c;
		}
		rootCnt++;                  // 이동 경로의 수 증가
		return;
	}
	else {          						// 도착점이 아니라면
		orig = gMap[s.row][s.col];          // 상태 롤백을 위해 현재 값을 보관 후
		gMap[s.row][s.col] = 1;             // 정점 방문 체크 처리를 한다.
		for (i=0 ; i<rc.dir ; i++) {        // 인접한 정점에 대하여
			v.row = s.row + rc.row[i];
			v.col = s.col + rc.col[i];
			// 유효 범위 내의 좌표이며
			if ((v.row >= 1) && (v.row <= gRow) && (v.col >= 1) && (v.col <= gCol)) {
				// 탐색되지 않은 도로라면
				if (gMap[v.row][v.col] == ROAD) {
					dfs(v, c + 1);          // 탐색 함수 재귀 호출
				}
			}
		}
		// 해당 정점 이후의 모든 정점이 완료되어 함수 종료 시
		// 해당 정점의 재사용을 위해 방문처리 표시를 롤백한다.
		gMap[s.row][s.col] = orig;
	}
}

// 맵 출력 함수
void print(void) {
	int i;
	int j;

	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			switch (gMap[i][j]) {
			case ROAD:
				if ((gStart.row == i) && (gStart.col == j)) {
					printf("S");
				}
				else if ((gGoal.row == i) && (gGoal.col == j)) {
					printf("G");
				}
				else {
					printf(".");
				}
				break;
			case WALL:
				printf("%c", '#');
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

int main(void) {
	int st, ed;

	freopen("data.txt", "r", stdin);    // 파일 입력 설정
	create();                           // 맵 생성

	minV = 10000;                       // 최소 경로값 저장 변수 초기화
	maxV = 0;                           // 최대 경로값 저장 변수 초기화
	rootCnt = 0;                        // 이동 경로 수 변수 초기화

	st = clock();                       // 탐색 시작 시간
	dfs(gStart, 0);                     // DFS 탐색 실행
	ed = clock();                       // 탐색 종료 시간

	print();                            // 맵 및 탐색 정보 출력
	printf("최소경로 : %d\n", minV);
	printf("최대경로 : %d\n", maxV);
	printf("경로수 : %d\n", rootCnt);
	printf("탐색시간 : %.6lf초\n", ((double)ed - st) / CLOCKS_PER_SEC);
	
	init();                             // 사용변수 초기화

	return 0;
}
