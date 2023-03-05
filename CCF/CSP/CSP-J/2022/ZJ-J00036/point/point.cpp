#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long x,y,mxy=1;
long long a[1005][1005]={0};
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&x,&y);
		mxy=max(mxy,max(x,y));
		if(x<=1000&&y<=1000)
		{
			a[x][y]=1;
		}
	}
	if(k==0&&mxy<=1000)
	{
		for(int i=1;i<=1000;i++)
		{
			for(int j=1;j<=1000;j++)
			{
				if(a[i][j]==1)
				{
					a[i][j]=max(a[i-1][j],a[i][j-1])+1;
				}
			}
		}
		long long ans=1;
		for(int i=1;i<=1000;i++)
		{
			for(int j=1;j<=1000;j++)
			{
				ans=max(ans,a[i][j]);
			}
		}
		printf("%lld\n",ans);
	}
	else if(k==0)
	{
		printf("%lld\n",1);
	}
	else
	{
		printf("%lld\n",n+k);
	}
	return 0;
}
