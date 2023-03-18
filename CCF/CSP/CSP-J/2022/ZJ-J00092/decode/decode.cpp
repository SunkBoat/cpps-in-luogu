#include<bits/stdc++.h>
using namespace std;
long long T,n,e,d,he,cha,chaf,p,q;
long long check(long long x)
{
	long long mid,l=0,r=1e9,ans=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (mid*mid<=x) ans=mid,l=mid+1;
		else r=mid-1;
	}
	if (ans*ans==x) return ans;
	else return -1;
}
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&e,&d);
		he=n+2-e*d;
		chaf=he*he-4*n;
		cha=check(chaf);
		if (cha==-1||(he-cha)%2==1||he==cha) printf("NO\n");
		else
		{
			p=(he-cha)/2;
			q=(he+cha)/2;
			printf("%lld %lld\n",p,q);
		}
	}
	return 0;
}
