
#include <iostream>
#pragma warning(disable:4996)
#define _CRT_NO_SECURE_WARNINGS

using namespace std;
#define N 21

int map[N][N];
int n, ans;
//0좌 1상 2우 3하
int yx[4][2] = { {0,-1} ,{-1,0},{0,1},{1,0} };

//방향값 검사용
int dd[5];

void dfs(int board[][N], int dir, int cnt, int biggest) {
	dd[cnt - 1] = dir;

	//이동하고 나서 바뀐 맵을 저장할 변수
	int tmp[N][N];
	memset(tmp, 0, sizeof(int)*N*N);

	//이동하고 나서 바뀐 맵을 저장하고 최댓값을 찾음
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) {
		tmp[i][j] = board[i][j];
		if (tmp[i][j] > biggest) biggest = tmp[i][j];
		if (ans == 128) {
			while (1)
				break;
		}
	}
	//if (dd[0] == 3 && dd[1] == 1 && cnt ==3) {		cout << "hep";	}

	if (dd[0] == 2 && dd[1] == 1 && dd[2] == 2 && dd[3] == 1 && cnt==5 && dir==2){//&& dd[4] == 2 && cnt == 6) {		
		cout << "hep";	}
	//5번하고나면 ans를 최댓값으로 바꿔주고 종료
	if (cnt >= 6) {
		if (ans < biggest) 	ans = biggest;
		return;
	}
	if (dir == 0) {
		for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) {
			if (tmp[i][j] == 0) {
				int k = j;
				while (tmp[i][k] == 0 && k < n) k++;
				if (k > n - 1) continue;
				tmp[i][j] = tmp[i][k];
				tmp[i][k] = 0;
			}
			if (tmp[j][i] && tmp[j + 1][i] == 0) {
				int k = j + 1;
				while (tmp[i][k] == 0 && k < n) k++;
				if (k > n - 1) continue;
				if (tmp[i][j] == tmp[i][k]) {
					tmp[i][j] *= 2;
					tmp[i][k] = 0;
				}
			}
			else if (tmp[i][j + 1] && tmp[i][j] && tmp[i][j] == tmp[i][j + 1]) {
				tmp[i][j] *= 2;
				tmp[i][j + 1] = 0;
			}
			else if (tmp[i][j - 1] && tmp[i][j] && tmp[i][j - 1] == tmp[i][j]) {
				tmp[i][j - 1] *= 2;
				tmp[i][j] = 0;
			}
		}
	}

	if (dir == 2) {
		for (int i = 0; i < n; i++) for (int j = n - 1; j >= 0; j--) {
			if (tmp[i][j] == 0) {
				int k = j;
				while (tmp[i][k] == 0 && k >= 0) k--;
				if (k < 0) continue;
				tmp[i][j] = tmp[i][k];
				tmp[i][k] = 0;
			}
			if (tmp[j][i] && tmp[j - 1][i] == 0) {
				int k = j - 1;
				while (tmp[i][k] == 0 && k >= 0) k--;
				if (k < 0) continue;
				if (tmp[i][j] == tmp[i][k]) {
					tmp[i][j] *= 2;
					tmp[i][k] = 0;
				}
			}
			else if (tmp[i][j + 1] && tmp[i][j] && tmp[i][j] == tmp[i][j + 1]) {
				tmp[i][j + 1] *= 2;
				tmp[i][j] = 0;
			}
			else if (tmp[i][j - 1] && tmp[i][j] && tmp[i][j - 1] == tmp[i][j]) {
				//tmp[i][j] *= 2;
				tmp[i][j - 1] = 0;
			}
		}
	}

	if (dir == 1) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			if (tmp[j][i] == 0) {
				int k = j;
				while (tmp[k][i] == 0 && k < n) k++;
				if (k > n - 1) continue;
				tmp[j][i] = tmp[k][i];
				tmp[k][i] = 0;
			}
			if (tmp[j][i] && tmp[j + 1][i] == 0) {
				int k = j + 1;
				while (tmp[k][i] == 0 && k < n) k++;
				if (k > n - 1) continue;
				if (tmp[j][i] == tmp[k][i]) {
					tmp[j][i] *= 2;
					tmp[k][i] = 0;
				}
			}
			else if (tmp[j + 1][i] && tmp[j][i] && tmp[j + 1][i] == tmp[j][i]) {
				tmp[j][i] *= 2;
				tmp[j + 1][i] = 0;
			}
			else if (tmp[j - 1][i] && tmp[j][i] && tmp[j - 1][i] == tmp[j][i]) {
				tmp[j - 1][i] *= 2;
				tmp[j][i] = 0;
			}

		}
	}
	if (dir == 3) {
		while (1) break;
	}
	if (dir == 3) {
		for (int i = 0; i < n; i++) for (int j = n - 1; j >= 0; j--) {
			if (tmp[j][i] == 0) {
				int k = j-1;
				while (tmp[k][i] == 0 && k >= 0) k--;
				if (k < 0) continue;
				tmp[j][i] = tmp[k][i];
				tmp[k][i] = 0;
			}
			if (tmp[j][i] && tmp[j - 1][i] == 0) {
				int k = j - 1;
				while (tmp[k][i] == 0 && k >= 0) k--;
				if (k < 0) continue;
				if (tmp[j][i] == tmp[k][i]) {
					tmp[j][i] *= 2;
					tmp[k][i] = 0;
				}
			}
			else if (tmp[j+1][i] && tmp[j][i] && tmp[j+1][i] == tmp[j][i]) {
				tmp[j+1][i] *= 2;
				tmp[j][i] = 0;
			}
			else if (tmp[j-1][i] && tmp[j][i] && tmp[j][i] == tmp[j-1][i]) {
				//tmp[j][i] *= 2;
				tmp[j-1][i] = 0;
			}
		}
	}

	
	//방향별로 리컬시브하게 돌림
	dfs(tmp, 0, cnt + 1, biggest);
	dfs(tmp, 1, cnt + 1, biggest);
	dfs(tmp, 2, cnt + 1, biggest);
	dfs(tmp, 3, cnt + 1, biggest);
}


