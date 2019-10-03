//2017.09.19

/// https://www.acmicpc.net/problem/10819
/// N개의 정수로 이루어진 배열 A가 주어진다. 이 때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최대값을 구하는 프로그램을 작성하시오. 
/// |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|
/// 첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.
/// 첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.


/// 이해안되는건  [0],[2],[4] 씩 +=2 여야되는거 아닌가? ++이 아니고??

#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;


#define MAX 8
#define MIN 3

int calculate(int *a,int n);

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int fac(int n) {
	if (n == 1)return 1;
	else return n*fac(n - 1);
}

int next_permu(int *a, int n);

int main() {
	int n,i, answer=0;
	int A[MAX];
	//int A[6] = { 20, 1, 15, 8, 4, 10};

	cin >> n;

	for (i = 0; i < n; i++) 		cin >> A[i];
	
	qsort(A, n, sizeof(int), compare);
	for (i = 0; i < fac(n); i++) {
		if(next_permu(A,n))					if (answer < calculate(A, n)) 				answer = calculate(A, n);
		
	}
	cout << answer<<'\n';
	return 0;
}

int calculate(int *a, int n) {
	int temp=0,result=0;
	//for (int j = 0; j < n - 1; j+=2){//2개씩 계싼이면 1개는 건너뛰어야 되어야되는거 아닌가?
	for (int j = 0; j < n-1; j++) {
		temp = a[j] - a[j+1];
		if (temp < 0) temp = -temp;
		result += temp;
	}
	return result;
}

/*int next_permu(int* a, int n) { //에러있음.
	int i = n-1;
	while (i < 0 && a[i-1] >= a[i]) i--;
	if (i <= 0) return false;
	
	int j = n - 1;
	while (j > i - 1 && a[i - 1] >= a[i - 1]) j--;
	int temp = 0;
	temp = a[i-1];
	a[i - 1] = a[j];
	a[j] = temp;

	while(i<j){
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
	return true;
}*/

int next_permu(int *a, int N) {
	//bool nextPermu(vector<int> &a, int N) {

	int i = N - 1;
	while (i > 0 && a[i - 1] >= a[i])
		i--;
	if (i <= 0) return false;

	int j = N - 1;
	while (j > i - 1 && a[i - 1] >= a[j]) j--;
	swap(a[i - 1], a[j]);
	j = N - 1;

	while (i<j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
	return true;
}
