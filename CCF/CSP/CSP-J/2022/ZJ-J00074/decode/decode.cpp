#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL q,n,d,e;

int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld%lld",&n,&d,&e);
		LL sum=n-e*d+2;
		LL l=1,r=sum/2;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(mid*(sum-mid)>n)
				r=mid-1;
			else l=mid+1;
		}
		if(r*(sum-r)==n)
			printf("%lld %lld\n",r,(sum-r));
		else printf("NO\n");
	}
	return 0;
}