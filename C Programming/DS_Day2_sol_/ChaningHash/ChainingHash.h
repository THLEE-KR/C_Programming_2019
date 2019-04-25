#ifndef CHAININGHASH_H_
#define CHAININGHASH_H_
#define NOTUSED -1
typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _node {
	int key;
	struct _node *next;
} node_t;

typedef struct _chaining_hash {
	node_t *hash;									/* Node ���·� ����Ǵ� �ؽ� ���̺� */
	int size;										/* hash table ũ�� (bucket ũ��) */
	int dataCnt;									/* hash table���� �������� ���� */
} hash_t;
bool_t createHash(hash_t *hsp, int size);			/* �ؽ� ���� �� �ʱ�ȭ �Լ� */
int hashFunction(hash_t *hsp, int key);				/* �ؽ� �� ��� �Լ� */
bool_t hashInput(hash_t *hsp, int insertData);		/* �ؽÿ� ������ ������ */
int hashSearch(hash_t *hsp, int searchData);		/* �ؽÿ��� �����͸� ã�� */
bool_t hashDelete(hash_t *hsp, int deleteData);		/* �ؽÿ� ������ ������ */
void destroyHash(hash_t *hsp);						/* �ؽ� �Ҹ� �Լ� */
void hashPrint(hash_t *hsp);						/* �׽�Ʈ�� �Լ� - �ؽ� ���̺��� ���� ��� */

#endif /* CHAININGHASH_H_ */
