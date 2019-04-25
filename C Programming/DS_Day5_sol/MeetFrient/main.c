#include <stdio.h>
#define MAX 10
#define DEBUG 1

int dist[MAX][MAX];				/* ���ð� ģ��, ģ���� ģ��, ģ���� ���� �Ÿ� ���� �迭 */
int R[MAX];						/* �� ��ǥ ���� �迭 */
int C[MAX];						/* �� ��ǥ ���� �迭 */
int N;							/* ������ ũ�� */
int frs		;					/* ģ�� �� */
int perm[MAX];					/* �������� �迭 */
int used[MAX];					/* ���� üũ �迭 */
int best[MAX];					/* �ִ� ��� ���� �迭 */
int minV = MAX * MAX;			/* �ּҰŸ� ���庯�� */

void createPerm(int n, int k);	/* �������� �� �Ÿ���� �Լ� */

int main(void) {
	int i;
	int j;

	freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &frs);	/* ���� ũ��� ģ���� ���� �о���δ�. */

	/* ���� ��ǥ�� 1,1�� ���� */
	R[0] = 1;
	C[0] = 1;

	/* ģ���� ��ǥ ������ �о�鿩 �迭�� ���� */
	for (i=1 ; i<=frs ; i++) {
		scanf("%d %d", &R[i], &C[i]);
	}

	/* �� �������κ��� �� ���������� ���� ���̺��� �ۼ��Ѵ�. */
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

	/* ������ �����ϴ� �Լ� ȣ�� */
	createPerm(0, 3);
	printf("�ִܰŸ� : %d\n", minV);
	printf("���� > ");
	for (i=0 ; i<frs ; i++) {
		printf("%d > ", best[i]);
	}
	printf("���õ���\n");

	return 0;
}

/*------------------------------------------------------------------------
 * Function Name 	: createPerm() - ���� ���� �� �Ÿ���� �Լ�
 * Argument 		: n - ���� �迭 ���� ��ġ
 * 					  k - �迭 ���� �ε��� �Ѱ� ��
 * Return			: ����
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
