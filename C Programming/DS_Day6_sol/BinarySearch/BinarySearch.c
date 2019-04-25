#include <stdio.h>
#include "BinarySearch.h"
/*----------------------------------------------------------------
Function name	: binarySearch() - �̺а˻� �Լ�
Parameters		: ary - ������ �˻� ��� �迭
				  left - �˻� ������ ���� �ε���
				  right - �˻� ������ ���� �ε���
				  key - �˻��� ������
Returns			: �˻� ���� �� ã�� ������ index
				    �˻� ���� �� -1 ����
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
