# include <stdio.h>
int  main()
{
	char   str1[8];
	char   str2[8] = {'P','r','o','g','r','a','m'};
	char   str3[] = "Good!";
	str1[0] = 'T' ;
	str1[1] = 'u' ;
	str1[2] = 'r' ;
	str1[3] = 'b' ;
	str1[4] = 'o' ;
	str1[5] = '-' ;
	str1[6] = 'C' ;
	str1[7] = '\0' ;  // <=== 이 줄은 꼭 필요한 것일까?
	printf("str1 : %s \n" , str1 ) ;
	printf("str2: %s \n" , str2 ) ;
	printf("str3 : %s \n" , str3 ) ;

	getchar();
	return 0;
}
