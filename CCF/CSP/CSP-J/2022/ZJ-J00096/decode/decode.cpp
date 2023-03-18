#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
signed main() {
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&T);
	while(T--) {
		int n,d,e;
		scanf("%lld %lld %lld",&n,&d,&e);
		double sum=n-e*d+2;
		double b=sqrt(double(sum*sum-4*n));
		double p=(sum+b)/2;
		double q=(sum-b)/2;
		if(p==floor(p)&&q==floor(q)) printf("%lld %lld\n",(int)q,(int)p);
		else printf("NO\n");
	}
	return 0;
}