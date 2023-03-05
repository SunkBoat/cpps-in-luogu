#include<bits/stdc++.h>
using namespace std;
long long k,f[1005],n,e,d;
long long ans,L=0,R,mid,p,q,flag=0;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	for(int t=1; t<=k; t++)
	{
		memset(f,0,sizeof f);
		int cnt=0;
		flag=0;
		scanf("%lld%lld%lld",&n,&e,&d);
		ans=e*d;
		for(int i=1; i<=sqrt(n)+1; i++)
			if(n%i==0)f[++cnt]=i;
		L=0,R=cnt+1;
		while(L+1<R)
		{
			mid=(L+R)/2;
			p=f[mid];
			q=n/f[mid];
			if((p-1)*(q-1)+1>ans)
				R=mid;
			if((p-1)*(q-1)+1==ans)
			{
				printf("%lld %lld\n",p,q);
				flag=1;
				break;
			}
			if((p-1)*(q-1)+1<ans)
				L=mid;
		}
		if(!flag)
			printf("NO\n");
	}
	return 0;
}