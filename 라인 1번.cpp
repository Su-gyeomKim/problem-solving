#include <iostream>
#pragma warning(disable:4996)
// include <cstdio>
// cin,cout 대신 scanf,printf를 사용하려면 iostream 대신 cstdio 를 사용하세요 .
#include <stdlib.h>
#include <string>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int B[1001], C[1001];

using namespace std;
int main() {
	freopen("1.txt", "r", stdin); 
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;

		cin >> n;

		int x, y;
		int idxB = 0, idxC = 0;
		string team;

		int cnt = 0;
		string win;

		for (int j = 0; j < n; j++) {

			cin >> x >> y >> team;

			if (team == "Brown") {
				if (x < 0) x = -x;
				if (y < 0) y = -y;
				B[idxB] = x + y;
				idxB++;
			}

			if (team == "Cony") {
				if (x < 0) x = -x;
				if (y < 0) y = -y;
				C[idxC] = x + y;
				idxC++;
			}

			//qsort(B, sizeof(B) / sizeof(int), sizeof(int), cmp);
			//qsort(C, sizeof(C) / sizeof(int), sizeof(int), cmp);
			if (j == n - 1) {

				if (idxC == 0) {
					cout << "Brown" << ' ' << idxB << '\n';
					break;
				}
				if (idxB == 0) {
					cout << "Cony" << ' ' << idxC << '\n';
					break;
				}

				qsort(B, idxB, sizeof(int), cmp);
				qsort(C, idxC, sizeof(int), cmp);

				if (B[0] < C[0]) {
					win = "Brown";
					for (int i = 0; i<idxB; i++) {
						if (B[i] < C[0]) cnt++;
					}
				}
				else {
					win = "Cony";
					for (int i = 0; i<idxC; i++) {
						if (C[i] < B[0]) cnt++;
					}
				}

				cout << win << ' ' << cnt << '\n';
			}
		}
	}
	return 0;
}