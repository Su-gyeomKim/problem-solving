#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
#define N 21
	 
int a[N][N];
bool vi[N];
int n, ans=2147468347, flag;

void dfs(int i, int cnt,bool v[N]) {
	
	v[i] = 1;

	if (cnt == n / 2) {
		int sum1 = 0, sum2 = 0, half=0;
		for (int i = 0; i < n; i++) if (v[i]) half++;
		
		if (half == n / 2) {
			for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
				if (i == j) continue;
				if (vi[i] && vi[j]) sum1 += a[i][j] + a[j][i];
				if (!vi[i] && !vi[j]) sum2 += a[i][j] + a[j][i];
			}
			if (ans > abs(sum1 - sum2)) ans = abs(sum1 - sum2);
		}

		else {
			v[i] = 0; cnt--;
		}

		return;
	}

 	for (int j = i + 1; j < n-1; j++) {
		dfs(j, cnt + 1, v);
		v[j] = 0;
 	}
}

int main() {
	freopen("14889.txt", "r", stdin); setbuf(stdout, NULL);

	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < N; j++) vi[j] = { 0 };
		dfs(i, 1, vi);
	}

	cout << ans;
}
