#include<stdio.h>
int main()
{
	int k, s = 0;
	printf("������ �Է��ϼ���. 0(zero)�� �Է��ϸ� ����˴ϴ� : ");
	scanf("%d", &k);
	while (k != 0)
     {
		printf("���ݱ��� ���� : %d �Դϴ� \n", s += k);
		printf("���� �Է��ϼ��� 0(zero)�� �Է��ϸ� ����˴ϴ� : ");
		scanf("%d", &k);
	}
	return 0;
}
