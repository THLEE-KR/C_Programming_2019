#include <stdio.h>
int inputInt(const char *);
void myflush(void);
int main()
{
	int score;
	char className;  
	char stuName[20];
	
	score = inputInt("성적을 입력하시오 : ");
	printf("class를 입력하시오(A~C) : ");
	className = getchar();
	printf("학생명을 입력하시오 : ");
	fgets(stuName, sizeof(stuName), stdin);

	printf("학생명 : %s / class : %c / 성적 : %d\n", stuName, className, score);
	getchar();
	return 0;
}
int inputInt(const char *message)
{
	int number, res;
	while (1) {
		printf(message);
		res = scanf("%d", &number);
		if (res == 1) {
			break;
		}
		else {
			myflush();
		}
	}
	return number;
}
void myflush(void) // 입력 버퍼 비우기 함수
{
	while (getchar() != '\n');
}
