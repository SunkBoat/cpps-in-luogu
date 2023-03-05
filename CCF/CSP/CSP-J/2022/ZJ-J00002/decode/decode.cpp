#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	int k;
	scanf("%d",&k);
	while(k--)
	{
		long long n,e,d;
		scanf("%lld%lld%lld",&n,&e,&d);
		long long m=n-e*d+2,delta=m*m,tmp;
		delta-=n*4;
		if(delta<0)
		{
			printf("NO\n");
			continue;
		}
		tmp=sqrt(delta);
		if(tmp*tmp!=delta)
		{
			printf("NO\n");
			continue;
		}
		long long xx=m+tmp,yy=m-tmp;
		if(xx%2 || yy%2)
		{
			printf("NO\n");
			continue;
		}
		long long p=xx/2,q=yy/2;
		if(p>q)swap(p,q);
		printf("%lld %lld\n",p,q);
	}
}
