#include <iostream>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

#define MAX 1001
#define comp(a,b) (a>b?a:b)

int map[MAX][MAX];
int n, m;
int ans=1, tomato;
int yx[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

typedef pair<int, int> pos;
queue <pos> q;

void bfs() {
	while (!q.empty()) {
		pos start = q.front();
		int y = start.first;
		int x = start.second;
		q.pop();
		tomato--;
		for (int i = 0; i < 4; i++) {
			int ny = y + yx[i][0], nx = x+yx[i][1];
			if (ny <1 || ny >n || nx<1 || nx>m) continue;
			if (map[ny][nx] == 0) {
				map[ny][nx] = map[y][x] + 1;
				ans = comp(map[ny][nx], ans);
				q.push(pos(ny, nx));
			}
		}
	}

	if (tomato == 0) {
		cout << ans-1 << '\n';
	}
	else {
		cout << -1<<  '\n';
	}
}

int main() {

	cin >> m >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0 || map[i][j] == 1) tomato++;
			if (map[i][j] == 1) q.push(pos(i, j));
		}

	bfs();
}