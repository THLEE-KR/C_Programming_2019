#include<stdio.h>
int   abs ( int ) ; 
int main()
{
     int  num ; 
     printf("�ϳ��� ���� �Է��ϼ��� : ") ;
     scanf("%d" , &num) ; 
     printf("���밪 : %d \n" , abs(num) ) ; 
     getchar();
     return 0;
}
int  abs (int  x)
{
     if ( x > 0 )  { return  (x) ; }
     else   { return  (-x) ; }
}
