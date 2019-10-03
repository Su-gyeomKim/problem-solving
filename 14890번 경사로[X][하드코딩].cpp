#include<iostream>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_NO_SECURE_WARNINGS

#define N 101

int map[N][N];
//높이차이 기록용 맵
int col_diff[N][N], row_diff[N][N];
int n, l;
int ans;

int main() {
	freopen("1.txt", "r", stdin); setbuf(stdout, NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++)			cin >> map[i][j];
	
	///1. 높이차이 입력
	//가로(열간) 높이차이 체크
	for (int i = 0; i < n; i++)		for (int j = 1; j < n; j++)			col_diff[i][j] = map[i][j - 1]-map[i][j];
	//세로(행간) 높이차이 체크
	for (int i = 0; i < n; i++)		for (int j = 1; j < n; j++)			row_diff[j][i] = map[j-1][i] - map[j][i];

	///2. 높이차이 없는 길 계산
	//가로(열간) 높이차이 없는 길 계산
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) {
		if (!col_diff[i][j]) continue;
		if (j == n - 1) ans++;
	}
	//세로(행간) 높이차이 없는 길 계산
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) {
		if (!row_diff[j][i]) continue;
		if (j == n - 1) ans++;
	}

	///3. 높이차이 있는 길 계산
	//가로(열간) 높이차이 있는 길 계산
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) {
		
		//차이가 0이면 컨티뉴해서 다음 블록 탐색
		if (!col_diff[i][j]) continue;

		//차이가 1보다 크면 다음 행으로 넘어감
		if (col_diff[i][j] > 1 || col_diff[i][j] < -1) { i++,j=0;	continue; }

		//경사로(내리막+오르막)가 나오고, L개만큼 차이없고, 이후 차이 없으면 계산
		if (col_diff[i][j] == 1 || col_diff[i][j] == -1) {
			int k = 0;
			for (k = j + 1; k < j + l; k++) { if (col_diff[i][k] != 0)	break; }
			if (k == j + l) {
				for (; k < n; k++) { if (col_diff[i][k]) break;  }
				if (k != n) { i++; continue; }
				else {
					ans++,i++,j=0;
					continue;
				}
			}
		}
		//내리막길이 먼저 나오고 오르막길이 나오면 계산 X하고 넘어감
		if (col_diff[i][j] == 1) {
			int k = 0;
			for (k = j + 1; k < j + l; k++) { if (col_diff[i][k] != 0)	break; }
			if (k == j + l) {
				for (; k < n; k++) { if (col_diff[i][k] == -1) break; }
				if (k != n) { i++, j = 0; continue; }
			}
		}
		//오르막실이 먼저 나오고 내리막길이 나오면 계산함
		if (col_diff[i][j] == -1) {
			int k = 0;
			for (k = j + 1; k < j + l; k++) { if (col_diff[i][k] != 0)	break; }
			if (k == j + l) {
				for (; k < n; k++) {
					if (col_diff[i][k] == 1) {
						//내리막길부터 끝까지 검사
						int k2 = 0;
						for (k2 = k + 1; k < k + l; k++) { if (col_diff[i][k2] != 0)	break; }

					}
				}
				if (k != n) { i++, j = 0; continue; }
			}
		}
	
	}
	//세로(행간) 높이차이 있는 길 계산
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) {
		//차이가 0이면 컨티뉴해서 다음 블록 탐색
		if (!row_diff[j][i]) continue;
		//차이가 1보다 크면 다음 열로 넘어감
		if (row_diff[j][i] != 1 || row_diff[j][i] != -1) { i++;	continue; }

	}
	///4. 답출력
	cout << ans;
}