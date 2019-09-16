#include <iostream>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

#define N 50
#define S 13


struct pos { int y; int x; };
pos me[2 * N], ss[S];
pos c[S];
bool v[S];

int n, m,ans= 2147468347;
int idx_me, idx_ss;

int dist(int m_idx, int s_idx) {
	return abs(c[s_idx].y - me[m_idx].y) + abs(c[s_idx].x - me[m_idx].x);
}

void dfs(int idx, int cnt) {
	if (v[idx]) return;


	if (cnt >= m || idx >= idx_ss) {
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
	c[cnt].y = ss[idx].y, c[cnt].x = ss[idx].x;
    
	v[idx] = 1; 
    dfs(idx+1, cnt+1);
    v[idx] = 0;
    dfs(idx+1,cnt);
    
	return;
}


int main() {
	//freopen("15686.txt", "r", stdin); setbuf(stdout, NULL);
    int map[N][N];
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
	dfs(0, 0);

	cout << ans;
}
