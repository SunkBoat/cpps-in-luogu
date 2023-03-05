#include <bits/stdc++.h>
using namespace std;

long long A, B;

int main() {
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	cin >> A >> B;
	if (A == 1) cout << 1 << endl;
	else {
		long long res = 1;
		for (long long i = 1; i <= B; i++) {
			res *= A;
			if (res > 1000000000ll) {
				puts("-1");
				return 0;
			}
		}
		cout << res << endl;
	}
	return 0;
}
