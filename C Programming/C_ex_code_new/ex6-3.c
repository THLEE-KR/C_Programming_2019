#include <stdio.h>
void array_input(int p[][4], int row);  // void array_input(int (*p)[4], int row);  
void array_output(int p[][4], int row); // void array_output(int (*p)[4], int row);
int main()
{
	int  num_ary[3][4];
	int row, col;

	// 행의 개수 구하기
	row = sizeof(num_ary) / sizeof(num_ary[0]);
	// 열의 개수 구하기
	//col = sizeof(num_ary[0]) / sizeof(num_ary[0][0]); 
	array_input(num_ary, row);
	array_output(num_ary, row);
	return 0;
}
void array_input(int p[][4], int row)
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d행%d열 방의 값입력: ", i, j);
			scanf("%d", &p[i][j]);
		}
	}
	return;
}

void array_output(int p[][4], int row)
{
	// TODO
}
