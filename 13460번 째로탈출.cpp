#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

#define MAX	 10
#define MIN	 3

struct pos{
	int		x;
	int		y;
	char	color;
}p;

int		n;
int		m;

char	map[MAX][MAX];
pos		R, B, O;
queue <pos> q;
int		yx[4][2] = { {0,-1}, {-1.0}, {0,1}, {1,0} };//  ¡ç¡è¡æ¡é


void bfs() {
	pos ball=q.front();
	q.pop();

	int y = ball.y, x = ball.x;

	for (int i = 0; i < 4; i++) {
		y += yx[i][0], x += yx[i][1];
		
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			
			if (map[i][j] == 'R') {
				R.x = i, R.y = j, R.color = 'R';
				q.push(R);
			}

			else if (map[i][j] == 'B') {
				B.x = i, B.y = j, B.color = 'B';
				q.push(B);
			}

			else if (map[i][j] == 'O')
				O.x = i, O.y = j;
		}

	bfs();
}