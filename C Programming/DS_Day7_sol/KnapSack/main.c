#include <stdio.h>
#include "KnapSack.h"
#define START startTime = clock()
#define END endTime = clock()
#define TIME_PRINT(S) printf(S "�˰��� ���� �ҿ�ð� : %d(millisecond)\n", (endTime-startTime));

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
		printf("DP ��� : %d\n", result);
		END;
		TIME_PRINT("DP ");
		
		START;
		result=knapsack(1, J);
		END;		
		printf("DFS ��� : %d\n", result);
		TIME_PRINT("DFS ");
	}

	return 0;
}

/*------------------------------------------------------------------
�Լ��� �� ���: knapsack() - �ش��ϴ� ��ȣ�� ������ ���� ���� ���� ���� ��� �� �� ū ��ġ�� �����ϴ� ����Լ�
�������� : i - ������ ��ȣ
        r - ���� ����
���ϰ�: �ش繰���� ���� ����� ��ġ�� ���� ���� ����� ��ġ �� ū ��
------------------------------------------------------------------*/
int knapsack(int i, int r)
{
	int res1, res2;
	if(i == C+1){  // ������ ������ �ʰ� ������
		return 0;
	}
	else if(r<W[i]){  // ���� ���԰�  ���� ����(itemNum)�� ���Ժ��� ������ ���� ������ ���� �� �ִ��� Ȯ���Ϸ� ��
		return knapsack(i+1,r);
	}
	else{   // ���� ����(itemNum)�� ���� ���� ���� �ִ� ��츦 ȣ�� ��
		res1 = knapsack(i+1, r);
		res2 = knapsack(i+1, r-W[i])+V[i];
		return (res1>res2)?res1:res2; // ���� ����(itemNum)�� ���� ���� ���� �ִ� ��� �� ��ġ�� �� ū ��츦 ���� ��
	}
}





