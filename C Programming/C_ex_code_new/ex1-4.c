#include<stdio.h>

int main()
{
		float fnum = 17.123456789;
		double dnum = 17.12345678912345;

		printf("fnum = %.20f\n", fnum);
		printf("dnum = %.20lf\n", dnum);

		getchar();
		return 0;
}
