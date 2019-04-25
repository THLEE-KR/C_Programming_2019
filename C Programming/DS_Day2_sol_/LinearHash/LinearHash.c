#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "LinearHash.h"

/*--------------------------------------------------------------------------------------
Function name	: createHash() - 해시 생성 및 초기화 함수
Parameters		: hp - 해시관리 구조체의 주소,  size - 해시 테이블의 사이즈
Returns			: 성공적으로 생성하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
bool_t createHash(hash_t *hsp, int size) {
	if (hsp == NULL) {  							/* hsp포인터 NULL check*/
		return FALSE;
	}

	hsp->hash = (int *)calloc(size, sizeof(int));  	/* hash 메모리 할당 */
	if (hsp->hash != NULL) {						/* hash 메모리 할당 설공 시*/
		hsp->size = size;							/* hash size 초기화 */
		memset(hsp->hash, 0xff, sizeof(int) * size);
		return TRUE;
	}
	else {											/* hash 메모리 할당 실패 시 */
		return FALSE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: hashFunction() - 해시값 계산 함수
Parameters		: hsp - 해시관리 구조체의 주소,  key - key값
Returns			: 해시값 리턴
--------------------------------------------------------------------------------------*/
int hashFunction(hash_t *hsp, int key) {
	int keySum=0;

	if (hsp == NULL) {  							/* hsp포인터 NULL check*/
		return FALSE;
	}

	/* key값을 한자리씩 분리하여 배열에 저장 */
	while(key > 0) {
		keySum += key%10;
		key /= 10;
	}
	printf("keySum = %d\n", keySum);
	return keySum%hsp->size;
}
/*--------------------------------------------------------------------------------------
Function name	: hashInput() - 해시에 데이터 삽입 함
Parameters		: hsp - 해시관리 구조체의 주소,  iData - 해시에 저장할 데이터 값
Returns			: 성공적으로 삽입하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
bool_t hashInput(hash_t *hsp, int iData) {
	int firstHashValue;
	int hashValue;

	if (hsp == NULL) {  							/* hsp포인터 NULL check*/
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
Function name	: hashSearch() - 해시에서 데이터를 찾음
Parameters		: hsp - 해시관리 구조체의 주소,  sData - 해시에서 찾을 데이터 값
Returns			: 성공 - 찾은 데이터의 해시 값, 실패 - -1 리턴
--------------------------------------------------------------------------------------*/
int hashSearch(hash_t *hsp, int sData) {
	int firstHashValue;
	int hashValue;

	if (hsp == NULL) {  							/* hsp포인터 NULL check*/
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
Function name	: hashDelete() - 해시에 데이터 삭제 함
Parameters		: hsp - 해시관리 구조체의 주소,  dData - 해시에서 삭제할 데이터 값
Returns			: 성공적으로 삭제하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
bool_t hashDelete(hash_t *hsp, int dData) {
	int hashValue;

	if (hsp == NULL) {  							/* hsp포인터 NULL check*/
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
Function name	: destroyHash() - 해시 소멸 함수
Parameters		: hsp - 해시관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyHash(hash_t *hsp) {
	if (hsp == NULL) {  							/* hsp포인터 NULL check*/
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
Function name	: hashPrint() - 해시에 저장된 데이터 출력 함수
Parameters		: hsp - 해시관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void hashPrint(hash_t *hsp) {
	int i;

	if (hsp == NULL) {  							/* hsp포인터 NULL check*/
		return;
	}

	printf("hash data : ");
	for(i=0; i<hsp->size; i++)
		printf("%5d", hsp->hash[i]);

	printf("\n");
	return;
}
