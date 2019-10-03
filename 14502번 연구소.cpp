#include<iostream>
#include<queue>
#pragma warning(disable:4996)

using namespace std;
#define N 10

///0 = ∫Ûƒ≠, 1= ∫Æ, 2 = πŸ¿Ã∑ØΩ∫
int map[N][N], map1[N][N], map2[N][N];
bool visit[N][N];
int n, m;
int ans, cnt, idx;

typedef pair<int, int> pos;
pos p;
queue<pos> q_v, q_v1;

int yx[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void virus() {

	int cnt = 0;

	while (!q_v.empty()) {
		pos p = q_v.front();
		int y = p.first, x = p.second;
		q_v.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + yx[i][0], nx = x + yx[i][1];
			if (ny < 1 || nx<1 || ny>n || nx>m || map1[ny][nx] != 0) continue;
			map1[ny][nx] = 2;
			q_v.push(make_pair(ny, nx));
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (map1[i][j] == 0) {
				cnt++;
				ans = max(ans, cnt);
			}
		}
	return;
}


void reset() {	for (int i = 1; i <= n; i++)		for (int j = 1; j <= m; j++) {			map1[i][j] = map[i][j];		}}

void wall(int y, int x, int w) {
	
	map[y][x] = 1;
	visit[y][x] = 1;

	if (w==3) {
		q_v = q_v1;
		reset();
		virus();
		
		map[y][x] = 0;
		visit[y][x] = 0;
		return;
		}

	for (int i = y; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] || map[i][j] != 0) continue;
			wall(i, j, w + 1);
		}

	map[y][x] = 0; 
	visit[y][x] = 0;
}

int main() {
	freopen("1.txt", "r", stdin); setbuf(stdout, NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			map1[i][j] = map[i][j];
			if (map[i][j] == 2)				q_v.push(make_pair(i, j));
		}

	//reset();
	q_v1 = q_v;

	for (int i = 1; i <= n; i++)		
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != 0) continue;
			wall(i, j, 1);
		}

	cout << ans;
}
