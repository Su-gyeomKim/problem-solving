#include <iostream>
#pragma warning(disable:4996)
#define _CRT_NO_SUCURE_WARNINGS
using namespace std;

int a[1000];

int main() {
	freopen("4344.txt", "r", stdin);
	int c;
	cin >> c;
	
	while (c--) {
		float n,sum=0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		float avg = sum / n;
		float upper = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > avg) upper++;
		}
		
		float x = upper / n *100;
		
		cout.setf(ios::fixed);
		cout.precision(3);
		cout << x << '%'<<'\n';
	}
}