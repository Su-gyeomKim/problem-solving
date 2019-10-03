#include <iostream>

using namespace std;

int main() {
	int n,ans=0;
	cin >> n;
		if (n && n % 5 == 0) {
			ans = n / 5;
		}
		else {
			int  time;
				ans = n / 5;
				time = ans;
			n -= 5*ans;
			while (time-- && n%3) {
				n += 5;
				ans--;
			}
			if (n && n % 3 == 0) {
				ans += n / 3;
			}
			else {
				ans = -1;
			}
		}
		cout << ans;
}