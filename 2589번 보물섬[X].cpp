#include <iostream>
#include <queue>
using namespace std;

#pragma warning(disable:4996)

#define N 51-42
#define cmp(a,b) (a>b? a:b)

char map[7][N];
bool visit[N][N];
int n, m,y,x;
int yx[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int ans;

//typedef pair<int, int> p;
//queue<pair<p,int>> q;
//queue<p,int> q;
/*
void bfs() {
	
	int cnt=0;

	while (!q.empty()) {
		
		p pos = q.front().first;
		y = pos.first;
		x = pos.second;
		q.pop();
		if (visit[y][x]) continue;
		cnt++;
		for (int i = 0; i < 4; i++) {
			int ny = y + yx[i][0], nx = x + yx[i][1];
			if (ny < 0 || ny>n || nx<0 || nx>m || map[ny][nx] == 'W' || visit[ny][nx]) continue;
			visit[ny][nx] = 1;
			ans = cmp(ans, cnt);
			//q.push(p(ny,nx),cnt+1);
		}
	}
}
*/

void dfs(int y, int x, int cnt) {

	for (int i = 0; i < 4; i++) {
		int ny = y + yx[i][0], nx = x + yx[i][1];
		if (ny < 1 || ny>n || nx<1 || nx>m || map[ny][nx] == 'W' || visit[ny][nx]) continue;
		visit[ny][nx] = 1;
		ans = cmp(ans, cnt);
		//ans = max(ans, cnt);
		dfs(ny, nx, cnt + 1);
	}
}

int main() {

	freopen("1.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	for (int i = 1; i <= n; i++)
		//scanf("%s", &map[i]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j] == 'L') {
				memset(visit, 0, sizeof(visit));
				visit[i][j];
				//q.push(p(i,j));
				//bfs();
				dfs(i,j,-1);
			}

	cout << ans<<'\n';
}

/*
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <memory.h>
#pragma warning(disable:4996)
using namespace std;

typedef pair<int, int> pii;

char map[52][52];
bool visit[52][52];
int n, m;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int bfs(int i, int j)
{
	queue<pair<pii, int>> q;

	q.push({ { i, j }, 0 });

	int get = 0;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;

		q.pop();
		if (visit[y][x])
			continue;

		get = max(get, cnt);
		visit[y][x] = true;

		for (int i = 0; i < 4; i++)
		{
			int hereY = y + dy[i];
			int hereX = x + dx[i];

			if (map[hereY][hereX] == 'W' || hereY < 0 || hereX < 0 || hereY >= n || hereX >= m || visit[hereY][hereX])
				continue;

			q.push({ { hereY,hereX },cnt + 1 });
		}
	}

	return get;
}

int main()
{

	freopen("1.txt", "r", stdin);
	setbuf(stdout, NULL);
	int get;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			memset(visit, false, sizeof(visit));
			if (map[i][j] == 'L')
				get = max(get, bfs(i, j));
		}
	}

	cout << get;
	return 0;
}
*/