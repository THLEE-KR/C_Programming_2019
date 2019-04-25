#include <stdio.h>
int main()
{
		short  x =  32767;			// short형의 최대값
		short  y =  x + 1;			// short형의 최대값보다 1큰 값을 y에 저장
		printf("x = %hd\t  y = %hd\n", x, y);		// h는 short형 변경자

		getchar();
		return 0;
}

