#include <iostream>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define N 20001
#define smaller(a, b) a=a<b?a:b

//int map[N][N]; 메모리 초과

vector< vector<int> >map;

int V, E;
int k;
int u, v, w;
int ans;

bool flag;

void dfs(int from, int to, int sum) {
	//vertex is connected
	if (map[from][to] != 0) {
		ans = sum + map[from][to];
		return;
	}
	//if vertex is not connected
	else 
		for (int i = 0; i < V; i++) 
			if (map[from][i]) {
				if (map[i][to]) {
					if (!flag) { ans = sum + map[from][i] + map[i][to]; flag = 1; }
					else smaller(ans, sum + map[from][i] + map[i][to]);
				}
				else 
					dfs(i, to, sum+map[from][i]);
			}
	
	return;
}
int main() {
	freopen("1.txt", "r", stdin); setbuf(stdout, NULL);
	
	cin >> V >> E >> k;
	for (int i = 0; i < V; i++)
	{
		vector<int> column;
		column.resize(E);
		map.push_back(column);
	}

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		map[u - 1][v - 1] = w;
	}
	
	for (int i = 0; i < V; i++) {
		// start edge ans dest edge is same
		if (i == k - 1) {cout << 0 << '\n'; continue;}
		ans = 0, flag = 0;
		dfs(k - 1, i, 0);
		if (ans > 0 ? cout << ans << '\n' : cout << "INF" << '\n');
	}
}