#include <iostream>
#pragma warning(disable:4996)
#define _CRT_NO_SECURE_WARNINGS

using namespace std;
#define N 21
#define K 1000
#define chk(i,j,n,m) i<0 || j<0|| i>=n || j>=m

int map[N][N];
//0 위, 1 정면, 2 아래, 3 후, 4 좌, 5 우
//int dice[6];
int cmd[K];
int n, m;

struct dice{
	int y, x;
}d;
int a[6],cpy[6];
// 0 동, 1 서, 2 북, 3 남
int yx[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };


void dice_and_map(dice d, bool flag) {
	if (flag)	a[2] = map[d.y][d.x], map[d.y][d.x] = 0;
	else map[d.y][d.x] = a[2];
}

	//1:동	//2:서	 //3:북	//4:남
//	012345	012345	 012345	012345
//	415320	514302 	 123045	301245
// +402023 +403041 +3-111   +1113
void roll(int y, int x, int cnt) {

	for (int i = 0; i < 6; i++) cpy[i] = a[i];
	d.y = y + yx[cmd[cnt] - 1][0], d.x = x + yx[cmd[cnt] - 1][1];
	
	if (chk(d.y, d.x, n, m)) {
		d.y = y, d.x = x; return;
	}

	bool flag=0;
	if (map[d.y][d.x]) flag = 1;
	
	if (cmd[cnt] == 1) {
		a[0] = cpy[4], a[2] = cpy[5], a[4] = cpy[2], a[5] = cpy[0];
		dice_and_map(d, flag);
	}
	if (cmd[cnt] == 2) {
		a[0] = cpy[5], a[2] = cpy[4], a[4] = cpy[0], a[5] = cpy[2];
		dice_and_map(d, flag);
	}
	if (cmd[cnt] == 3) {
		for (int i = 0; i < 3; i++) a[i] = cpy[i + 1];		a[3] = cpy[0];
		dice_and_map(d, flag);
	}
	if (cmd[cnt] == 4) {
		for (int i = 1; i < 4; i++) a[i] = cpy[i - 1];		a[0] = cpy[3];
		dice_and_map(d, flag);
	}
	cout << a[0] << '\n';
}

int main() {
	//freopen("1.txt", "r", stdin);
	int y, x, k;

	cin >> n >> m >> y >> x >> k;
	d.y = y, d.x = x;

	for(int i=0; i<n; i++)		for (int j = 0; j < m; j++)			cin >> map[i][j];
	for (int i = 0; i < k; i++) 		cin >> cmd[i];
	for (int i = 0; i < k; i++) 		roll(d.y, d.x, i);
}