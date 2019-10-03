#include<iostream>
using namespace std;

int a[2][15];
int n, ans;

void dfs(int day, int cost) {
	if (day == n) if (ans < cost) ans = cost;
	if (day > n - 1) return;

	dfs(day + a[0][day], cost + a[1][day]);
	dfs(day + 1, cost);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[0][i] >> a[1][i];

	for (int i = 0; i < n; i++)
		dfs(i, 0);
	cout << ans;
}

/*
#include<iostream>
using namespace std;
int d[15];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int t, p;  cin >> t >> p;
		d[i + 1] = max(d[i + 1], d[i]);
		d[i + t] = max(d[i + t], d[i] + p);
	}
	
	cout << d[n];
	}
	*/