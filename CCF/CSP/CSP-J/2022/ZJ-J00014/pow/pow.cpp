// CSP-J 2022 T1 pow
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, s = 1;
int b;
int main () {
	freopen ("pow.in", "r", stdin);
	freopen ("pow.out", "w", stdout);
	scanf ("%lld%lld", &a, &b);
	if (a == 1) {
		puts ("1");
		exit (0);
	}
	for (int i = 1; i <= b; i++) {
		s *= a;
		if (s > 1000000000ll) {
			puts ("-1");
			exit (0);
		}
	}
	printf ("%lld\n", s);
	return 0;
}
