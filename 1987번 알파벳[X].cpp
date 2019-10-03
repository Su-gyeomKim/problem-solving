#include<iostream>
#include<queue>
using namespace std;
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#define N 21

int map[N][N];
bool alphabet[26];
char a[N*N];
int n, r, c;
int ans;

int yx[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
typedef pair<int, int> p;
queue <p> q;

void dfs(int i, int j, int cnt) {		
	bool flag = 0;
	alphabet[map[i][j]] = 1;
	a[cnt] = map[i][j]+'A';
	//cout << char(map[i][j] + 'A');
	for (int d = 0; d < 4; d++) {
		int y = i + yx[d][0], x = j + yx[d][1];
		if (y < 0 || x < 0 || y >= r || x >= c || alphabet[map[y][x]]) continue;
		
		dfs(y, x, cnt + 1);
	}
	if (cnt >= 100) {
		for (int k = 1; k <= cnt; k++)
			cout << a[k];
		cout << endl;
	}
	ans = ans < cnt ? cnt : ans;
	
	alphabet[map[i][j]] = 0;
	a[cnt] = 0;
}

void bfs() {
	while (!q.empty()) {
		p p = q.front();
		int i = p.first, j = p.second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int y = +yx[d][0], x = j + yx[d][1];
			if (y < 0 || x < 0 || y >= r || x >= c || alphabet[map[y][x]]) continue;
			q.push(make_pair(y, x));
		}
		ans = ans < q.size() ? q.size() : ans;
	}
}

int main() {
	freopen("1.txt", "r", stdin); setbuf(stdout, NULL);
	
	cin >> r >> c;
	for(int i=0; i<r; i++)
		for (int j = 0; j < c; j++) {
			char a; cin >> a;
			map[i][j] = a - 'A';
		}

	for (int i = 0; i<r; i++)		for (int j = 0; j < c; j++) {			memset(alphabet, 0, 26);			
			//q.push(make_pair(i, j));			bfs();
		}
	dfs(0, 0, 1);
	cout << ans;
}