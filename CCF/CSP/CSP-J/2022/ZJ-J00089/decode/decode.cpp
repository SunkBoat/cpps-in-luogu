#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

LL k, n, d, e;

int main()
{
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	
	scanf("%lld", &k);
	while (k -- )
	{
		scanf("%lld%lld%lld", &n, &d, &e);
		LL cur = d * e - 2ll, tmp = abs(n - d * e) + 2ll;
		LL l = 1ll, r = tmp - 1ll;
		while (l < r)
		{
			LL mid = (l + r) >> 1ll;
			if (mid * (tmp - mid) > n) l = mid + 1ll;
			else r = mid;
		}
		if (l * (tmp - l) == n) printf("%lld %lld\n", tmp - l, l);
		else puts("NO");
	}
	
	return 0;
}

