#include <stdio.h>
#include "BinarySearch.h"
/*----------------------------------------------------------------
Function name	: binarySearch() - 이분검색 함수
Parameters		: ary - 데이터 검색 대상 배열
				  left - 검색 구간의 좌측 인덱스
				  right - 검색 구간의 우측 인덱스
				  key - 검색할 데이터
Returns			: 검색 성공 시 찾은 숫자의 index
				    검색 실패 시 -1 리턴
----------------------------------------------------------------*/
int binarySearch(int ary[], int size, int key) {
	int left = 0;
	int right = size - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (ary[mid] > key) {
			right = mid - 1;
		}
		else if (ary[mid] < key) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}
