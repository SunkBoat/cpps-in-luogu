#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	unsigned long long x=a,ans=1;
	while(b)
	{
		if(b%2==1)
		{
			ans*=x;
			if(ans>1000000000)
			{
				printf("-1");
				return 0;
			}
		}
		x*=x;
		b>>=1;
		if(b&&x>1000000000)
		{
			printf("-1");
			return 0;
		}
	}
	printf("%lld",ans);
	return 0;
}
