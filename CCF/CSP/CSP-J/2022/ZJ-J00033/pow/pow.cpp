#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool flag = false;

ll fastpow(ll a, ll b)
{
	if(flag) return 0;
	if(b == 1) return a;
	ll t = fastpow(a, b >> 1);
	if(t > 1000000000) flag = true;
	if(flag) return 0;
	if(b & 1) return t * t * a;
	else 	  return t * t;
}

ll myA, myB, myC;

signed main()
{
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	cin >> myA >> myB;
	myC = fastpow(myA, myB);
	if(flag || myC > 1000000000) puts("-1");
	else cout << myC << endl;
	return 0;
}
