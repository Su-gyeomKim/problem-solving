#include <iostream>
#include <queue>
using namespace std;

#pragma warning(disable:4996)

#define N 51-44
#define cmp(a,b) (a<b? a:b)

char map[N][N];
bool visit[N][N];
int n, m, y, x;
int yx[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int ans=51*51;
bool chk;

typedef pair<int, int> p;
//queue<pair<p,int>> q;
queue<p> q;

void bfs() {

	int cnt = 0;

	while (!q.empty()) {

		p pos = q.front();
		y = pos.first;
		x = pos.second;
		q.pop();
		//visit[y][x] = 1;

		if (map[y][x] == 'S') {
			for (int i = 0; i < 4; i++) {
				int ny = y + yx[i][0], nx = x + yx[i][1];
				if (map[ny][nx] == 'D') {
					cnt++;
					ans = cmp(ans, cnt);
					chk = 1;
					return;
				}
			}
		}

		if (map[y][x] == 'S' || map[y][x] == 'D') {
			for (int i = 0; i < 4; i++) {
				int ny = y + yx[i][0], nx = x + yx[i][1];
				if (ny < 1 || ny>n || nx<1 || nx>m || map[ny][nx] == 'X' || visit[ny][nx]) continue;

				if (map[ny][nx] == '.') {

					visit[ny][nx] = 1;

					if (map[y][x] == '*' && map[ny][nx] == '.')
						map[ny][nx] = '*';

					else if (map[y][x] == 'S') {
						//visit[y][x] = 1;
						char temp = map[ny][nx];
						map[ny][nx] = map[y][x];
						map[y][x] = temp;
						cnt++;
						if (map[ny][nx] == 'D') {
							cnt++;
							ans = cmp(ans, cnt);
							chk = 1;
							return;
						}
					}

					q.push(p(ny, nx));
				}

			}
		}
	}
}


int main() {

	freopen("1.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	//for (int i = 1; i <= n; i++)	scanf("%s", &map[i]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j] == 'S' || map[i][j] == '*') {
				q.push(p(i, j));
			}
	chk;
	bfs();
	if (!chk) cout << "KAKTUS" << '\n';
	else
		cout << ans << '\n';
}
