#include <bits/stdc++.h>
using namespace std;
#define int long long
int k, n, e, d, c;


int calc(int _p, int _q) {
	return (_p - 1) * (_q - 1) + 1;
}

void g(int v) {
	int f = n + 2 - c;
	for (int i = 0; i <= (int)(f / 2); i++) {
		if (calc(i, f - i) == c) {
			printf("%lld %lld\n", i, f - i);
			return;
		}
	}
	printf("NO\n");
}

signed main() {
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	scanf("%lld", &k);
	for (int i = 0; i < k; i++) {
		scanf("%lld%lld%lld", &n, &e, &d);
		c = e * d;
		g(n);
	}
	return 0;
}
