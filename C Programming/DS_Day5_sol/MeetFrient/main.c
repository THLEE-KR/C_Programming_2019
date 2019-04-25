#include <stdio.h>
#define MAX 10
#define DEBUG 1

int dist[MAX][MAX];				/* 자택과 친구, 친구과 친구, 친구와 자택 거리 저장 배열 */
int R[MAX];						/* 행 좌표 저장 배열 */
int C[MAX];						/* 열 좌표 저장 배열 */
int N;							/* 도시의 크기 */
int frs		;					/* 친구 수 */
int perm[MAX];					/* 순열저장 배열 */
int used[MAX];					/* 순열 체크 배열 */
int best[MAX];					/* 최단 경로 저장 배열 */
int minV = MAX * MAX;			/* 최소거리 저장변수 */

void createPerm(int n, int k);	/* 순열생성 및 거리계산 함수 */

int main(void) {
	int i;
	int j;

	freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &frs);	/* 맵의 크기와 친구의 수를 읽어들인다. */

	/* 자택 좌표를 1,1로 설정 */
	R[0] = 1;
	C[0] = 1;

	/* 친구의 좌표 정보를 읽어들여 배열에 저장 */
	for (i=1 ; i<=frs ; i++) {
		scanf("%d %d", &R[i], &C[i]);
	}

	/* 각 지점으로부터 각 지점까지의 정보 테이블을 작성한다. */
	for (i=0 ; i<=frs ; i++) {
		for (j=i+1 ; j<=frs ; j++) {
			int h = (C[i] - C[j]) >= 0 ? C[i] - C[j] : -(C[i] - C[j]) ;
			int v = (R[i] - R[j]) >= 0 ? R[i] - R[j] : -(R[i] - R[j]) ;
			dist[j][i] = dist[i][j] = h + v;
		}
	}

#if DEBUG == 1
	printf("%2s", "");
	for (i=0 ; i<=frs ; i++) {
		printf("%2d", i);
	}
	printf("\n");
	for (i=0 ; i<=frs ; i++) {
		printf("%2d", i);
		for (j=0 ; j<=frs ; j++) {
			printf("%2d", dist[i][j]);
		}
		printf("\n");
	}
#endif

	/* 순열을 생성하는 함수 호출 */
	createPerm(0, 3);
	printf("최단거리 : %d\n", minV);
	printf("자택 > ");
	for (i=0 ; i<frs ; i++) {
		printf("%d > ", best[i]);
	}
	printf("자택도착\n");

	return 0;
}

/*------------------------------------------------------------------------
 * Function Name 	: createPerm() - 순열 생성 및 거리계산 함수
 * Argument 		: n - 순열 배열 저장 위치
 * 					  k - 배열 저장 인덱스 한계 값
 * Return			: 없음
 -----------------------------------------------------------------------*/
void createPerm(int n, int k) {
	int i;

	if (n == k) {
		int d = 0;

		for (i=0 ; i<k ; i++) {
			if (i == 0) {
				d += dist[0][perm[i]];
			}
			else {
				d += dist[perm[i-1]][perm[i]];
			}
		}
		d += dist[perm[k - 1]][0];
		printf("tot dist = %d\n", d);
		if (d < minV) {
			minV = d;
			for (i=0 ; i<k ; i++) {
				best[i] = perm[i];
			}
		}
	}
	else {
		for (i=0 ; i<k ; i++) {
			if (used[i] == 0) {
				used[i] = 1;
				perm[n] = i + 1;
				createPerm(n + 1, k);
				used[i] = 0;
			}
		}
	}
}
