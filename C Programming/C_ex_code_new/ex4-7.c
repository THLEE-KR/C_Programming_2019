#include <stdio.h>
#include<windows.h>
int main()
{
	int  kor = 0, eng = 0, mat = 0, result, total;
	printf("������ ������ �Է��Ͻÿ� : ");
	result = scanf("%d %d %d", &kor, &eng, &mat);
	if (result == 3){
		total = kor + eng + mat;
		printf("���� : %d��\n", total);
	}
	else {
		printf("�Էµ����� �����Դϴ�.\n");
	}
	printf("scanf()�Լ��� ���ϰ� : %d\n", result);

	system("pause");  // ���α׷� ��� ����
	return 0;
}
