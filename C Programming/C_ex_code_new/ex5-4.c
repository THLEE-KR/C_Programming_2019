#include "ex5-4-my.h"
#ifdef FINISH
int sleepingHours=7;
#define MSG "고생했어요~"
#else
#ifdef CONTINUE
int sleepingHours=4;
#define MSG "열프~ 즐프~“

#else
int sleepingHours=0;
#define MSG "날새 보아요~"
#endif
#endif

int main()
{
	printf("%s\n", MSG);
	printf("오늘의 수면시간은 %d시간 입니다.\n", sleepingHours);

	getchar();
	return 0;
}
