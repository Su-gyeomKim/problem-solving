#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#define N 10+1
#define G 200

//int comp(const void *a, const void *b) { return *(int*)a - *(int*)b; }

int map[N][N], map_cpy[N][N], visit[N][N];
int n, seed, ans, Min, Max = 2147483647;
int yx[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

bool CanBloom(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + yx[i][0], nx = x + yx[i][1];
		if (ny < 0 || ny >= n || nx <0 || nx >= n)
			return 0;
		if (visit[ny][nx])
			return 0;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + yx[i][0], nx = x + yx[i][1];
		visit[ny][nx] = 1;
	}
}

void dfs(int y, int x, int seed, int cnt) {
	if (seed == 0) 
		memset(visit, 0, sizeof(visit));
	
	if (visit[y][x])		return;

	//if (y > 0 && y < n && x > 0 && x < n) {
		visit[y][x] = 1;
	//}

	if (seed == 3) {
		ans = ans > cnt ? ans : cnt;
		return;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (!CanBloom(i, j)) continue;
			dfs(i, j, seed + 1, cnt+map[i][j]);
		}
}

int main() {
	freopen("14260.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> map[i][j]; 
		
	dfs(0,0,0,map[0][0]);
	
	cout << ans<<'\n';
}