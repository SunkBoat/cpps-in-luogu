#include<bits/stdc++.h>
using namespace std;

long long n,e,d,m,k;

int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	long long q;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld%lld",&n,&e,&d);
		m=e*d;
		k=n-m+2;
		//printf("%lld,%lld\n",n,k);
		//printf("%lld,%lld\n",k-1>n,(k/2)*(n-(k/2))<n);
		//printf("%lld,%lld %lld\n",k-1,(k/2),(k-(k/2)));
		if(k-1>n||(k/2)*(k-(k/2))<n){printf("NO\n");continue;}
		
		long long l=1,r=k/2;
		long long ans=-1;
		while(l<=r)
		{
			long long mid=(l+r+1)/2;
			long long tmp=mid*(k-mid);
			//printf("%lld-%lld %lld,%lld:%lld\n",l,r,mid,k-mid,tmp);
			if(tmp==n){ans=mid;break;}
			if(tmp>n)r=mid-1;
			if(tmp<n)l=mid+1;
		}
		if(ans==-1) printf("NO\n");
		else printf("%lld %lld\n",ans,k-ans);
	}
	
	return 0;
}
/*
1
19616506255877370 51 384637370332039
*/