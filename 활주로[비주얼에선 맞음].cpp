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
	//0 ��� 1 ���� 2 ������ 3 ������ 4 �Ұ�
	int i;
	//�ٸ��� ���������� Ȯ���� 1���� �迭
	int build[N];
	for (i = 0; i < n - 1; i++) {
		//���� ��ϰ� ���� ����� �ٸ��� ������
		//������ ���� ������� i++
		if (map[i][row] != map[i + 1][row]) {
			//�ٸ��� ��Ÿ���� �ϴ� ��� �÷��� ������
			flag = 0;

			//���̸� ���
			int diff = map[i][row] - map[i + 1][row];
			//���̰� 1���� ũ�� �� ���� �ѱ��
			if (abs(diff) > 1) break;

			//���� ��� ( i+1 )�� �������̸�
			if (diff == 1) {
				//������ �÷��� ����
				flag = 2;
				int j;
				for (j = i + 1; j <= i + l; j++) {
					//j�� n���� Ŀ�� ���� ����ų�
					//map�� ���� ��ϰ� �� ���� ����� ���̰� �ٸ��ų�
					//������ ���� ������ �������� ��ġ�Ǿ��ٸ� �ߴ��ϰ� �ѱ�
					if (j > n - 1 || map[i + 1][row] != map[j][row] || build[j] == 3) {
						break;
					}
					//���� ��Ͽ� ������ �����ٰ� ǥ��
					build[j] = 2;
				}
				//�ߴܵǸ� �Ұ� �÷��� ����
				if (j != i + 1 + l) flag = 4;
			}

			//���� ��� ( i+1 )�� �������̸�
			if (diff == -1) {
				//������ �÷��� ����
				flag = 3;
				int j;
				for (j = i; j >= i - l; j--) {
					//j�� 0���� �۾��� ���� ����ų�
					//map�� ���� ��ϰ� ���� ����� ���̰� �ٸ��ų�
					//������ ���� ������ �������� ��ġ�Ǿ��ٸ� �ߴ��ϰ� �ѱ�
					if (j < 0 || map[i][row] != map[j][row] || build[j] == 2) {
						break;
					}
					//���� �����ġ�� ������ �����ٰ� ǥ����
					build[j] = 3;
				}
				//�ߴܵǾ����� �Ұ��� ǥ��
				if (j != i - l) flag = 4;
			}

			//�Ұ��� �ϸ� �� ���� �ѱ�
			if (flag == 4)break;
		}
	}

	//�Ұ��� ǥ�ð� ������
	//�� ���� ������ ������ �� ���
	if (flag != 4 && i == n - 1) ans++;
	//�����ٷ� �Ѿ
	row++;
	//n ������ �ȳ����� ���� �� ����
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