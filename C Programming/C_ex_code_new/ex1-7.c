#include<stdio.h>
#include<math.h> // fabs()�Լ� ��� �����
#include<float.h>  //  DBL_EPSILON ��ũ�� ����
int main()
{
	double a,b;
	printf("a=");
	scanf("%lf", &a);

	printf("b=");
	scanf("%lf", &b);

	printf("DBL_EPSILON = %.30lf\n", DBL_EPSILON);
	// DBL_EPSILON = 0.000000000000000222044604925031

	if(fabs(a-b) < DBL_EPSILON){
		// if(a==b)
		printf(" �� ���� ���� ��!!\n");
	}
	else{
		printf("�� ���� �ٸ� ��!!\n");
	}

	getchar(); getchar();
	return 0;
}
