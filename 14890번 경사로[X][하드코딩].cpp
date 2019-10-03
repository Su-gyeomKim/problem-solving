#include<iostream>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_NO_SECURE_WARNINGS

#define N 101

int map[N][N];
//�������� ��Ͽ� ��
int col_diff[N][N], row_diff[N][N];
int n, l;
int ans;

int main() {
	freopen("1.txt", "r", stdin); setbuf(stdout, NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++)			cin >> map[i][j];
	
	///1. �������� �Է�
	//����(����) �������� üũ
	for (int i = 0; i < n; i++)		for (int j = 1; j < n; j++)			col_diff[i][j] = map[i][j - 1]-map[i][j];
	//����(�ణ) �������� üũ
	for (int i = 0; i < n; i++)		for (int j = 1; j < n; j++)			row_diff[j][i] = map[j-1][i] - map[j][i];

	///2. �������� ���� �� ���
	//����(����) �������� ���� �� ���
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) {
		if (!col_diff[i][j]) continue;
		if (j == n - 1) ans++;
	}
	//����(�ణ) �������� ���� �� ���
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) {
		if (!row_diff[j][i]) continue;
		if (j == n - 1) ans++;
	}

	///3. �������� �ִ� �� ���
	//����(����) �������� �ִ� �� ���
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) {
		
		//���̰� 0�̸� ��Ƽ���ؼ� ���� ��� Ž��
		if (!col_diff[i][j]) continue;

		//���̰� 1���� ũ�� ���� ������ �Ѿ
		if (col_diff[i][j] > 1 || col_diff[i][j] < -1) { i++,j=0;	continue; }

		//����(������+������)�� ������, L����ŭ ���̾���, ���� ���� ������ ���
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
		//���������� ���� ������ ���������� ������ ��� X�ϰ� �Ѿ
		if (col_diff[i][j] == 1) {
			int k = 0;
			for (k = j + 1; k < j + l; k++) { if (col_diff[i][k] != 0)	break; }
			if (k == j + l) {
				for (; k < n; k++) { if (col_diff[i][k] == -1) break; }
				if (k != n) { i++, j = 0; continue; }
			}
		}
		//���������� ���� ������ ���������� ������ �����
		if (col_diff[i][j] == -1) {
			int k = 0;
			for (k = j + 1; k < j + l; k++) { if (col_diff[i][k] != 0)	break; }
			if (k == j + l) {
				for (; k < n; k++) {
					if (col_diff[i][k] == 1) {
						//����������� ������ �˻�
						int k2 = 0;
						for (k2 = k + 1; k < k + l; k++) { if (col_diff[i][k2] != 0)	break; }

					}
				}
				if (k != n) { i++, j = 0; continue; }
			}
		}
	
	}
	//����(�ణ) �������� �ִ� �� ���
	for (int i = 0; i < n; i++)		for (int j = 0; j < n; j++) {
		//���̰� 0�̸� ��Ƽ���ؼ� ���� ��� Ž��
		if (!row_diff[j][i]) continue;
		//���̰� 1���� ũ�� ���� ���� �Ѿ
		if (row_diff[j][i] != 1 || row_diff[j][i] != -1) { i++;	continue; }

	}
	///4. �����
	cout << ans;
}