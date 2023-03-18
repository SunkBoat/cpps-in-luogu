#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	int k;
	long long n,e,d,m,p;
	scanf("%d",&k);
	bool Flag;
	while(k--)
	{
		Flag=true;
		scanf("%lld %lld %lld",&n,&e,&d);
		m=e*d;
		m-=2;
		p=n-m;
		long long l=1,r=p-1,b,mid;
		long long P=p/2,Q=p-P;
		if(p-1>n||P*Q<n)
		{
			printf("NO\n");
			continue;
		}
		while(l<r)
		{
			mid=(l+r)>>1;
			b=p-mid;
//			printf("// %lld %lld %lld %lld %lld\n",mid,b,mid*b,l,r);
			if(mid*b==n)
			{
				printf("%lld %lld\n",mid,b);
				Flag=false;
				break;
			}
			if(mid*b>n)
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		b=p-l;
		if(b*l==n&&Flag)
		{
			printf("%lld %lld\n",l,b);
			Flag=false;
			continue;
		}
		if(Flag)printf("NO\n");
	}
	return 0;
}