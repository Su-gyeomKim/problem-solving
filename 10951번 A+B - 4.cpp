#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int n, m;
	//scanf�� EOF(End Of File)���� ó���ϴ� 3���� ���

	// 1. scanf�� return���� ~(=not)�� ������
	//while (~scanf("%d %d", &n, &m))		

	//2. scanf�� return���� NULL�� ������(ä���� ����ʰ� �߻�)
	//while (scanf("%d %d", &n, &m)!=NULL) 

	//3. scanf�� return���� ���������� ���� ������ �����̴�.
	while (scanf("%d %d", &n, &m) == 2)

		printf("%d \n", m + n);
	return 0;
}