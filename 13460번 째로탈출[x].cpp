#include <iostream>
#include <queue>
#include <algorithm>

#pragma warning(disable:4996)
#define _CRT_NO_SECURE_WARNINGS

using namespace std;
#define N 12
//0аб 1╩С 2©Л 3го
int yx[4][2] = { { 0,-1 },{ -1,0 },{ 0,1 },{ 1,0 } };
char map[N][N];
int n, m;
bool print, goal;

struct pos { int y, x, color, cnt; } B, R, O;
queue<pos> q;
int R_goal = 2147468347, B_goal,R_goal_d;

void bfs() {
	while (!q.empty()) {
		pos ball = q.front();
		int y = ball.y;
		int x = ball.x;
		q.pop();

		bool red = 0;
		if (ball.color) red = 1;
		ball.cnt++;

		for (int d = 0; d < 4; d++) {
			int ny = y, nx = x;

			while (ny >= 0 && nx >= 0 && ny < n && nx < m && map[ny][nx] != '#' && map[ny][nx] != 'O') 					ny += yx[d][0], nx += yx[d][1];
			
			ny -= yx[d][0], nx -= yx[d][1];

			//if (ny == y && nx == x) continue;

			if (red) {
				if (ny==B.y && nx==B.x)		ball.y = ny - yx[d][0], ball.x = nx - yx[d][1], ball.color = red;
				else ball.y = ny, ball.x = nx, ball.color = red;
				if (ny != y || nx != x) {
					q.push(ball);
				}
				//map[y][x] = '.';
				map[ball.y][ball.x] = 'R';
				}
			
			else if(!red) {
				if (ny==R.y && nx == R.x) 	ball.y = ny - yx[d][0], ball.x = nx - yx[d][1], ball.color = red;
				else ball.y = ny, ball.x = nx, ball.color = red;
				if (ny != y || nx != x)q.push(ball);
				//map[y][x] = '.';
				map[ball.y][ball.x] = 'B';
				}
			

			if (map[ny + yx[d][0]][nx + yx[d][1]] == 'O' && !red) {
				B_goal = ball.cnt;	
				if (goal) 
					if (B_goal <= R_goal && d == R_goal_d) {
						cout << -1;
						print = 1;
						return;
					}
					else	cout << R_goal; print = 1; return;
							
			}
			if (map[ny + yx[d][0]][nx + yx[d][1]] == 'O' && red) {
				if (ball.cnt < R_goal) {
					R_goal = ball.cnt;
					R_goal_d = d;
				}
				goal = 1;
				break; 
			}
		}
		if (goal) break;
	}

	if(B_goal)
		if (R_goal<B_goal && !print) 
		{ cout << R_goal; print = 1; return; }

	if(R_goal && !B_goal) { cout << R_goal; print = 1; return; }
}

int main() {
	freopen("13460.txt", "r", stdin); setbuf(stdout, NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O') O.y = i, O.x = j;
			if (map[i][j] == 'B') { B.y = i, B.x = j, B.color = 0; q.push(B); }
			if (map[i][j] == 'R') { R.y = i, R.x = j, R.color = 1; q.push(R); }
		}

	bfs();

	if (!print) cout << -1;
}