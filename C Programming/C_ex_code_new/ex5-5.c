#include <stdio.h>
#include "ex5-5-my.h"
#if  CLASS == 1
#include "one.h"
#elif  CLASS == 2
#include "ex5-5-two.h"
#else
#include "ex5-5-three.h"
#endif
int main()
{
	printf("%d반의 학생수는 %d명 입니다.\n", CLASS, STUDENT_CNT);

	getchar();
	return 0;
}
