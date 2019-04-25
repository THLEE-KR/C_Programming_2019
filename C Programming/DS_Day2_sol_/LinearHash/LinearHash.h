#ifndef LINEARHASH_H_
#define LINEARHASH_H_

#define EMPTY -1								/* ����ִ� ���� */
#define DELETE -2								/* ������ ���� */
typedef enum { FALSE, TRUE } bool_t;

typedef struct _linear_hash {
     int *hash;   								/* int�� ���� �ؽ����̺� */
     int size;    								/* hash table�� ũ�� */
} hash_t;

bool_t createHash(hash_t *hsp, int size);		/* �ؽ� ���� �� �ʱ�ȭ �Լ� */
int hashFunction(hash_t *hsp, int key);			/* �ؽð� ��� �Լ� */
bool_t hashInput(hash_t *hsp, int insertData);	/* �ؽÿ� ������ ���� �� */
int hashSearch(hash_t *hsp, int searchData);	/* �ؽÿ��� �����͸� ã�� */
bool_t hashDelete(hash_t *hsp, int deleteData);	/* �ؽÿ� ������ ���� �� */
void destroyHash(hash_t *hsp);					/* �ؽ� �Ҹ� �Լ� */
void hashPrint(hash_t *hsp); 					/* �׽�Ʈ�� �Լ�-�ؽ� ���̺��� ���� ��� */

#endif /* LINEARHASH_H_ */