int main() {
	freopen("12100.txt", "r", stdin); setbuf(stdout, NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) cin >> map[i][j];

	for (int i = 0; i < 4; i++) dfs(map, i, 1, 0);
	
	cout << ans;
}

/*
#pragma warning(disable: 4996)

#include<stdio.h>

int n, ans;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
int dd[5];
void move(int pan[22][22], int x) {
	if (x == 5) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (pan[i][j] == 64) {
					for (int k = 0; k < 5; k++)
						printf("%d ", dd[k]);
				}
				if (pan[i][j] > ans) ans = pan[i][j];
			}
		}
		return;
	}
	if (dd[0] == 1 && dd[1] == 2 && dd[2] == 2 && dd[3] == 1) {
		int k = 1;
	}
	int newpan[22][22] = { 0, };
	// To Right
	for (int i = 1; i <= n; i++) {
		int prev = -1, last = n;
		for (int j = n; j >= 1; j--) {
			newpan[i][j] = 0;
			if (pan[i][j] == 0) continue;
			if (pan[i][j] == prev) {
				prev = -1;
				newpan[i][last + 1] *= 2;
				continue;
			}
			else {
				prev = pan[i][j];
				newpan[i][last] = pan[i][j];
				last--;
			}
		}
	}
	dd[x] = 2;
	move(newpan, x + 1);
	// To Left
	for (int i = 1; i <= n; i++) {
		int prev = -1, last = 1;
		for (int j = 1; j <= n; j++) {
			newpan[i][j] = 0;
			if (pan[i][j] == 0) continue;
			if (pan[i][j] == prev) {
				prev = -1;
				newpan[i][last - 1] *= 2;
				continue;
			}
			else {
				prev = pan[i][j];
				newpan[i][last] = pan[i][j];
				last++;
			}
		}
	}
	dd[x]= 0;
	move(newpan, x + 1);
	// To Up
	for (int j = 1; j <= n; j++) {
		int prev = -1, last = 1;
		for (int i = 1; i <= n; i++) {
			newpan[i][j] = 0;
			if (pan[i][j] == 0) continue;
			if (pan[i][j] == prev) {
				prev = -1;
				newpan[last - 1][j] *= 2;
				continue;
			}
			else {
				prev = pan[i][j];
				newpan[last][j] = pan[i][j];
				last++;
			}
		}
	}
	dd[x] = 1;
	move(newpan, x + 1);
	// To Down
	for (int j = 1; j <= n; j++) {
		int prev = -1, last = n;
		for (int i = n; i >= 1; i--) {
			newpan[i][j] = 0;
			if (pan[i][j] == 0) continue;
			if (pan[i][j] == prev) {
				prev = -1;
				newpan[last + 1][j] *= 2;
				continue;
			}
			else {
				prev = pan[i][j];
				newpan[last][j] = pan[i][j];
				last--;
			}
		}
	}
	dd[x]= 3;
	move(newpan, x + 1);
}

int main() {

	freopen("12100.txt", "r", stdin);

	int pan[22][22];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &pan[i][j]);
		}
	}

	move(pan, 0);
	printf("%d\n", ans);
	
	return 0;
	}
	*/