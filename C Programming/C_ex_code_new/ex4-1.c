#include<stdio.h>
int main()
{
	int  score ;
	char  remark ;
	printf("점수를 입력하세요 :  ") ;
	scanf("%d", & score) ;
	switch(score / 10)
	{
	case  10 :
	case  9  : remark = 'A' ;  break ;
	case  8  : remark = 'B' ;  break ;
	case  7  : remark = 'C' ;  break ;
	case  6  : remark = 'D' ;  break ;
	default   : remark = 'F' ;
	}
	printf("점수는 %d  학점은 %c  입니다 \n", score, remark) ;

	getchar(); getchar();
	return 0;
}
