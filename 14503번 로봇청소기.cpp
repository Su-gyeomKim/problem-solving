#include<iostream>

using namespace std;

#define N 50
#define L(d) d=(d+3)%4
#define wall(a) map[a.r][a.c] == 1

int map[N][N];
int n, m, r, c, d;  //d 0:ºÏ, 1:µ¿, 2:³², 3:ÁÂ
					///dir: 0 1 2 3 = > left = (dir + 3) % 4
					///left : 3 0 1 2
int ans;

struct a {
	int r;	int c;	int d;
}A;

int yx[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };

void chkL(a a);


void dfs(a a) {
	if (map[a.r][a.c] == 0) {
		map[a.r][a.c] = 2;
		chkL(a);
	}
}

int chk4(a a) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int y = a.r + yx[i][0], x = a.c + yx[i][1];
		if (map[y][x] != 0)			cnt++;
	}
	if (cnt == 4) {

		// a.d:back to => 0:r+1 , 1:c-1, 2:r-1 , 3: c+1
		//a.d = odd number
		if (a.d % 2) {
			if (a.d / 2) {//a.d = 3
				a.c++;
				if (wall(a)) 	return 2;
				chkL(a);
			}
			else {//a.d = 1
				a.c--;
				if (wall(a)) 	return 2;
				chkL(a);
			}
		}
		else {
			if (a.d / 2) { //a.d = 2
				a.r--;
				if (wall(a)) 	return 2;
				chkL(a);
			}
			else { //a.d = 0
				a.r++;
				if (wall(a)) 	return 2;
				chkL(a);
			}
		}
	}
}


void chkL(a a) {
	//ÀÖÀ¸¸é Æ®·ç
	/// dir 0: 0~r , 1: c~m , 2:r~n , 3: 0~c

	if (chk4(a) == 2)
		return;

	switch (a.d) {
	case(0):
		if (map[a.r][a.c - 1] == 0) { L(a.d);		a.c--;		dfs(a); }
		else {
			L(a.d);				chkL(a);
		}
		break;

	case(1):
		if (map[a.r - 1][a.c] == 0) { L(a.d);		a.r--;		dfs(a); }
		else {
			L(a.d);				chkL(a);
		}
		break;

	case(2):
		if (map[a.r][a.c + 1] == 0) { L(a.d);		a.c++;		dfs(a); }
		else {
			L(a.d);	chkL(a);
		}
		break;

	case(3):
		if (map[a.r + 1][a.c] == 0) { L(a.d);		a.r++;		dfs(a); }
		else {
			L(a.d);		chkL(a);
		}
		break;
	}
	return;
}



int main() {

	//freopen("1.txt", "r", stdin); setbuf(stdout, NULL);

	cin >> n >> m;
	cin >> A.r >> A.c >> A.d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	dfs(A);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2)
				ans++;
		}

	cout << ans;

}
