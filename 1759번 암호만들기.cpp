#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int cmp(const void *a, const void *b) { return *(char *)a - *(char*)b; }

#define N 16
char a[N];
char b[N];
bool visit[N];
int l, c;

void dfs(int y, int cnt) {

	b[cnt] = a[y];
	
	if (cnt == l) {

		if (b[l - 1] != 0) {
			int even=0, odd=0;

			for (int k = 0; k < l; k++) {
				if (b[k] == 'a' || b[k] == 'e' || b[k] == 'i' || b[k] == 'o' || b[k] == 'u')	even++;
				else odd++;
			}
			if (even >= 1 && odd >= 2) 
				for (int k = 0; k < l; k++) 
					cout << b[k];
			else 
				return;

			cout << endl;
		}
		cnt --;
		b[cnt] = 0;
		return;
	}
	
	for (int i = y; i < c; i++) {
		dfs(i+1, cnt + 1);
	}
}

int main() {
	freopen("1.txt", "r", stdin); setbuf(stdout, NULL);
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}
	
	qsort(a, c, sizeof(char), cmp);

	for (int i = 0; i < c ; i++) {
		dfs(i, 0);
	}

}