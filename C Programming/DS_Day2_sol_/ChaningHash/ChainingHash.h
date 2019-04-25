#ifndef CHAININGHASH_H_
#define CHAININGHASH_H_
#define NOTUSED -1
typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _node {
	int key;
	struct _node *next;
} node_t;

typedef struct _chaining_hash {
	node_t *hash;									/* Node 형태로 저장되는 해시 테이블 */
	int size;										/* hash table 크기 (bucket 크기) */
	int dataCnt;									/* hash table내의 데이터의 개수 */
} hash_t;
bool_t createHash(hash_t *hsp, int size);			/* 해시 생성 및 초기화 함수 */
int hashFunction(hash_t *hsp, int key);				/* 해시 값 계산 함수 */
bool_t hashInput(hash_t *hsp, int insertData);		/* 해시에 데이터 삽입함 */
int hashSearch(hash_t *hsp, int searchData);		/* 해시에서 데이터를 찾음 */
bool_t hashDelete(hash_t *hsp, int deleteData);		/* 해시에 데이터 삭제함 */
void destroyHash(hash_t *hsp);						/* 해시 소멸 함수 */
void hashPrint(hash_t *hsp);						/* 테스트용 함수 - 해시 테이블의 내용 출력 */

#endif /* CHAININGHASH_H_ */
