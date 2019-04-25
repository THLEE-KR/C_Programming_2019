#include<stdio.h>
#include<stdlib.h>
#include "ChainingHash.h"

/*--------------------------------------------------------------------------------------
Function name	: createHash() - �ؽ� ���� �� �ʱ�ȭ �Լ�
Parameters		: hsp - �ؽð��� ����ü�� �ּ�,  size - �ؽ� ���̺��� ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
bool_t createHash(hash_t *hsp, int size) {
	int i;

	if (hsp == NULL) {  									/* hsp������ NULL check*/
		return FALSE;
	}

	hsp->hash = (node_t *)calloc(size, sizeof(node_t));  	/* hash �޸� �Ҵ� */

	if (hsp->hash != NULL) {								/* hash �޸� �Ҵ� ���� ��*/
		for (i=0 ; i<size ; i++) {
			hsp->hash[i].key = NOTUSED;
		}
		hsp->size = size;									/* hash size �ʱ�ȭ */
		hsp->dataCnt = 0;   								/* hash dataCnt �ʱ�ȭ */
		return TRUE;
	}
	else {													/* hash �޸� �Ҵ� ���� �� */
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

	// key���� ���ڸ��� �и��Ͽ� �迭�� ����
	while (key > 0) {
		keySum += key%10;
		key /= 10;
	}
	printf("keySum = %d\n", keySum);

	return keySum % hsp->size;
}

/*--------------------------------------------------------------------------------------
Function name	: hashInput() - �ؽÿ� ������ ���� ��
Parameters		: hsp - �ؽð��� ����ü�� �ּ�,  iData - �ؽÿ� ������ ��
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
bool_t hashInput(hash_t *hsp, int iData) {
	int hashValue;
	node_t *np;   											/* �� node_t�� �ּҸ� ������ ������ */
	if (hsp == NULL) {  									/* hsp ������ NULL check*/
		return FALSE;
	}
	hashValue = hashFunction(hsp, iData);
	if (hsp->hash[hashValue].key == NOTUSED) {
		hsp->hash[hashValue].key = iData;
	}
	else {
		np = (node_t *)calloc(1, sizeof(node_t));
		if(np == NULL) {
			return FALSE;										/* ����� �Ҵ��� �����ϸ� FALSE ���� */
		}
		np->key = iData;
		np->next = hsp->hash[hashValue].next;  					/* �ؽ����̺��� �ش� ��Ŷ�� ù��° ����� ������ �� ����� next�� ���� */
		hsp->hash[hashValue].next = np; 						/* �� ����� �ּҸ� �ؽ����̺��� �ش� ��Ŷ�� ù��° ���� ��� */
	}
	hsp->dataCnt++;
	return TRUE;
}

/*--------------------------------------------------------------------------------------
Function name	: hashSearch() - �ؽÿ��� �����͸� ã��
Parameters		: hp - �ؽð��� ����ü�� �ּ�,  sData - �ؽÿ� ã�� ������ ��
Returns			: ã�� �������� �ؽ� ��, ��ã���� -1 ����
--------------------------------------------------------------------------------------*/
int hashSearch(hash_t *hsp, int sData) {
	int hashValue;
	node_t *sp;   											/* �˻��� node_t �����ͺ��� */

	if (hsp == NULL) {  									/* hsp������ NULL check*/
		return -1;
	}
	hashValue = hashFunction(hsp, sData);
	
	sp = &hsp->hash[hashValue];
	while(sp != NULL){
		if(sp->key==sData){
			return hashValue;
		}
		sp=sp->next;
	}
	return -1;
}

/*--------------------------------------------------------------------------------------
Function name	: hashDelete() - �ؽÿ� ������ ���� ��
Parameters		: hsp - �ؽð��� ����ü�� �ּ�,  dData - �ؽÿ��� ������ ��
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
bool_t hashDelete(hash_t *hsp, int dData) {
	int hashValue;
	node_t *sp;   											/* ������ node_t �����ͺ��� */
	node_t *pre;  											/* ������ node_t �ճ�带 ����ų ������ */
	if (hsp == NULL) {  									/* hsp ������ NULL check*/
		return FALSE;
	}
	hashValue = hashFunction(hsp, dData);
	pre = &hsp->hash[hashValue];
	if (pre->key == dData) {  // �迭�� �濡 �ִ� ������ ���� �� 
		sp = pre->next;
		if (sp != NULL) {
			*pre=*sp; // �迭�� �濡 �ٷ� ����Ǿ��ִ� ���� ��� 
		}
		else {
			pre->key = NOTUSED;
		}
		hsp->dataCnt--;
		return TRUE;
	}
	else {  // ��念���� �ִ� ������ �̸�
		sp = pre->next;
		while (sp != NULL) {
			if (sp->key == dData) {  							/* ������ �����͸� ã�� */
				pre->next = sp->next;
				free(sp);
				hsp->dataCnt--;
				return TRUE;  									/* ������ ���������Ƿ� TRUE ���� */
			}
			else {                 								/* ��ã������ ���� ���� �̵� */
				pre = sp;
				sp = sp->next;
			}
		}
	}
	return FALSE;
}

/*--------------------------------------------------------------------------------------
Function name	: destroyHash() - �ؽ� �Ҹ� �Լ�
Parameters		: hsp - �ؽð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyHash(hash_t *hsp) {
	int i;
	node_t *np;
	if (hsp == NULL) { 										/* hsp������ NULL check*/
		return;
	}
	if (hsp->hash != NULL) {
		for (i=0 ; i<hsp->size ; i++) {
			np = hsp->hash[i].next;
			printf("hash[%d] : ", i);

			while (np != NULL) {
				hsp->hash[i].next = np->next;
				//printf("%5d", np->key);
				free(np);
				np= hsp->hash[i].next;
			}
			printf("\n");
		}
		free(hsp->hash);
	}
	hsp->hash = NULL;
	hsp->size = 0;
	hsp->dataCnt = 0;
}

/*--------------------------------------------------------------------------------------
Function name	: hashPrint() - �ؽÿ� ����� ������ ��� �Լ�
Parameters		: hsp - �ؽð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void hashPrint(hash_t *hsp) {
	int i;
	node_t *np;
	if (hsp == NULL) {  									/* hsp������ NULL check*/
		return;
	}
	printf("hash data : \n");
	for (i=0 ; i<hsp->size ; i++) {
		printf("hash[%d] : ", i);

		if (hsp->hash[i].key != NOTUSED) {
			printf("%5d", hsp->hash[i].key);
			np = hsp->hash[i].next;
			while (np != NULL) {
				printf("%5d", np->key);
				np= np->next;
			}
		}

		printf("\n");
	}
	return;
}
