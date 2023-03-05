#include<bits/stdc++.h>
using namespace std;

int n,k;

struct point{
	int x,y;
}ng[510];

int dp[510];
int mx[510];

int _max(int x,int y)
{
	return x>y?x:y;
}

void foo1()
{
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		for(int ls=0;ls<i;ls++)
		{
			if((ng[ls].x-ng[i].x==-1 || ng[ls].y-ng[i].y==-1) && ng[ls].x<=ng[i].x && ng[ls].y<=ng[i].y)
				dp[i]=_max(dp[i-1]+1,dp[i]);
		}
	}
	cout<<dp[n];
}

int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&ng[i].x,&ng[i].y);
	}
	if(k==0)foo1();
}
