#include <stdio.h>
#include<windows.h>
int main()
{
	int  kor = 0, eng = 0, mat = 0, result, total;
	printf("국영수 성적을 입력하시오 : ");
	result = scanf("%d %d %d", &kor, &eng, &mat);
	if (result == 3){
		total = kor + eng + mat;
		printf("총점 : %d점\n", total);
	}
	else {
		printf("입력데이터 오류입니다.\n");
	}
	printf("scanf()함수의 리턴값 : %d\n", result);

	system("pause");  // 프로그램 잠시 멈춤
	return 0;
}
