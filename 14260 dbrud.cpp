#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int map[11][11] = { 0 };
int xdir[5] = { 0,0,0,1,-1 };
int ydir[5] = { 0,1,-1,0,0 };
int min = 2014029716;

int flower[11][11] = { 0 };
int visit[11][11] = { 0 };

void initFlower() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			flower[i][j] = 0;
		}
	}
}

int blossom() { //필수있으면 1, 못피면 0
	int nx, ny;
	initFlower();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] = 1) {
				for (int d = 0; d < 4; d++) {
					nx = i + xdir[d];
					ny = j + ydir[d];
					if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
						flower[nx][ny]++;
						if (flower[nx][ny] > 1) {
							return 0;
						}
					}
				}
			}
		}
	}
	return 1;
}

int getPrice() {
	int price = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (flower[i][j] == 1)
				price += map[i][j];
		}
	}
	return price;
}

void choice(int cnt, int x, int y) {
	int temp;

	if (visit[x][y])
		if (cnt > 3) {
			if (blossom()) {
				temp = getPrice();
				if (min > temp) {
					min = temp;
				}
			}
			return;
		}

	if (x >= N - 1 || y >= N - 1) {
		return;
	}

	for (int i = x; i < N - 1; i++) {
		for (int j = y + 1; j < N - 1; j++) {
			//if (visit[i][j] != 0)
			visit[i][j] = 1;
			choice(cnt + 1, i, j);
			visit[i][j] = 0;
		}
	}
}

int main(void) {
	int nx, ny;
	freopen("14260.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			visit[i][j] = 1;
			choice(1, i, j);
			visit[i][j] = 0;
		}
	}

	printf("%d\n", min);

	scanf("%d", &N);
	return 0;
}

//시작점에서 k개 올라가기
/*for (int k = 1; k <= 2; k++) {
nx = i - k;
ny = j;
for (int d = 0; d < 4; d++) {
for (int z = 0; z < k; z++) {
nx = nx + xddir[0];
ny = ny + yddir[0];
if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
visit[nx][ny] = 1;
}
}
}
}*/