#include <stdio.h>
#include "LinearHash.h"

int menu(const char **mList, size_t menuCnt);							/* �޴� ��� �� �޴���ȣ �Է� �Լ� */
void mInput(hash_t *hsp);												/* �Է¸޴� ó�� �Լ� */
void myDelete(hash_t *hsp);												/* �����޴� ó�� �Լ� */
void mSearch(hash_t *hsp);												/* �˻��޴� ó�� �Լ� */
void myflush(void);														/* �Է� ���� flush �Լ� */

int main(void) {
	hash_t hash;														/* �ؽ� ���� */
	const char *menuList[] = { "�Է� �ϱ�", "�����ϱ�", "�˻��ϱ�", "����" }; 	/* �޴� ����Ʈ */
	int menuCnt;														/* �޴����� ���庯�� */
	int menuNum;														/* �޴���ȣ ���庯�� */

	createHash(&hash, 10);												/* �ؽ� �ʱ�ȭ */
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);  					/* �޴� ���� ����ϱ� */

	while (1) {
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt) { 										/* ����޴� ���� �� �ݺ��� Ż���ϱ� */
			break;
		}
		switch (menuNum)
		{
		case 1: mInput(&hash);  break;
		case 2: myDelete(&hash); break;
		case 3: mSearch(&hash); 										/* hash���� ��� ������ ����ϱ�*/
		}
	}
	destroyHash(&hash); 												/* hash���� ��� ������ ����ϱ�*/
	
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name	: mInput() - �ؽÿ� �����͸� �ݺ������� �Է���
Parameters		: hsp - �ؽð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void mInput(hash_t *hsp)
{
	int data;

	while (1) {
		printf("������ �����������͸� �Է��Ͻÿ�(���ڳ� �Է� �� ����) : ");

		if (scanf("%d", &data) != 1) { 									/* ���ڰ� �ԷµǸ� while���� ��������*/
			myflush();
			break;
		}

		if (hashInput(hsp, data) == FALSE) {
			printf("�Է� ����!\n");
		}

		hashPrint(hsp);  // hash�� ���� ���� Ȯ���ϱ�
	}
}

/*--------------------------------------------------------------------------------------
Function name	: myDelete() - �ؽ��� �����͸� ���� ��
Parameters		: hsp - �ؽð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void myDelete(hash_t *hsp) {
	int data;

	while (1) {
		printf("������ �����������͸� �Է��Ͻÿ�(���ڳ� �Է� �� ����) : ");

		if (scanf("%d", &data) != 1) { 									/* ���ڰ� �ԷµǸ� while���� ��������*/
			myflush();
			break;
		}

		if (hashDelete(hsp, data) == FALSE) {
			printf("���� ����!\n");
		}

		hashPrint(hsp);  // hash�� ���� ���� Ȯ���ϱ�
	}
}

/*--------------------------------------------------------------------------------------
Function name	: mSearch - �ؽ����̺��� ������ �˻� �ϱ�
Parameters		: hsp - �ؽð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void mSearch(hash_t *hsp) {
	int data;
	int hashValue;

	while (1) {
		printf("�˻� �����������͸� �Է��Ͻÿ�(���ڳ� �Է� �� ����) : ");

		if (scanf("%d", &data) != 1) {									/* ���ڰ� �ԷµǸ� while���� ��������*/
			myflush();
			break;
		}

		if ((hashValue = hashSearch(hsp, data)) == -1) {
			printf("�˻� ����!\n");
		}
		else {
			printf("�˻� ���� - �ؽð� = %d\n", hashValue);
		}

		hashPrint(hsp);  // hash�� ���� ���� Ȯ���ϱ�
	}
}

/*--------------------------------------------------------------------------------------
Function name	: menu() - �޴��� ����ϰ� �޴���ȣ�� �Է¹޾� ������
Parameters		: menuLIst - �޴������ ���ڿ�
				  menuCnt  - �޴�����
Returns			: ���õȸ޴���ȣ
--------------------------------------------------------------------------------------*/
int menu(const char **menuList, size_t menuCnt) {
	int i;
	int menuNum = 0;													/* �Էµ� �޴���ȣ ���� ����*/
	int res;															/* scanf()�Լ��� ���ϰ� ���� ����*/

	for (i = 0; i<menuCnt; i++)	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt) { 								/* �޴���ȣ �������� ��ȣ�� �Էµɶ� ���� �ݺ�*/

		printf("# �޴���ȣ�� �Է��ϼ��� : ");
		res = scanf("%d", &menuNum);

		if (res != 1) { 												/* ������ �Էµ��� �ʾ�����*/
			myflush();  												/* �Է¹��� ����*/
			continue;
		}
	}

	return menuNum;
}

/*----------------------------------------------------------------------------------
Function name	: myflush - �Է� ���� ���� ��� ������ ����� �Լ�
Parameters		: ����
Returns			: ����
----------------------------------------------------------------------------------*/
void myflush(void) {
	while (getchar() != '\n') {
		;
	}
}
