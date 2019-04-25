#include <stdio.h>

int f(int n);

int main(void) {
	int T;
	int n;
	int tc;
	
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (tc=0 ; tc<T ; tc++) {
		scanf("%d", &n);
		printf("%d\n", f(n));
	}
	
	return 0;
}

int f(int n) {
	if (n <= 2) {
		return n;
	}
	else {
		return (f(n-2) + f(n-1));
	}
}
