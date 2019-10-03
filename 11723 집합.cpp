#include <stdio.h>
#include <iostream>
#include <istream>
#include <vector>
#include <string.h>
//using namespace std;

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

int main() {
	freopen("11723.txt", "r", stdin);  setbuf(stdout, NULL);
	int m=0;
	int n = 20;
	scanf("%d",&m);
	int s = 0;
	//std::string chk;
	//vector<char, char>;
	char chk[20];
	while(m--) {
		int x=0;
		//gets_s(chk, 20);
		scanf("%s", chk);
		
		if (chk[0] == 'a') {
			if (chk[1] == 'd') {
				scanf("%d",&x);
				s |= (1 << x);
				//std::cout << '\n' << chk << ' '<< x << '\n';
			}
			if (chk[1] == 'l') {
				s = (1 << 21) - 1;
				//std::cout << '\n' << chk << ' ' << x << '\n';
			}
		}
		if (chk[0] == 'c') {
			scanf("%d",&x);
			if (s&(1 << x)) puts("1");
			else puts("0");
			//std::cout << '\n' << chk << ' ' << x << '\n';
			//std::cout << s;
		}
		if (chk[0] == 'r') {
			scanf("%d",&x);
			s &= ~(1 << x);
			//std::cout << '\n' << chk << ' ' << x << '\n';
		}
		if (chk[0] == 't') {
			scanf("%d",&x);
			s ^= (1 << x);
			//std::cout << '\n' << chk << ' ' << x << '\n';
		}
		if (chk[0] == 'e') {
			s = 0;
			//std::cout << '\n' << chk << ' ' << x << '\n';
		}
		
	}
}