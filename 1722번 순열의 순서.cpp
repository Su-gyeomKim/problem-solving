//2017.09.10

#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 20

bool NextPermutation(int *a, int N, int &C);

int main() {
	int N, M, k, i;
	int count;
	int a[MAX],b[MAX];

	cin >> N;
	
	for (i = 0; i < N; i++) a[i] = i + 1;
	count = 1;

	cin >> M;
	
	switch (M) {

	case 1:
		cin >> k;
		if (count == k)
			for (i = 0; i < N; i++)
				cout << a[i] << ' ';

		else
			while (NextPermutation(a, N, count))
				if (count == k)
					for (i = 0; i < N; i++)
						cout << a[i] << ' ';
		break;
	
	case 2:
		for (i = 0; i < N; i++)
			cin >> b[i];
		for (i = 0; i < N; i++)
			while (b[i] != a[i])
				NextPermutation(a, N, count);
		cout << count;
		break;
	
	default:
		return 0;
	}

	return 0;
}

bool NextPermutation(int *a, int N, int &C) {
	int i = N - 1;
	while (i > 0 && a[i - 1] >= a[i])
		i--;
	if (i <= 0) return false;
	int j = N - 1;
	while (j > i - 1 && a[i - 1] >= a[j]) j--;
	swap(a[i - 1], a[j]);
	j = N - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++; j--;
	}

	C++;

	return true;
}