#include <iostream>
#include <queue>

using namespace std;

#pragma warning(disable:4996)

#define N 51-48
#define cmp(a,b) (a<b?a:b)


int R, C;
bool visit[N][N];
int temp_x, temp_y;
char map[N][N];
int x_move[] = { 0,0,-1,1 };
int y_move[] = { -1,1,0,0 };
int cnt[N][N];
int x, y;
queue<pair<int, int> > q;
void bfs() {
	visit[temp_x][temp_y] = true;
	q.push({ temp_x,temp_y });
	while (!q.empty()) {
		int rx = q.front().first;
		int ry = q.front().second;
		q.pop();

		// caution 3
		if (map[rx][ry] == '*') {
			for (int i = 0; i<4; i++) {
				int nx = rx + x_move[i];
				int ny = ry + y_move[i];
				if (nx >=0 && nx < R && ny >=0 && ny < C) {
					if (map[nx][ny] != 'D'&&map[nx][ny] != 'X'&&map[nx][ny] != 'S' && !visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });

						// caution 4
						map[nx][ny] = '*';
					}
				}
			}
		}
		else if (map[rx][ry] == '.' || map[rx][ry] == 'S') {
			for (int i = 0; i<4; i++) {
				int nx = rx + x_move[i];
				int ny = ry + y_move[i];
				if (nx >=0 && nx < R && ny >=0 && ny < C) {
					if (map[nx][ny] != 'X'&&map[nx][ny] != '*' && !visit[nx][ny]) {
						q.push({ nx,ny });
						visit[nx][ny] = true;
						cnt[nx][ny] = cnt[rx][ry] + 1;
						if (map[nx][ny] == 'D') {
							x = nx; y = ny;
							return;
						}
					}
				}
			}
		}

	}
}
int main() {

	freopen("1.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) {
			
			cin >> map[i][j];
			
			if (map[i][j] == 'S') 
				temp_x = i, temp_y = j;

			else if (map[i][j] == '*') 
				q.push({ i,j });
		}
	
	bfs();
	if (!cnt[x][y])   printf("KAKTUS\n");
	else    printf("%d\n", cnt[x][y]);
	return 0;
}

/*
char map[N][N];
int cnt[N][N];
int water[N][N];
bool visit[N][N];
int R, C;
int chk, ans=N;

int yx[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

typedef pair<int, int> p;
queue<p> q;

void bfs() {
	while (!q.empty()){
		p pos = q.front();
		int y = pos.first;
		int x = pos.second;
		q.pop();
		visit[y][x] = 1;

		if (map[y][x] == 'S') {
			for (int i = 0; i < 4; i++) {
				int ny = y + yx[i][0], nx = x+yx[i][1];
				if (map[ny][nx] == 'D') {
					chk=1;
					ans = cnt[y][x] + 1;
					return;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + yx[i][0], nx = x + yx[i][1];
			if (ny < 0 || ny>R - 1 || nx<0 || nx>C - 1 || visit[ny][nx] || map[ny][nx] == 'X' || map[y][x] =='.') continue;
			
			if (map[ny][nx] == '.') {
				
				visit[ny][nx] = 1;

				q.push(p(ny, nx));	

				if (map[y][x] == '*') {
					water[ny][nx]=water[y][x]+1;
					map[ny][nx] = '*';
				}
				
				if (map[y][x] == 'S') {
					char temp = map[ny][nx];
					map[ny][nx] = map[y][x];
					map[y][x] = temp;		
					//cnt++;
					cnt[ny][nx] = cnt[y][x] + 1;
				}
			}
		}
	}
}


int main() {

	freopen("1.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'S' || map[i][j] == '*')	q.push(p(i, j));
			if (map[i][j] == 'S') cnt[i][j] = 0;
			if (map[i][j] == '*') water[i][j] = 0;
		}

	bfs();

	if (!chk)
		cout << "KAKTUS" << '\n';
	else
		cout << ans << '\n';
}
*/