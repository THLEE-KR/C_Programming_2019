#include "ex5-4-my.h"
#ifdef FINISH
int sleepingHours=7;
#define MSG "����߾��~"
#else
#ifdef CONTINUE
int sleepingHours=4;
#define MSG "����~ ����~��

#else
int sleepingHours=0;
#define MSG "���� ���ƿ�~"
#endif
#endif

int main()
{
	printf("%s\n", MSG);
	printf("������ ����ð��� %d�ð� �Դϴ�.\n", sleepingHours);

	getchar();
	return 0;
}
