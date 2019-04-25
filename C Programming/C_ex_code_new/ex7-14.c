#include <stdio.h>
int* find(int* begin, int* end, int value);

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	size_t size = sizeof(x) / sizeof(x[0]);

	int* p = find(x, x + size, 5);

	if (p == x + size) {
		printf("not find\n");
	}
	else {
		printf("find data = %d\n", *p);
	}

	p = find(x, x + size, 15);
	if (p == x + size)
	{
		printf("not find\n");
	}
	else
	{
		printf("find data = %d\n", *p);
	}

	return 0;
}

int* find(int* begin, int* end, int value)
{
	while (begin != end && *begin != value) {
		++begin;
	}

	return begin;
}
