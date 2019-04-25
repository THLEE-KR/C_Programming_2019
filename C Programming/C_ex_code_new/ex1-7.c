#include<stdio.h>
#include<math.h> // fabs()함수 헤더 선언부
#include<float.h>  //  DBL_EPSILON 매크로 선언
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
		printf(" 두 수는 같은 수!!\n");
	}
	else{
		printf("두 수는 다른 수!!\n");
	}

	getchar(); getchar();
	return 0;
}
