#include<stdio.h>
void forEach( int *start, int *end, void (*workData)(void *vp));
void showInt( void *vp );
void inputInt( void *vp );
void myFlush();

int main()
{
	int   x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int   y[5] = { 10,20,30,40,50 };

	printf("[ x 배열 출력하기 ]\n");
	forEach(x, x+10, showInt);

	printf("\n[ y 배열 출력하기 ]\n");
	forEach(y, y+5, showInt);

	printf("\n[ y 배열 입력 받기 ]\n");
	forEach(y, y+5, inputInt);

	printf("\n[ y 배열 출력하기 ]\n");
	forEach(y, y+5, showInt);

	getchar();getchar();
	return 0;
}
void forEach( int *start, int *end, void (*workData)(void *vp) )
{
	while(start!=end)
	{
		workData(start);
		start++;
	}
}
void showInt( void *vp )
{
	printf("num=%d\n", *(int *)vp);
}
void inputInt( void *vp )
{
	int res;
	printf("정수값 입력 : ");
	while( (res=scanf("%d", vp)) != 1 ){
		printf("잘못 입력하셨습니다. 다시 입력 : ");
		myFlush();
	}
	return;
}

void myFlush()
{
	while(getchar() != '\n');
}
