#include <iostream>
#include <queue>
using namespace std;

#pragma warning(disable:4996)

#define N 20
//이동 횟수는 5번, 5번 이동후 얻을 수 있는 최댓값.
#define chk y<0 || x<0 || y>n - 1 || x>n - 1

int map[N][N],Omap[N][N],Nmap[N][N];
int n;
int ans, cnt;
int from, to=n;
int i1;

int c[6],k;
// d= 0:좌,  1:우, 2:상,  3:하
//yx= 0:오른,2:왼, 3:아래,4:위로 
int yx[4][2] = { { 0,1 } ,{ 0,-1 }, { 1,0 },{ -1,0 } };

typedef pair<int, int> p;
queue <p> q;

void map_cpy(int dest[][N],int src[][N]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			dest[i][j] = src[i][j];
		}
}

bool allzero(int i,int j, int d) {
	int y = i - yx[d][0], x = j - yx[d][1];
	if (chk) return 0;
	while (map[y][x] == 0) {
		if (chk) return 1;
		y -= yx[d][0], x -= yx[d][1];
		if (map[y][x] != 0) return 1;
	}
}
int go(int i, int j, int d) {

	int y = i + yx[d][0], x = j + yx[d][1];
	int cy = i - yx[d][0], cx = j - yx[d][1];
	if (chk) return 2;

	if (map[y][x] / 2 > 0 && map[y][x] == map[i][j]) {
		map[i][j] = 2 * map[y][x];
		map[y][x] = 0;
		if (allzero(i, j, d)) {

			int ny = y + yx[d][0], nx = x + yx[d][1];
			go(ny, nx, d);
			ny++, nx++;
		}
	}
	if (map[i][j]==0 && map[y][x]!=0) {
		map[i][j] = map[y][x];
		map[y][x] = 0;
		if (map[i][j]==map[cy][cx]) {
			map[cy][cx] = 2 * map[i][j];
			map[i][j] = 0;
		}
		if (allzero(i, j, d)) {
			go(cy, cx, d);
			cy--,cx--;
		}
	}


}

void dfs(int cnt, int max, int d) {
	
	c[cnt] = d;
	if (cnt == 1) {
		if(d==2)
		{
			k = 1;
		}
	}
	
	///블록단위 이동
	///d  0:좌, 1:우 2:상 3:하
	///탐색:우    좌   하   상
	if (d == 0) {
		for (int i = 0; i < n; i++) 				for (int j = 0; j < n; j++) { if (go(i, j, d) == 2)				continue; }
		map_cpy(Nmap, map);
	}

	if (d == 1) {
		for (int i = 0; i < n; i++)				for (int j = n - 1; j >= 0; j--) { if (go(i, j, d) == 2)						continue; }
		map_cpy(Nmap, map);
	}
	if (d == 2) {
		for (int i = 0; i < n; i++)				for (int j = 0; j < n; j++) { if (go(i, j, d) == 2)					continue; }
		map_cpy(Nmap, map);
	}
	if (d == 3) {
		for (int i = n - 1; i >= 0; i--)				for (int j = 0; j < n; j++) {		 if (go(i, j, d) == 2)						continue; }
		map_cpy(Nmap, map);
	}
	if (cnt > 5) {
		for (int i = 0; i < n; i++)				for (int j = 0; j < n; j++) { ans = ans > map[i][j] ? ans : map[i][j]; }

		map_cpy(map, Omap);
		map_cpy(Nmap, Omap);
		return;
	}

	for (int i = 0; i < 4; i++)
		dfs(cnt + 1, max, i);

}

int main() {
	
	freopen("1.txt", "r", stdin); setbuf(stdout, NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			Omap[i][j] = map[i][j];
			Nmap[i][j] = map[i][j];
		}

	for (i1 = 0; i1 < 4; i1++)
		dfs(1,0,i1);

	cout << ans;
}
