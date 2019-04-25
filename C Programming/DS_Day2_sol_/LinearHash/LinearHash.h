#ifndef LINEARHASH_H_
#define LINEARHASH_H_

#define EMPTY -1								/* 비어있는 상태 */
#define DELETE -2								/* 삭제된 상태 */
typedef enum { FALSE, TRUE } bool_t;

typedef struct _linear_hash {
     int *hash;   								/* int값 저장 해시테이블 */
     int size;    								/* hash table의 크기 */
} hash_t;

bool_t createHash(hash_t *hsp, int size);		/* 해시 생성 및 초기화 함수 */
int hashFunction(hash_t *hsp, int key);			/* 해시값 계산 함수 */
bool_t hashInput(hash_t *hsp, int insertData);	/* 해시에 데이터 삽입 함 */
int hashSearch(hash_t *hsp, int searchData);	/* 해시에서 데이터를 찾음 */
bool_t hashDelete(hash_t *hsp, int deleteData);	/* 해시에 데이터 삭제 함 */
void destroyHash(hash_t *hsp);					/* 해시 소멸 함수 */
void hashPrint(hash_t *hsp); 					/* 테스트용 함수-해시 테이블의 내용 출력 */

#endif /* LINEARHASH_H_ */
