//2017.09.10
/*
다음 수열

1 2 4 6 5 3 (next = 1 2 5 3 4 6)
< < < > >
i는 4번째
오른쪽 끝부터 쌍으로 비교했을때
왼쪽이 오른쪽보다 커야 함

4번째 부터 감소해가는 수열 발생
i-1보다 크면서 감소수열 상 가장 작은수
발견한 j와 i-1 swap
이후부터 오름차순으로 감소 수열 정리


이전 수열

1 2 4 6 5 3 (prev = 1 2 4 6 3 5)
< < < > >
i는 5번째
오른쪽 끝부터 쌍으로 비교시
왼쪽이 오른쪽보다 작아야 함.

5번째가 가장 바깥쪽인 감소수열
i-1인 5보다 작으면서 가장 작은 3

발견한 j와 i-1 swap
이후부터 오름차순으로 감소 수열 정리

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool prevPermu(int *a, int N);
//bool nextPermu(vector<int> &a, int N);

int main() {
	int N;
	int a[10000];
	cin >> N;
	//vector<int> a(N);
	for (int i = 0; i<N; i++)
		cin >> a[i];

	if (prevPermu(a, N))
		//if (next_permutation(a, a+N))
		//if(next_permutation(a.begin(), a.end()))
		for (int i = 0; i < N; i++)
			cout << a[i] << ' ';
	else
		cout << -1;

	cout << '\n';
	return 0;
}

bool prevPermu(int *a, int N) {
	//bool nextPermu(vector<int> &a, int N) {

	int i = N - 1;
	while (i > 0 && a[i - 1] <= a[i])
		i--;
	if (i <= 0) return false;

	int j = N - 1;
	while (j > i - 1 && a[i - 1] <= a[j]) j--;
	swap(a[i - 1], a[j]);
	j = N - 1;

	while (i<j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
	return true;
}