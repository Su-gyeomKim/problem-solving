/*
#include <stdio.h>
#pragma warning(disable:4996)
int min;
int costTable[4];
int plan[12];

void search(int month, int cost) {
	if (month >= 12) {
		if (min > cost)
			min = cost;
		return;
	}
	search(month + 1, cost + costTable[0] * plan[month]);
	search(month + 1, cost + costTable[1]);
	search(month + 3, cost + costTable[2]);
	search(month + 12, cost + costTable[3]);
}

int main() {
	int testCases, tc, i;
	scanf("%d", &testCases);
	for (tc = 1; tc <= testCases; tc++) {
		min = 1 << 30;

		for (i = 0; i < 4; i++)
			scanf("%d", &costTable[i]);
		for (i = 0; i < 12; i++)
			scanf("%d", &plan[i]);

		search(0, 0);

		printf("#%d %d\n", tc, min);
	}
	return 0;
}

*/

/*#include<iostream>

using namespace std;

int Min;
int price[4];
int plan[12];

void sum(int month, int cost) {
	if (month >= 12) {
		if (Min>cost)   
			Min = cost;
		return;
	}
	sum(month + 1, cost + plan[month] * price[0]);
	sum(month + 1, cost + price[1]);
	sum(month + 3, cost + price[2]);
}
int main() {
	int t;
	int i, j;
	cin >> t;
	for (i = 1; i <= t; i++) {
		
		for (j = 0; j<4; j++) cin >> price[j];
		for (j = 0; j<12; j++) cin >> plan[j];
		Min = price[3];
		sum(0, 0);
		
		cout << '#' << i << ' ' << Min << '\n';
	}
	return 0;
}*/
/*
#include<cstdio>
#include<algorithm>

int test_case, T;
int comp(const void *a, const void *b) { return *(int *)b - *(int*)a; }

#define max(a,b) (a>b? a:b)
#define min(a,b) (a<b? a:b)

int map[100], t, n, top, btm;
int main() {
	while (t++<10) {
		freopen("input.txt", "r", stdin);
		setbuf(stdout, NULL);
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i<100; i++)    scanf("%d", &map[i]);
		qsort(a, 100, 4, comp);
		for (int i = 0; i <= n; i++) {
			top = btm = 0;
			for (int j = 0; j < 100; j++) {
				if (map[top] < map[j]) top = j;
				if (map[btm] > map[j]) btm = j;
			}
			if (i == n) ans = map[top] - map[btm];
			map[top]--; map[btm]++;
		}
		printf("#%d %d\n", t, ans);
	}for (int m = 0; m < 100; m++) same[m] = 0;

	return 0;
}

*/
/*
#include<iostream>
using namespace std;
#include<algorithm>
int a[1001][1001], d[1001][1001];

int main() {
	int t; cin >> t;
	for (int k = 1; k <= t; k++) {
		int tc, n; cin >> tc >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
			d[i][j] = max(d[i - 1][j], d[i][j - 1]) + a[i][j];
			if (ans<d[i][j]) ans = d[i][j];
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}*/
#include <cstdio>
#pragma warning(disable:4996)

int n, ans;
int a[15][2];

void dfs(int day, int value) {
	if (day == n) if (ans < value) ans = value;
	if (day > n - 1) return;

	dfs(day + a[day][0], value + a[day][1]);
	dfs(day + 1, value);
}

int main() {

	freopen("1.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
	}
	for (int i = 0; i < n; i++) {
		dfs(i, 0);
	}
	printf("%d \n", ans);
	return 0;
}