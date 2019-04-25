#include<stdio.h>
#include<stdlib.h>
#include "ChainingHash.h"

/*--------------------------------------------------------------------------------------
Function name	: createHash() - 해시 생성 및 초기화 함수
Parameters		: hsp - 해시관리 구조체의 주소,  size - 해시 테이블의 사이즈
Returns			: 성공적으로 생성하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
bool_t createHash(hash_t *hsp, int size) {
	int i;

	if (hsp == NULL) {  									/* hsp포인터 NULL check*/
		return FALSE;
	}

	hsp->hash = (node_t *)calloc(size, sizeof(node_t));  	/* hash 메모리 할당 */

	if (hsp->hash != NULL) {								/* hash 메모리 할당 설공 시*/
		for (i=0 ; i<size ; i++) {
			hsp->hash[i].key = NOTUSED;
		}
		hsp->size = size;									/* hash size 초기화 */
		hsp->dataCnt = 0;   								/* hash dataCnt 초기화 */
		return TRUE;
	}
	else {													/* hash 메모리 할당 실패 시 */
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

	// key값을 한자리씩 분리하여 배열에 저장
	while (key > 0) {
		keySum += key%10;
		key /= 10;
	}
	printf("keySum = %d\n", keySum);

	return keySum % hsp->size;
}

/*--------------------------------------------------------------------------------------
Function name	: hashInput() - 해시에 데이터 삽입 함
Parameters		: hsp - 해시관리 구조체의 주소,  iData - 해시에 저장할 값
Returns			: 성공적으로 삽입하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
bool_t hashInput(hash_t *hsp, int iData) {
	int hashValue;
	node_t *np;   											/* 새 node_t의 주소를 저장할 포인터 */
	if (hsp == NULL) {  									/* hsp 포인터 NULL check*/
		return FALSE;
	}
	hashValue = hashFunction(hsp, iData);
	if (hsp->hash[hashValue].key == NOTUSED) {
		hsp->hash[hashValue].key = iData;
	}
	else {
		np = (node_t *)calloc(1, sizeof(node_t));
		if(np == NULL) {
			return FALSE;										/* 새노드 할당을 실패하면 FALSE 리턴 */
		}
		np->key = iData;
		np->next = hsp->hash[hashValue].next;  					/* 해시테이블의 해당 버킷의 첫번째 노드의 정보를 새 노드의 next에 저장 */
		hsp->hash[hashValue].next = np; 						/* 새 노드의 주소를 해시테이블의 해당 버킷의 첫번째 노드로 등록 */
	}
	hsp->dataCnt++;
	return TRUE;
}

/*--------------------------------------------------------------------------------------
Function name	: hashSearch() - 해시에서 데이터를 찾음
Parameters		: hp - 해시관리 구조체의 주소,  sData - 해시에 찾을 데이터 값
Returns			: 찾은 데이터의 해시 값, 못찾으면 -1 리턴
--------------------------------------------------------------------------------------*/
int hashSearch(hash_t *hsp, int sData) {
	int hashValue;
	node_t *sp;   											/* 검색용 node_t 포인터변수 */

	if (hsp == NULL) {  									/* hsp포인터 NULL check*/
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
Function name	: hashDelete() - 해시에 데이터 삭제 함
Parameters		: hsp - 해시관리 구조체의 주소,  dData - 해시에서 삭제할 값
Returns			: 성공적으로 삭제하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
bool_t hashDelete(hash_t *hsp, int dData) {
	int hashValue;
	node_t *sp;   											/* 삭제할 node_t 포인터변수 */
	node_t *pre;  											/* 삭제할 node_t 앞노드를 가리킬 포인터 */
	if (hsp == NULL) {  									/* hsp 포인터 NULL check*/
		return FALSE;
	}
	hashValue = hashFunction(hsp, dData);
	pre = &hsp->hash[hashValue];
	if (pre->key == dData) {  // 배열의 방에 있는 데이터 삭제 시 
		sp = pre->next;
		if (sp != NULL) {
			*pre=*sp; // 배열의 방에 바로 연결되어있는 노드로 덮어씀 
		}
		else {
			pre->key = NOTUSED;
		}
		hsp->dataCnt--;
		return TRUE;
	}
	else {  // 노드영역에 있는 데이터 이면
		sp = pre->next;
		while (sp != NULL) {
			if (sp->key == dData) {  							/* 삭제할 데이터를 찾음 */
				pre->next = sp->next;
				free(sp);
				hsp->dataCnt--;
				return TRUE;  									/* 삭제가 성공했으므로 TRUE 리턴 */
			}
			else {                 								/* 못찾았으면 다음 노드로 이동 */
				pre = sp;
				sp = sp->next;
			}
		}
	}
	return FALSE;
}

/*--------------------------------------------------------------------------------------
Function name	: destroyHash() - 해시 소멸 함수
Parameters		: hsp - 해시관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyHash(hash_t *hsp) {
	int i;
	node_t *np;
	if (hsp == NULL) { 										/* hsp포인터 NULL check*/
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
Function name	: hashPrint() - 해시에 저장된 데이터 출력 함수
Parameters		: hsp - 해시관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void hashPrint(hash_t *hsp) {
	int i;
	node_t *np;
	if (hsp == NULL) {  									/* hsp포인터 NULL check*/
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
