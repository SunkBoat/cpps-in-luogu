#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

using namespace std;

int main() {
	int n;
	ll s = 1ll;
	scanf ("%lld", &n);
	for (int i = 1; i <= n; ++i) {
		s *= i;
		while (s % 10ll == 0ll) s /= 10ll;
		s %= 1000000ll;
	}
	printf ("%lld\n", s % 10ll);
}
