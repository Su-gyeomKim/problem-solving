#include <iostream>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

#define N 1001-995
#define M 10001

int map[N][N];
bool visit[N];

int n, m, v;
pair<int, int> p;
queue<int> q;

void bfs(int v) {
	q.push(v);
	visit[v] = 1;
	
	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v << ' ';
		for (int i = 1; i <= n; i++)
			if (map[v][i] && !visit[i]) {
				visit[i] = 1;
				q.push(i);
			}
	}
}

void dfs(int v) {
	visit[v] = 1;
	cout << v << ' ';
	for (int i = 1; i <= n; i++)
		if (map[v][i] && !visit[i])
			dfs(i);
}

int main() {
	freopen("1.txt", "r", stdin);
	setbuf(stdout, NULL);
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	dfs(1);
	memset(visit, 0, sizeof(visit));
	cout << endl;
	bfs(1);
}