#include <bits/stdc++.h>
using namespace std;

long long K;
long long n,d,e;
long long m,t;
long long f(long long x,long long y)
{
	long long left=1,right=x/2,mid;
	while(left<right)
	{
		mid=(left+right)/2;
		if(mid*(x-mid)==y)
		{
			left=mid;
			break;
		}
		else if(mid*(x-mid)>y)
		{
			right=mid-1;
		}
		else if(mid*(x-mid)<y)
		{
			left=mid+1;
		}
	}
	if(left*(x-left)!=y)
	{
		return (-1);
	}
	return left;
}
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&K);
	while(K--)
	{
		scanf("%lld %lld %lld",&n,&d,&e);
		m=n-e*d+2;
		t=f(m,n);
		if(t==(-1))
		{
			printf("NO\n");
		}
		else
		{
			printf("%lld %lld\n",min(t,m-t),max(t,m-t));
		}
	}
	return 0;
}
