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


	/* ���� ����
	#include <iostream>
using namespace std;
bool broken[10]; // ��ư�� ������ ������ true, �ƴϸ� false
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
	for (int i = 0; i <= 1000000; i++) { // ���� ��ư���� �̵��ϴ� ä��
		int c = i;
		int len = possible(c); // ���̸� ���.
		if (len > 0) {
			int press = c - n; // +�� -�� �� �� ������ �ϴ��� ���
			if (press < 0) {
				press = -press; // +�� ������ ���
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
