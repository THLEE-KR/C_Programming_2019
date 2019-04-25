#include <stdio.h>
int  main()
{
		double  d_num1 = 321.45e-1;
		double  d_num2 = d_num1 + 10;

		printf("d_num1 = %lf(%le)\n", d_num1, d_num1);
		printf("d_num2 = %lf(%le)\n", d_num2, d_num2);

		getchar();
		return 0;
}
