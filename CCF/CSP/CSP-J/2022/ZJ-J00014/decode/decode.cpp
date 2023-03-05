// CSP-J 2022 T2 decode
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll aaa, bbb, sm, pd, del;
ll my_sqrt (ll x) {
	ll l = 1ll, r = 1000000000ll, ans = 0ll;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (mid * mid > x) {
			r = mid - 1;
		} else {
			ans = mid;
			l = mid + 1;
		}
	}
	if (ans * ans != x) {
		return -1ll;
	} else {
		return ans;
	}
}
int main () {
	freopen ("decode.in", "r", stdin);
	freopen ("decode.out", "w", stdout);
	scanf ("%d", &T);
	while (T--) {
		scanf ("%lld%lld%lld", &pd, &aaa, &bbb);
		sm = pd - aaa * bbb + 2;
		del = sm * sm - 4 * pd;
		if (del < 0) {
			puts ("NO");
			continue;
		}
		del = my_sqrt (del);
		if (del == -1ll) {
			puts ("NO");
			continue;
		}
		if (del >= sm) {
			puts ("NO");
			continue;
		}
		if ((del + sm) & 1 == 1) {
			puts ("NO");
			continue;
		}
		printf ("%lld %lld\n", (sm - del) >> 1, (sm + del) >> 1);
	}
	return 0;
}
