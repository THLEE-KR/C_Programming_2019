#include<stdio.h>
int   abs ( int ) ; 
int main()
{
     int  num ; 
     printf("하나의 수를 입력하세요 : ") ;
     scanf("%d" , &num) ; 
     printf("절대값 : %d \n" , abs(num) ) ; 
     getchar();
     return 0;
}
int  abs (int  x)
{
     if ( x > 0 )  { return  (x) ; }
     else   { return  (-x) ; }
}
