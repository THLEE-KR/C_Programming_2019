#include<stdio.h>
void forEach( int *start, int *end, void (*workData)(void *vp));
void showInt( void *vp );
void inputInt( void *vp );
void myFlush();

int main()
{
	int   x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int   y[5] = { 10,20,30,40,50 };

	printf("[ x �迭 ����ϱ� ]\n");
	forEach(x, x+10, showInt);

	printf("\n[ y �迭 ����ϱ� ]\n");
	forEach(y, y+5, showInt);

	printf("\n[ y �迭 �Է� �ޱ� ]\n");
	forEach(y, y+5, inputInt);

	printf("\n[ y �迭 ����ϱ� ]\n");
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
	printf("������ �Է� : ");
	while( (res=scanf("%d", vp)) != 1 ){
		printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է� : ");
		myFlush();
	}
	return;
}

void myFlush()
{
	while(getchar() != '\n');
}
