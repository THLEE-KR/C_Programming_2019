#include <stdio.h>
int inputInt(const char *);
void myflush(void);
int main()
{
	int score;
	char className;  
	char stuName[20];
	
	score = inputInt("������ �Է��Ͻÿ� : ");
	printf("class�� �Է��Ͻÿ�(A~C) : ");
	className = getchar();
	printf("�л����� �Է��Ͻÿ� : ");
	fgets(stuName, sizeof(stuName), stdin);

	printf("�л��� : %s / class : %c / ���� : %d\n", stuName, className, score);
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
void myflush(void) // �Է� ���� ���� �Լ�
{
	while (getchar() != '\n');
}
