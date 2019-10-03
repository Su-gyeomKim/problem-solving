//2017.09.19

/// https://www.acmicpc.net/problem/10819
/// N���� ������ �̷���� �迭 A�� �־�����. �� ��, �迭�� ����ִ� ������ ������ ������ �ٲ㼭 ���� ���� �ִ밪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
/// |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|
/// ù° �ٿ� N (3 �� N �� 8)�� �־�����. ��° �ٿ��� �迭 A�� ����ִ� ������ �־�����. �迭�� ����ִ� ������ -100���� ũ�ų� ����, 100���� �۰ų� ����.
/// ù° �ٿ� �迭�� ����ִ� ���� ������ ������ �ٲ㼭 ���� �� �ִ� ���� �ִ��� ����Ѵ�.


/// ���ؾȵǴ°�  [0],[2],[4] �� +=2 ���ߵǴ°� �ƴѰ�? ++�� �ƴϰ�??

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
	//for (int j = 0; j < n - 1; j+=2){//2���� ����̸� 1���� �ǳʶپ�� �Ǿ�ߵǴ°� �ƴѰ�?
	for (int j = 0; j < n-1; j++) {
		temp = a[j] - a[j+1];
		if (temp < 0) temp = -temp;
		result += temp;
	}
	return result;
}

/*int next_permu(int* a, int n) { //��������.
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
