#include<bits/stdc++.h>
using namespace std;
int k;
long long n,d,e,he,cha,p,q;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%d",&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%lld%lld%lld",&n,&d,&e);
		he=n+2ll-e*d;
		cha=sqrt(he*he-4ll*n);
		p=(he-cha)/2ll;
		q=(he+cha)/2ll;
		if (p*q==n&&(p-1ll)*(q-1ll)+1ll==d*e) printf("%lld %lld\n",p,q);
		else printf("NO\n");
	}
	return 0;
}
