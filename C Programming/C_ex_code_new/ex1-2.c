#include <stdio.h>
int main()
{
		short  x =  32767;			// short���� �ִ밪
		short  y =  x + 1;			// short���� �ִ밪���� 1ū ���� y�� ����
		printf("x = %hd\t  y = %hd\n", x, y);		// h�� short�� ������

		getchar();
		return 0;
}

