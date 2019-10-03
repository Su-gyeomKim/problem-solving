//2017.09.10
/*
���� ����

1 2 4 6 5 3 (next = 1 2 5 3 4 6)
< < < > >
i�� 4��°
������ ������ ������ ��������
������ �����ʺ��� Ŀ�� ��

4��° ���� �����ذ��� ���� �߻�
i-1���� ũ�鼭 ���Ҽ��� �� ���� ������
�߰��� j�� i-1 swap
���ĺ��� ������������ ���� ���� ����


���� ����

1 2 4 6 5 3 (prev = 1 2 4 6 3 5)
< < < > >
i�� 5��°
������ ������ ������ �񱳽�
������ �����ʺ��� �۾ƾ� ��.

5��°�� ���� �ٱ����� ���Ҽ���
i-1�� 5���� �����鼭 ���� ���� 3

�߰��� j�� i-1 swap
���ĺ��� ������������ ���� ���� ����

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