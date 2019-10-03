#include <iostream>
#include <queue>

#pragma warning(disable:4996)

using namespace std;

#define N 10001
#define chk y<1 || x<1 || y>h || x>w 
#define chkB map[y][x] == '#' || map[y][x] == '*'

int T;
int w, h;
char map[N][N];
int map1[N][N];
bool visit[N][N];
int ans = 2147468347;
int cnt;
//¡è¡é¡ç¡æ
int yx[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

struct p {
	int y, x;
	char c;
};

queue<p>q;

void bfs() {
	//for (int i = 1; i <= h; i++)		for (int j = 1; j <= w; j++)			map1[i][j] = map[i][j];

	//int q_size = q.size();
	//if (!q_size) return;
	while (!q.empty()) {
		int y, x;
		p p = q.front();
		int i = p.y, j = p.x;
		char c = p.c;
		q.pop();

		for (int d = 0; d < 4; d++) {
			y = i + yx[d][0], x = j + yx[d][1];

			if (c == '@') {
				if (chkB) continue;

				if (chk) {
					cnt++;
					ans = min(ans, cnt);
					return;
				}

				map[y][x] = '@', map[i][j] = '.';
				p.y = y, p.x = x, p.c = map[y][x];
				q.push(p);
			}
			else {
				if (chk || chkB) continue;
				map[y][x] = '*';
				p.y = y, p.x = x, p.c = map[y][x];
				q.push(p);
			}
		}
	}
}
/*
int dfs(int y, int x, int cnt) {
	int die = 0;

	visit[y][x] = 1;

	for (int d = 0; d < 4; d++) {		int ny = y + yx[d][0], nx = x + yx[d][1]; 		if (map[ny][nx] == '*'||map[ny][nx]=='#') { 			die++;						if (die == 4)								return 2;		}		}
	

	for (int d = 0; d < 4; d++) {
		int ny = y + yx[d][0], nx = x + yx[d][1];
		
		if (chkB(ny,nx))continue;
		if(visit[ny][nx]) continue;
		if (chk(ny, nx)) {
 			ans = min(ans,cnt + 1);
			//return ans;
		}
		bfs();
		if (map[ny][nx] != '*' && map[ny][nx] != '#') {
			map[ny][nx] = '@', map[y][x] = '.';
		}

		//if (!chk(ny, nx)) 	
		if ((!(ny<1 || nx<1 || ny>h || nx>w)) && map[ny][nx]!='#' && map[ny][nx]!='*') {
			dfs(ny, nx, cnt + 1);
			//for (int i = 1; i <= h; i++)				for (int j = 1; j <= w; j++)					map[i][j] = map1[i][j];
			visit[ny][nx]=0;
		}
	}	
	return -1;
}
*/
int main() {

	freopen("1.txt", "r", stdin); setbuf(stdout, NULL);

	cin >> T;
	while (T--) {
		cin >> w >> h;

		int y, x;

		for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++) { map[i][j] = 0; visit[i][j] = 0; cnt = 0; }
		while (!q.empty()) q.pop();
		ans = 2147468347;

		p p;
		for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				p.y = i, p.x = j, p.c = map[i][j];	q.push(p);
			}
			if (map[i][j] == '@') {
				p.y = i, p.x = j; p.c = map[i][j];	q.push(p);
			}
		}
		//dfs(y, x, 0);
		bfs();
		if (ans != 2147468347) cout << ans << '\n';
		else cout << "IMPOSSIBLE" << '\n';
	}
}
