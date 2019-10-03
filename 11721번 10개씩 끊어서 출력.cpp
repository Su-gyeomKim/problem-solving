#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m)==2) printf("%d", m+n);
	return 0;
}