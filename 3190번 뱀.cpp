#include <iostream>
#include <queue>
#pragma warning (disable:4996)
#define _CRT_SECURE_CO_WARNINGS	

using namespace std;
#define N 101

int map[N][N];
int s[N*N][2];
int pre_s[N*N][2];
int c[N][2];
int n, k, l;
int eat = 1, cmd;
//0 �� 1 �� 2 �� 3 ��
//3 1  0 2  1 3  2 0   
int yx[4][2] = { { 0,-1 },{ -1,0 },{ 0,1 },{ 1,0 } };

#define L(d,C) if(C==0) d=(d+3)%4; else d=(d+1)%4


int move(int oy, int ox, int d, int cnt) {

	for (int i = 0; i < eat; i++) pre_s[i][0] = s[i][0], pre_s[i][1] = s[i][1];

	int y = oy + yx[d][0], x = ox + yx[d][1];
	if (y < 0 || x < 0 || x >= n || y >= n) return cnt;

	s[0][0] = y, s[0][1] = x;
	if (map[y][x] == 1) { s[eat][0] = oy, s[eat][1] = ox;				eat++; }

	for (int i = 1; i <= eat; i++) s[i][0] = pre_s[i - 1][0], s[i][1] = pre_s[i - 1][1];

	for (int i = 1; i < eat; i++) {
		map[y][x] = 0;
		if (s[0][0] == s[i][0] && s[0][1] == s[i][1]) return cnt;
	}


	if (c[cmd][0] == cnt) { L(d, c[cmd][1]);	cmd++; }


	move(y, x, d, cnt + 1);
}

int main() {
	freopen("3190.txt", "r", stdin); setbuf(stdout, NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		map[y - 1][x - 1] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int X;
		char C;
		cin >> X >> C;
		c[i][0] = X;
		if (C == 'L') c[i][1] = 0;
		if (C == 'D') c[i][1] = 1;

	}

	cout << move(0, 0, 2, 1);
}

/*ó���� �¾Ҵ� �ڵ�
#include<iostream>
#include<queue>

using namespace std;

#pragma warning(disable:4996)

#define N 10

int map[N][N];
pair<int, int> snake[N], pre_snake[N];
pair<int, char> Move[N];
int n, k, l;
int eat, ans, idx = -1;

int state, pre_st;

int yx[4][2] = { { 0,1 },{ -1,0 },{ 1,0 },{ 0,-1 } };
// 0:�� / 1:�� / 2:�� / 3:��

void mov() {

for (int i = 0; i <= eat; i++)		pre_snake[i] = snake[i];

//�Ӹ��� ������
snake[0].first = snake[0].first + yx[state][0], snake[0].second = snake[0].second + yx[state][1];

//�浹�˻�
for (int i = 1; i <= eat; i++)		if (snake[0] == snake[i])			return;

//������ �Ӹ��� ���󰡰�
if (eat > 0) 		for (int i = 1; i <= eat; i++) 			snake[i] = pre_snake[i - 1];


//�ʿ� ����� ������ ������ ���簡
if (map[snake[0].first][snake[0].second]) {
map[snake[0].first][snake[0].second] = 0;
eat++;
if (eat > 0)
snake[eat].first = snake[eat - 1].first - yx[state][0], snake[eat].second = snake[eat - 1].second - yx[state][1];
}
}

void dfs(int ans) {

/// �������� ����
//������ ����//
if (snake[0].first < 0 || snake[0].first >= n || snake[0].second < 0 || snake[0].second >= n) {
	cout << ans << '\n';
	return;
}

//�浹//
if (eat > 0)
for (int i = 1; i <= eat; i++)
if (snake[0] == snake[i]) {
	cout << ans << '\n';
	return;
}
/// �������� ���� ����

//�ƿ� ȸ���� �ϳ��� ������
if (idx < 0) {
	mov();
	dfs(ans + 1);
}

//ȸ���� �ϳ��� ������
else if (ans < Move[idx].first || Move[idx].first < ans) {
	mov();
	dfs(ans + 1);
}

//ȸ���Ҷ�
if (ans == Move[idx].first && ans != 0) {
	if (Move[idx].second == 'L')
		switch (state) {
		case(0):	state = 1;	break;
		case(1):	state = 3;	break;
		case(2):	state = 0;	break;
		case(3):	state = 2;	break;
		}

	else if (Move[idx].second == 'D')
		switch (state) {
		case(0):	state = 2;	break;
		case(1):	state = 0;	break;
		case(2):	state = 3;	break;
		case(3):	state = 1;	break;
		}

	mov();
	idx++;
	dfs(ans + 1);
}
}

int main() {

	freopen("3190.txt", "r", stdin);	setbuf(stdout, NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int j, k;
		cin >> j >> k;
		map[j - 1][k - 1] = 1;
	}

	cin >> l;
	if (l > 0)		idx = 0;

	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		Move[i].first = x;
		Move[i].second = c;
	}

	dfs(ans);
}

*/