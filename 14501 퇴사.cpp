#include <iostream>
#include <algorithm>
#pragma warning (disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
#define N 20
int a[N][2];
int d[N];
int n,ans;

void dfs(int day, int sum) {
	if (day == n) ans = ans < sum ? sum : ans;
	if (day > n - 1) return;

	dfs(day + a[day][0], sum + a[day][1]);
	dfs(day + 1, sum);
}

int main() {
	freopen("14501.txt", "r", stdin); setbuf(stdout, NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];

	for (int i = 0; i <= n; i++) {
		d[i + 1] = max(d[i + 1], d[i]);
		d[i + a[i][0]] = max(d[i + a[i][0]], d[i] + a[i][1]);
	}
	//cout << d[n]<<endl;
	dfs(a[0][0], a[0][1]);
	cout << ans;
}