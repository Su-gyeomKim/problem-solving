//2017.09.18 

#include <iostream>

using namespace std;

#define MAX_E 15
#define MAX_S 28
#define MAX_M 19

int main() {
	int E, S, M;
	int e = 0, s = 0, m = 0;
	int a = 0;

	cin >> E >> S >> M;

	while (true) {
		a++;

		e = (e + 1) % MAX_E; if (e == 0) e = 15; //e�� 1�� ���ذ��� 15+1�� �ٽ� 1��, 15�� ��� �������� 0�̴ϱ� 15��� ����
		s = (s + 1) % MAX_S; if (s == 0) s = 28; //���� ����
		m = (m + 1) % MAX_M; if (m == 0) m = 19; //

		if (e == E && s == S && m == M) { 
			cout << a << endl;
			return 0;
		}
	}
}