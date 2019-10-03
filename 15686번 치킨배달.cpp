#include <iostream>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

#define N 50
#define S 13

int map[N][N];
struct pos { int y; int x; int val; };
pos me[2 * N], ss[S];
pos c[S];
bool v[S];

int n, m,ans= 2147468347;
int idx_me, idx_ss;

int dist(int m_idx, int s_idx) {
	return abs(c[s_idx].y - me[m_idx].y) + abs(c[s_idx].x - me[m_idx].x);
}

void update() {
	int total_time = 0;

	for (int s_idx = 0; s_idx < m; s_idx++) {
		for(int m_idx=0; m_idx<idx_me; m_idx++){}
	}
}

 int dfs2(int idx) {
	int far = 2147468347;
	int y = me[idx].y, x = me[idx].x;

	for (int i = 0; i < m; i++) {
		//far = min(far, abs(c[i].y - me[idx].y) + abs(c[i].x - me[idx].x));
		far = min(far, dist(idx, i));
	}
	return far;
}

void dfs(int idx, int cnt) {
	if (v[idx]) return;
	c[cnt-1].val = -1, c[cnt-1].y = ss[idx].y, c[cnt-1].x = ss[idx].x;
	v[idx] = 1;

	if (cnt == m) {
		int sum = 0;
		for (int i = 0; i < idx_me; i++) {
			int far = 2147468347;
			
			for (int j = 0; j < m; j++) {
				far = min(far, dist(i, j));
			}
			sum += far;
		}
		if (ans > sum) {
			ans = sum;
			return;
		}
		else
			return;
	}

	for (int i = 0; i < idx_ss; i++) {
		if (i == idx || v[i]) continue;
		dfs(i, cnt + 1);
		v[i] = 0;
	}
	//v[idx] = 0;
	return;
}


int main() {
	freopen("15686.txt", "r", stdin); setbuf(stdout, NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> map[i][j];
		if (map[i][j] == 1) {
			me[idx_me].y = i, me[idx_me].x = j;
			idx_me++;
		}
		if (map[i][j] == 2) {
			ss[idx_ss].y = i, ss[idx_ss].x = j;
			idx_ss++;
		}
	}

	for (int i = 0; i < idx_ss; i++)
		dfs(i, 1);

	cout << ans;
}