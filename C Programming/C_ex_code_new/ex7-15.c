#include <stdio.h>
void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *));
int compareInt(void *vp1, void *vp2);	// vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
int compareDouble(void *vp1, void *vp2);	// vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double  y[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	int number = 5;
	double dNumber = 5.5;
	int *ip;
	double *dp;
	size_t size = sizeof(x) / sizeof(x[0]);
	ip = (int *)find(x, x + size, &number, sizeof(int), compareInt);
	if (ip == x + size) { printf("not find\n"); }
	else { printf("find data = %d\n", *ip); }

	size = sizeof(y) / sizeof(y[0]);
	dp = (double *)find(y, y + size, &dNumber, sizeof(double), compareDouble);
	if (dp == y + size) { printf("not find\n"); }
	else { printf("find data = %lf\n", *dp); }
	return 0;
}
