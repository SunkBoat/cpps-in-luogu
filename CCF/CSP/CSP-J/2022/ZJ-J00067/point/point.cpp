#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=555;
int n,k,dp[maxn][maxn],ans;
struct node{
	long long x,y;
}a[maxn];
bool cmp(node a,node b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
int calc(int i,int j)
{
	return a[j].x-a[i].x+a[j].y-a[i].y-1;
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		dp[i][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j].y<a[i].y)
				continue;
			for(int p=j+1;p<=n;p++)
			{
				if(a[p].y>=a[j].y&&calc(i,p)-dp[i][j]+1<=k)
					dp[i][p]=max(dp[i][p],dp[i][j]+1);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans=max(ans,dp[i][j]);
	printf("%d",ans+k);
	return 0;
}
