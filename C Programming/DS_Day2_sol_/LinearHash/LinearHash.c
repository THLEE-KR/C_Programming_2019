#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "LinearHash.h"

/*--------------------------------------------------------------------------------------
Function name	: createHash() - �ؽ� ���� �� �ʱ�ȭ �Լ�
Parameters		: hp - �ؽð��� ����ü�� �ּ�,  size - �ؽ� ���̺��� ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
bool_t createHash(hash_t *hsp, int size) {
	if (hsp == NULL) {  							/* hsp������ NULL check*/
		return FALSE;
	}

	hsp->hash = (int *)calloc(size, sizeof(int));  	/* hash �޸� �Ҵ� */
	if (hsp->hash != NULL) {						/* hash �޸� �Ҵ� ���� ��*/
		hsp->size = size;							/* hash size �ʱ�ȭ */
		memset(hsp->hash, 0xff, sizeof(int) * size);
		return TRUE;
	}
	else {											/* hash �޸� �Ҵ� ���� �� */
		return FALSE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: hashFunction() - �ؽð� ��� �Լ�
Parameters		: hsp - �ؽð��� ����ü�� �ּ�,  key - key��
Returns			: �ؽð� ����
--------------------------------------------------------------------------------------*/
int hashFunction(hash_t *hsp, int key) {
	int keySum=0;

	if (hsp == NULL) {  							/* hsp������ NULL check*/
		return FALSE;
	}

	/* key���� ���ڸ��� �и��Ͽ� �迭�� ���� */
	while(key > 0) {
		keySum += key%10;
		key /= 10;
	}
	printf("keySum = %d\n", keySum);
	return keySum%hsp->size;
}
/*--------------------------------------------------------------------------------------
Function name	: hashInput() - �ؽÿ� ������ ���� ��
Parameters		: hsp - �ؽð��� ����ü�� �ּ�,  iData - �ؽÿ� ������ ������ ��
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
bool_t hashInput(hash_t *hsp, int iData) {
	int firstHashValue;
	int hashValue;

	if (hsp == NULL) {  							/* hsp������ NULL check*/
		return FALSE;
	}

	hashValue=firstHashValue = hashFunction(hsp, iData);

	while(hsp->hash[hashValue] != EMPTY && hsp->hash[hashValue] != DELETE) {
		hashValue=(hashValue+1) % hsp->size;
		if(hashValue == firstHashValue) {
			return FALSE;
		}
	}
	hsp->hash[hashValue] = iData;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: hashSearch() - �ؽÿ��� �����͸� ã��
Parameters		: hsp - �ؽð��� ����ü�� �ּ�,  sData - �ؽÿ��� ã�� ������ ��
Returns			: ���� - ã�� �������� �ؽ� ��, ���� - -1 ����
--------------------------------------------------------------------------------------*/
int hashSearch(hash_t *hsp, int sData) {
	int firstHashValue;
	int hashValue;

	if (hsp == NULL) {  							/* hsp������ NULL check*/
		return -1;
	}

	hashValue=firstHashValue = hashFunction(hsp, sData);

	while(hsp->hash[hashValue] != sData) {
		hashValue=(hashValue+1) % hsp->size;
		if(hashValue == firstHashValue){
			return -1;
		}
	}
	return hashValue;
}

/*--------------------------------------------------------------------------------------
Function name	: hashDelete() - �ؽÿ� ������ ���� ��
Parameters		: hsp - �ؽð��� ����ü�� �ּ�,  dData - �ؽÿ��� ������ ������ ��
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
bool_t hashDelete(hash_t *hsp, int dData) {
	int hashValue;

	if (hsp == NULL) {  							/* hsp������ NULL check*/
		return FALSE;
	}

	hashValue=hashSearch(hsp, dData);
	if(hashValue != -1){
		hsp->hash[hashValue] = DELETE;
		return TRUE;
	}
	else{
		return FALSE;
	}
}

/*--------------------------------------------------------------------------------------
Function name	: destroyHash() - �ؽ� �Ҹ� �Լ�
Parameters		: hsp - �ؽð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyHash(hash_t *hsp) {
	if (hsp == NULL) {  							/* hsp������ NULL check*/
		return;
	}

	if(hsp->hash != NULL) {
		free(hsp->hash);
	}

	hsp->hash = NULL;
	hsp->size = 0;

	return;
}

/*--------------------------------------------------------------------------------------
Function name	: hashPrint() - �ؽÿ� ����� ������ ��� �Լ�
Parameters		: hsp - �ؽð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void hashPrint(hash_t *hsp) {
	int i;

	if (hsp == NULL) {  							/* hsp������ NULL check*/
		return;
	}

	printf("hash data : ");
	for(i=0; i<hsp->size; i++)
		printf("%5d", hsp->hash[i]);

	printf("\n");
	return;
}
