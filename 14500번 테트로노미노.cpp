#include <iostream>
using namespace std;
#pragma warning (disable:4996)

#define N 500

int a[N][N];
bool visit[N][N];
int dyx[4][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } };
int n, m, ans;

void dfs(int y, int x, int cnt, int sum) {
	if (cnt == 4) {
		if (ans< sum) ans = sum;
		return;
	}
	visit[y][x] = 1;
	for (int i = 0; i<4; i++) {
		int ny = y + dyx[i][0], nx = x + dyx[i][1];
		if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1 || visit[ny][nx]) continue;
		visit[ny][nx] = 1;
		dfs(ny, nx, cnt + 1, sum + a[ny][nx]);
		visit[ny][nx] = 0;
	}

	visit[y][x] = 0;
}

int solve(int y, int x) {
	
	int cnt = 0,
		val = 1e4,
		ret = a[y][x];

	for (int i = 0; i < 4; i++) {
		int ny = y + dyx[i][0], nx = x + dyx[i][1];

		if (cnt > 1) return 0; // 2회이상 cut되면ㅏㅓㅗㅜ 모양이 안나옴

		if (ny <0 || ny>n - 1 || nx<0 || nx>m - 1) 
			cnt++;			continue;

		// + 모양에서 하나를 빼서 ㅗㅜㅏㅓ를 만드는데 그 하나를(최소값) 찾음
		if (val > a[ny][nx]) 
			val = a[ny][nx];
		
		ret += a[ny][nx];
	}

	// +모양인 경우 (cnt==0)
	if (cnt == 0) 
		ret -= val;

	// ㅗㅜㅏㅓ인 경우(cnt==1) 그냥 return
	return ret;

}
int main() {
	freopen("4.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)    for (int j = 0; j < m; j++) cin >> a[i][j];
	ans = 0;
	for (int i = 0; i < n; i++)    for (int j = 0; j < m; j++) {
		dfs(i, j, 1, a[i][j]);
		ans = ans > solve(i, j) ? ans : solve(i, j);
	}

	cout << ans << endl;
}
