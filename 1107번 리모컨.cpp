//2017.09.18
/*
#include <iostream>

using namespace std;

#define MAX_N 500000
#define MAX_M 10
#define MAX_DIGIT 6

bool broken[MAX_M];

int CheckButton(int chnnel);
int CheckButton(int chnnel) {
	while(chnnel>0){
		if (broken[chnnel % 10]) return 0;
		;
	}

	int main() {
		int n, m;

		int now = 100;
		int count = 0;

		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			int k;
			cin >> k;
			broken[k] = true;
		}
	}


	*/


	/* 백준 정답
	#include <iostream>
using namespace std;
bool broken[10]; // 버튼이 망가져 있으면 true, 아니면 false
int possible(int c) {
	if (c == 0) {
		if (broken[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (c > 0) {
		if (broken[c % 10]) {
			return 0;
		}
		len += 1;
		c /= 10;
	}
	return len;
}
int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	int ans = n - 100; // n >= 100
	if (ans < 0) {
		ans = -ans; // n < 100
	}
	for (int i = 0; i <= 1000000; i++) { // 숫자 버튼으로 이동하는 채널
		int c = i;
		int len = possible(c); // 길이를 잰다.
		if (len > 0) {
			int press = c - n; // +나 -를 몇 번 눌러야 하는지 계산
			if (press < 0) {
				press = -press; // +를 누르는 경우
			}
			if (ans > len + press) {
				ans = len + press;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
	}
	*/

#pragma warning (disable:4996)
