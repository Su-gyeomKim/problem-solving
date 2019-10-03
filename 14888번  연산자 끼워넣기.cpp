#include<iostream>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)

#define N 11
#define big(a,b) (a<b? b:a)
#define small(a,b) (a<b? a:b)

int n;
int a[N], op[4];

int M = -2147468347, m = 2147468347;
int cnt;
int chk;


void calc(int plus, int minus, int multi, int div,int count, int tmp) {

	if (count == n) {
		M = big(M, tmp), m = small(m, tmp);
		return;
	}

	if (plus)	calc(plus - 1, minus, multi, div, count + 1, tmp + a[count]);
	if (minus) calc(plus, minus - 1, multi, div, count + 1, tmp - a[count]);
	if (multi) calc(plus, minus, multi - 1, div, count + 1, tmp*a[count]);
	if (div) calc(plus, minus, multi, div - 1, count + 1, tmp / a[count]);
}
int main() {
	freopen("1.txt", "r", stdin);	setbuf(stdout, NULL);

	cin >> n;
	for (int i = 0; i < n; i++)		cin >> a[i];
	for (int i = 0; i < 4; i++) {		cin >> op[i];				cnt += op[i];	}

	calc(op[0], op[1], op[2], op[3], 1, a[0]);
	

	cout << M << '\n' << m;
}