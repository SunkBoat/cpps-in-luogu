#include<bits/stdc++.h>
using namespace std;
const int mo=1e9;
#define ll long long
ll a,b; 
ll qpow(ll x,ll t)
{
	ll res=1;
	while(t){
		if(t&1) {
			res=res*x;
			if(res>mo){
				return -1;
			}
		}
		x*=x;
		t>>=1;
	}
	return res;
}
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	printf("%lld",qpow(a,b));
}
