#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
#define N 1000

int main() {
	freopen("2064.txt", "r", stdin);
	int n=0;
	char s[16];
	int a[N][4];
	int mini[4];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d.%d.%d.%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
	}

	int diff[4] = { 0,0,0,0 };
	for (int i = 0; i < 4; i++) {
		int min = 2147468347, max = -2127468348;
		for (int j = 0; j < n - 1; j++) {
			if (min > a[j][i]) {
				min = a[j][i];
				min = mini[i];
			}
			if (max < a[j][i]) max = a[j][i];
		}
		diff[i] = max - min;
	}

	int ip[4];
	for (int i = 0; i < 4; i++) {

		if (diff[i] == 0) {
			ip[i] = a[0][i];
		}
		else {
			int dif = diff[i];
			if (dif+1 % 2 == 0) {
				//차이에 1을 더한게 2로 나누어 떨어지면 그 수의 범위(2^?)만큼 차이니까 젤큰거나 작은거에서 비교하면 되는데 어떻게 해야하지...
			}
			ip[i] += diff[i] - dif;
		}
	}
	cout << ip[0] << '.' << ip[1] << '.' << ip[2] << '.' << ip[3];
	cout << '\n';

	int netmask[4];

	for (int i = 0; i < 4; i++) {
		netmask[i] = (1 << 8) - 1;
		if (diff[i]!=0) netmask[i] -= diff[i] + 1;
	}
	cout << netmask[0]<<'.'<<netmask[1]<<'.'<<netmask[2]<<'.'<<netmask[3];
}