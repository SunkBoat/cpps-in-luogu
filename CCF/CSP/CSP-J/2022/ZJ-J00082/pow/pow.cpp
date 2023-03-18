#include <bits/stdc++.h>
using namespace std;

int a,b;

int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%d %d",&a,&b);
	long long ans;
	if(a==1)
	{
		printf("1\n");
		return 0;
	}
	else
	{
		ans=1;
		while(b&&ans<=1000000000)
		{
			ans*=a;
			b--;
		}
		if(ans>1000000000)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n",ans);
		}
	}
	return 0;
}