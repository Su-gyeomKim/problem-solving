//2017.09.25
//https://www.acmicpc.net/problem/1152
/*
영어 대소문자와 띄어쓰기만으로 이루어진 문장이 주어진다. 이 문장에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 단, 단어는 띄어쓰기 하나로 구분된다고 생각한다.

입력
첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문장이 주어진다. 이 문장의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 단어의 개수를 출력한다.

예제 입력 
The Curious Case of Benjamin Button
예제 출력 
6
*/
#include<stdio.h>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

#define MAX 1000000

int main() {
	char a[MAX];
	int ans = 0;
	for (int i = 0; i < MAX; i++) a[i] = -1;

	scanf("%[^\n]", &a);
	//std::cin >> a;

	if (a[0] != -1 && a[0] != ' ') ans = 1; //배열의 첫번째 원소가 공백, -1이 아니면 단어가 하나 존재함.

	for (int i = 1; i<MAX; i++) {
		if (a[i - 1] == ' '&& a[i] != '\0' && a[i] != ' ') ans += 1; //첫번째 이후부터 조사하는데 직전 원소가 스페이스바이며, 단어이고, 스페이스바가 연속이거나, 줄바꿈이 아니면 카운트 증가.
		if (a[i] == -1) { break; }//초기화한 -1을 만나면 반복문을 종료
	}
	cout << ans;
	return 0;
}