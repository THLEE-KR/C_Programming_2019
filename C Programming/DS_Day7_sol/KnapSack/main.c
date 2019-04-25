#include <stdio.h>
#include "KnapSack.h"
#define START startTime = clock()
#define END endTime = clock()
#define TIME_PRINT(S) printf(S "알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime-startTime));

int knapsack(int i, int r);

int startTime, endTime;

int main(void) {
	int T;
	int result;
	int tc;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (tc=0 ; tc<T ; tc++) {
		initData();
		createData();
		//printData();
		START;
		result = calc();
		printf("DP 결과 : %d\n", result);
		END;
		TIME_PRINT("DP ");
		
		START;
		result=knapsack(1, J);
		END;		
		printf("DFS 결과 : %d\n", result);
		TIME_PRINT("DFS ");
	}

	return 0;
}

/*------------------------------------------------------------------
함수명 및 기능: knapsack() - 해당하는 번호의 물건을 넣을 경우와 넣지 않을 경우 중 더 큰 가치를 리턴하는 재귀함수
전달인자 : i - 물건의 번호
        r - 남은 무게
리턴값: 해당물건을 넣은 경우의 가치와 넣지 않은 경우의 가치 중 큰 값
------------------------------------------------------------------*/
int knapsack(int i, int r)
{
	int res1, res2;
	if(i == C+1){  // 물건의 개수를 초과 했으면
		return 0;
	}
	else if(r<W[i]){  // 남은 무게가  현재 물건(itemNum)의 무게보다 작으면 다음 물건을 넣을 수 있는지 확인하러 감
		return knapsack(i+1,r);
	}
	else{   // 현재 물건(itemNum)을 넣지 않은 경우와 넣는 경우를 호출 함
		res1 = knapsack(i+1, r);
		res2 = knapsack(i+1, r-W[i])+V[i];
		return (res1>res2)?res1:res2; // 현재 물건(itemNum)을 넣지 않은 경우와 넣는 경우 중 가치가 더 큰 경우를 리턴 함
	}
}





