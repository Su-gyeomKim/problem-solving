#include <stdio.h>

int M[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // 각 달의 일 수, 누적으로 계산하기 위해 0월 부터
char D[7][4] = { "SUN","MON","TUE","WED","THU","FRI","SAT" }; // 7로 나눈 나머지로 각 요일 저장

int main()
{
	int Sum = 0; // 누적일수

	int x, y; //입력받을 변수 x=month, y=day
	scanf("%d %d", &x, &y);

	for (int i = 0; i<x; i++) Sum = Sum + M[i]; //누적 일수
	int date = (Sum + y) % 7; //date는 정확한 날짜 (누적 일 + 입력 일)
	printf("%s\n", D[date]);

	return 0;
}