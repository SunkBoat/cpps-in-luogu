#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

LL a, b, cur = 1;

int main()
{
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	
	scanf("%lld%lld", &a, &b);
	
	if (a == 1ll)
	{
		puts("1");
		return 0;
	}
	for (LL i = 1; i <= b; i ++ )
	{
		cur *= a;
		if (cur > 1000000000ll)
		{
			puts("-1");
			return 0;
		}
	}
	
	printf("%lld\n", cur);
	
	return 0;
}

