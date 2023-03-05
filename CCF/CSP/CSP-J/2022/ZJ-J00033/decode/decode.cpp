#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K, N, E, D;

ll fastread()
{
	ll sym = 1, res = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') sym = -sym;
		ch = getchar();
	}
	
	while(ch >= '0' && ch <= '9')
	{
		res = (res << 1) + (res << 3) + ch - '0';
		ch = getchar();
	}
	
	return res * sym;
}

//void fastwrite(ll x)
//{
//	ll cnt = 0;
//	char str[10000];
//	while(x)
//	{
//		str[cnt ++] = (x % 10) + '0';
//		x /= 10;
//	}
//	
//	for(ll i = cnt - 1; i >= 0; -- i)
//		putchar(str[i]);
//		
//	puts("");
//}

int check(ll P)
{
	int Q = N + 2 - D * E - P;
	if(P * Q > N)  return -1;
	if(P * Q == N) return 0;
	if(P * Q < N)  return 1;
}

signed main()
{
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	K = fastread();
	while(K --)
	{
		N = fastread();
		E = fastread();
		D = fastread();
		ll l = 0, r = ((N + 2 - D * E) >> 1), ans = -1;
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			int res = check(mid);
			if(res == -1) r = mid - 1;
			if(res == 1)  l = mid + 1;
			if(res == 0)
			{
				ans = mid;
				break;
			}
		}
		
		if(ans == -1) puts("NO");
		else 		  printf("%lld %lld\n", ans, ((N + 2 - D * E) - ans));
	}
	
	return 0;
}
