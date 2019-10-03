#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS



using namespace std;

#define N 101

int map[N][N], inv_map[N][N];
int n, l;
int ans;


void chkR(int row, int map[N][N]) {
	int flag = 1;
	//0 대기 1 가능 2 내리막 3 오르막 4 불가
	int i;
	//다리가 지어졌는지 확인할 1차원 배열
	int build[N];
	for (i = 0; i < n - 1; i++) {
		//지금 블록과 다음 블록이 다르면 계산시작
		//같으면 다음 블록으로 i++
		if (map[i][row] != map[i + 1][row]) {
			//다른게 나타나면 일단 대기 플래그 세워줌
			flag = 0;

			//차이를 계산
			int diff = map[i][row] - map[i + 1][row];
			//차이가 1보다 크면 이 줄은 넘긴다
			if (abs(diff) > 1) break;

			//다음 블록 ( i+1 )이 내리막이면
			if (diff == 1) {
				//내리막 플래그 세움
				flag = 2;
				int j;
				for (j = i + 1; j <= i + l; j++) {
					//j가 n보다 커져 맵을 벗어나거나
					//map의 다음 블록과 다 다음 블록이 높이가 다르거나
					//내리막 짓기 이전에 오르막이 설치되었다면 중단하고 넘김
					if (j > n - 1 || map[i + 1][row] != map[j][row] || build[j] == 3) {
						break;
					}
					//현재 블록에 내리막 지었다고 표시
					build[j] = 2;
				}
				//중단되면 불가 플래그 세움
				if (j != i + 1 + l) flag = 4;
			}

			//다음 블록 ( i+1 )이 오르막이면
			if (diff == -1) {
				//오르막 플래그 세움
				flag = 3;
				int j;
				for (j = i; j >= i - l; j--) {
					//j가 0보다 작아져 맵을 벗어나거나
					//map의 이전 블록과 지금 블록이 높이가 다르거나
					//오르막 짓기 이전에 내리막이 설치되었다면 중단하고 넘김
					if (j < 0 || map[i][row] != map[j][row] || build[j] == 2) {
						break;
					}
					//현재 블록위치에 오르막 지었다고 표시함
					build[j] = 3;
				}
				//중단되었으면 불가능 표시
				if (j != i - l) flag = 4;
			}

			//불가능 하면 이 줄은 넘김
			if (flag == 4)break;
		}
	}

	//불가능 표시가 없으며
	//이 줄을 무사히 끝까지 온 경우
	if (flag != 4 && i == n - 1) ans++;
	//다음줄로 넘어감
	row++;
	//n 범위를 안넘으면 다음 줄 실행
	if (row < n) chkR(row, map);
}

int main() {
	freopen("14890.txt", "r", stdin); setbuf(stdout, NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> l;

		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			ans = 0;
			map[i][j] = 0;
			inv_map[i][j] = 0;
		}

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			inv_map[j][i] = map[i][j];
		}
		chkR(0, map);
		chkR(0, inv_map);

		cout << '#' << t << ' ' << ans << '\n';
	}
}