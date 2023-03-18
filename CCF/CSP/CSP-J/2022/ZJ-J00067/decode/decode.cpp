#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long k,n,e,d,m,p,q;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld%lld%lld",&n,&e,&d);
		m=n-e*d+2;
		if(m*m-4*n<0)
		{
			printf("NO\n");
			continue;
		}
		long long t=m*m-4*n;
		long long x=sqrt(t);
		if(x*x!=t)
		{
			printf("NO\n");
			continue;
		}
		if((m+x)%2!=0)
		{
			printf("NO\n");
			continue;		
		}
		printf("%lld %lld\n",(m-x)/2,(m+x)/2);
	}
	return 0;
}
