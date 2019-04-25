#ifndef HEAP_H_
#define HEAP_H_
#define MAX 100										/* heap의 최대 저장 데이터 수 */
typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _heap {
   int *heap;										/* heap 공간 */
   int size;										/* heap의 크기 */
   int count;										/* heap에 저장되어 있는 데이터의 수 */
} heap_t;

bool_t createHeap(heap_t *hp, int size);			/* 힙 생성 함수 */
bool_t isHeapEmpty(heap_t *hp);						/* 힙이 완전히 비어 있는가 검사 */
bool_t isHeapFull(heap_t *hp);						/* 힙이 꽉 차 있는가 검사 */
bool_t insertHeap(heap_t *hp, int inData);			/* 힙에 데이터 삽입 */
bool_t deleteHeap(heap_t *hp, int *getData);		/* 힙에 데이터 삭제 */
void reHeapUp(heap_t *hp, int child);
void reHeapDown(heap_t *hp, int parent);			/* 지정 노드를 위치에 맞게 down 시킴 */
void printHeap(const heap_t *hp);					/* 힙의 데이터 출력(상위->하위 방향) */
void destroyHeap(heap_t *hp);						/* 힙 소멸 함수 */

#endif /* HEAP_H_ */
