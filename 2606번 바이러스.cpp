#include <iostream>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

#define N 101-94

bool visit[N];
int map[N][N];

int n, m, ans;
queue<int>q;

void bfs(int v) {
	visit[v] = 1;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (map[v][i] == 1 && !visit[i]) {
				visit[i] = 1;
				q.push(i);
				ans++;
				printf("bfs %d에서 %d로 이동\n", v+1, i+1);
				
				
			}
		}
	}
}
///*
void dfs(int v) {
	visit[v] = 1;
	
	for (int i = 0; i < n; i++) {

		if (map[v][i] == 1 && !visit[i]) {
			ans++;
			printf("dfs %d에서 %d로 이동\n", v+1, i+1);
			dfs(i);
		}
	}
	return;
}
//*/
int main() {
	freopen("1.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a -= 1; b -= 1;
		map[a][b] = map[b][a] = 1;
	}
	//bfs(0);
	dfs(0);
	cout << ans << '\n';
}