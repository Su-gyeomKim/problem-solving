// 2017.09.19
/*
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10
#define MIN 2

int dp[MAX][MAX];

int isVist(int *a) {
	return 0;
}

int Fac(int n) {
	if (n == 1) return 1;
	else return n*Fac(n - 1);
}


int main() {
	int N, i, j, sum = 0, result = 100;
	//int W[MAX][MAX];
	int route[MAX];

	cin >> N;
	///N = 4;

	for (i = 0; i < N; i++)		for (int j = 0; j < N; j++) 			cin >> W[i][j];

	//int W[MAX][MAX] = { {0,10,15,20},{5,0,9,10},{6,13,0,12},{8,8,9,0} };
	
	for (i = 0; i < N; i++) route[i] = i;

	//for (i = 0; i < N; i++)		for (int j = 0; j < N; j++) 			dp[i][j] = -1;
	// N+1번 방문해야함(돌아오기때문에)
	/*for (int k = 0; k < Fac(N); k++)
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				if (d[i][j] != 0 && d[i][j] == -1) {
					d[i][j] = 1;
					sum += W[i][j];
				}
			}
	
	
	while (next_permutation(route, route + N)) {
		bool O = true;
		for (i = 0; i < N-1; i++) {
			if (W[route[i]][route[i + 1]] != 0)
				sum += W[route[i]][route[i + 1]];
			else O = false;
		}
		if (O && W[route[N-1]][route[0]] != 0) {
			sum += W[route[N - 1]][route[0]];
			if (result > sum) result = sum;
		}
	}
	
	cout << result;
	
	return 0;
}
*/