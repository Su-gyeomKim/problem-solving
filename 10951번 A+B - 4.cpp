#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int n, m;
	//scanf를 EOF(End Of File)까지 처리하는 3가지 방법

	// 1. scanf의 return값이 ~(=not)일 때까지
	//while (~scanf("%d %d", &n, &m))		

	//2. scanf의 return값이 NULL일 때까지(채점시 출력초과 발생)
	//while (scanf("%d %d", &n, &m)!=NULL) 

	//3. scanf의 return값은 성공적으로 받은 변수의 갯수이다.
	while (scanf("%d %d", &n, &m) == 2)

		printf("%d \n", m + n);
	return 0;
}