#include<cstdio>
#pragma warning(disable:4996)

#define R 2
#define L 6

int w1[8], w2[8], w3[8], w4[8];

void rotate(int w[8], int dir) {
	if (dir == -1) {
		int temp = w[0];
		for (int i = 0; i<7; i ++ ) w[i] = w[i + 1];
		w[7] = temp;
	}
	else if(dir==1){
		int temp[8];
		for (int i = 0; i<8; i++) temp[i] = w[i];
		for (int i = 1; i<8; i ++ ) w[i] = temp[i - 1];
		w[0] = temp[7];
	}
	return;
}

void wrotate(int w, int dir) {
	switch (w) {
	case(1):
		if (w1[R] == w2[L]) {
			rotate(w1, dir); break;
		}
		else if (w1[R] != w2[L]) {
			if (w2[R] == w3[L]) { rotate(w1, dir), rotate(w2, -dir); break;
			}
			else if (w2[R] != w3[L]) {
				if (w3[R] == w4[L]) { rotate(w1, dir), rotate(w2, -dir), rotate(w3, dir); break;
				}
				else if (w3[R] != w4[L]) { rotate(w1, dir), rotate(w2, -dir), rotate(w3, dir), rotate(w4, -dir); break;
				}
			}
		}
	case(2):
		if (w2[L] == w1[R] && w2[R] == w3[L]) {
			rotate(w2, dir); break;
		}

		else if (w2[L] != w1[R] && w2[R] == w3[L]){ rotate(w1, -dir), rotate(w2, dir); break;
		}

		else if (w2[L] == w1[R] && w2[R] != w3[L])  {
			if (w3[R] == w4[L]) {rotate(w2, dir), rotate(w3, -dir); break;
			}
			else if (w3[R] != w4[L]) { rotate(w2, dir), rotate(w3, -dir), rotate(w4, dir); break;
			}
		}
		
		else if (w2[L] != w1[R] && w2[R] != w3[L]) {
			if (w3[R] == w4[L]) {rotate(w1, -dir), rotate(w2, dir), rotate(w3, -dir); break;
			}
			else if (w3[R] != w4[L]) { rotate(w1, -dir), rotate(w2, dir), rotate(w3, -dir), rotate(w4, dir); break;
			}
		}
	case(3):
		if (w3[L] == w2[R] && w3[R] == w4[L]) {rotate(w3, dir); break;
		}

		else if (w3[L] == w2[R] && w3[R] != w4[L]) 	{rotate(w3, dir), rotate(w4, -dir); break;
		}

		else if (w3[L] != w2[R] && w3[R] == w4[L]) {
			if (w2[L] == w1[R]) { rotate(w2, -dir), rotate(w3, dir); break;
			}
			else if (w2[L] != w1[R]) {rotate(w1, dir), rotate(w2, -dir), rotate(w3, dir); break;
			}
		}

		else if (w3[L] != w2[R] && w3[R] != w4[L]) {
			if (w1[R] == w2[L]) {rotate(w2, -dir), rotate(w3, dir), rotate(w4, -dir); break;
			}
			else if (w1[R] != w2[L]) { rotate(w1, dir), rotate(w2, -dir), rotate(w3, dir), rotate(w4, -dir); break;
			}
		}

	case(4):
		if (w4[L] == w3[R]) {rotate(w4, dir); break;
		}

		else if (w4[L] != w3[R]) {
			if (w3[L] == w2[R]) {rotate(w3, -dir), rotate(w4, dir); break;
			}
			else if (w3[L] != w2[R]) {
				if (w2[L] == w1[R]) {rotate(w2, dir), rotate(w3, -dir), rotate(w4, dir); break;
				}
				else if (w1[R] != w2[L]) { rotate(w1, -dir), rotate(w2, dir), rotate(w3, -dir), rotate(w4, dir); break;
				}
			}
		}
	}
}
int main() {
	int t;
	char s[9];
	scanf("%s", &s);			for (int i = 0; i < 8; i++) w1[i] = s[i];
	scanf("%s", &s);			for (int i = 0; i < 8; i++) w2[i] = s[i];
	scanf("%s", &s);			for (int i = 0; i < 8; i++) w3[i] = s[i];
	scanf("%s", &s);			for (int i = 0; i < 8; i++) w4[i] = s[i];
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int w, d;
		scanf("%d %d", &w, &d);
		wrotate(w, d);
	}
	int ans = 0;
	if (w1[0] == 49) ans += 1;
	if (w2[0] == 49) ans += 2;
	if (w3[0] == 49) ans += 4;
	if (w4[0] == 49) ans += 8;

	printf("%d\n", ans);
}
