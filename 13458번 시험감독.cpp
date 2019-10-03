#include<iostream>
#pragma warning(disable:4996)
using namespace std;

#define MAX 100000

int main() {
	freopen("1.txt", "r", stdin);
	int n;
	int a[MAX];
	long long int main, sub;

	cin >> n;
	for (int i = 0; i<n; i++) cin >> a[i];
	cin >> main >> sub;

	long long int ans = 0;

	for (int i = 0; i<n; i++) {
		if (a[i] - main <= 0) {
			ans += 1;
			continue;
		}

		a[i] -= main;
		ans += 1;

		if (a[i] - sub <= 0) {
			ans += 1;
			continue;
		}
		

		if (a[i] % sub == 0) {
			ans += a[i] / sub;
			continue;
		}
		else {
			ans += a[i] / sub + 1;
			continue;
		}
	}
	cout << ans;
	return 0;
}