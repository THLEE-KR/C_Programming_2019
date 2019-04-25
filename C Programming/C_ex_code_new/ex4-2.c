#include<stdio.h>
int main()
{
	int k, s = 0;
	printf("정수를 입력하세요. 0(zero)을 입력하면 종료됩니다 : ");
	scanf("%d", &k);
	while (k != 0)
     {
		printf("지금까지 합은 : %d 입니다 \n", s += k);
		printf("수를 입력하세요 0(zero)을 입력하면 종료됩니다 : ");
		scanf("%d", &k);
	}
	return 0;
}
