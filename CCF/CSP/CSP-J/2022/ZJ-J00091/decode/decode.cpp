#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	int k;
	long long n,e,d,m,t;
	scanf("%d",&k);
	for(int j=1;j<=k;j++)
	{
		scanf("%lld%lld%lld",&n,&e,&d);
		m=n-e*d+2;
		t=m*m-4*n;
		if(t<0)
		{
			printf("NO\n");
			continue;
		}
		long long a=int(sqrt(t));
		if(a*a!=t || m-a<=0 || (m-a)%2==1)
		{
			printf("NO\n");
			continue;
		}
		printf("%lld %lld\n",(m-a)/2,(m+a)/2);
	}
	return 0;
}
