/*
#include <iostream>

#define MAX 1000
#define DIGIT 3

using namespace std;

int IsClap(int *a) {
	int count = 0;
	for (int k = 0; k<DIGIT; k++)    if (a[k] == 3 || a[k] == 6 || a[k] == 9) count += 1;
	return count;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i<t + 1; i++) {
		if (((i % 10 == 3) || (i % 10 == 6) || (i % 10 == 9)) || ((i / 100 == 3) || (i / 100 == 6) || (i / 100 == 9)) || ((i / 10 == 3) || (i / 10 == 6) || (i / 10 == 9))) {
			int a[DIGIT] = { i / 100, i / 10, i % 10 };
			for (int j = 0; j<IsClap(a); j++) cout << '-';
			cout << ' ';
		}
		else cout << i << ' ';
	}
	return 0;
}
*/