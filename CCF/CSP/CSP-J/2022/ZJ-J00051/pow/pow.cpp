#include<bits/stdc++.h>
using namespace std;
long long a,b,ans;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	ans=1ll;
	while (b>0ll)
	{
		if (b%2ll==1ll) ans*=a;
		a=a*a;
		b/=2ll;
		if (b>0ll&&a>1000000000ll) 
		{
			printf("-1");
			return 0;
		}
		if (ans>1000000000ll) 
		{
			printf("-1");
			return 0;
		}
	}
	printf("%lld",ans);
	return 0;
}
