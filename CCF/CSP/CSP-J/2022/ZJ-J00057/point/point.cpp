#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
int dp[1005][1005];
vector<int> han[1005];
vector<int> lin[1005];
map<int,int> h;
map<int,int> l;
struct nod{
	int x,y;
}a[100005];
int ans=0;
void fid(int x)
{
	int sum=1;
	int j=-100;
	for(auto i : han[x])
	{
		if(i-j==1)
		{
			sum++;
			ans=max(sum,ans);
		}
		else sum=1;
		j=i;
	}
}
void tid(int x)
{
	int sum=1;
	int j=-100;
	for(auto i:lin[x])
	{
		if(i-j==1)
		{
			sum++;
			ans=max(sum,ans);
		}
		else sum=1;
		j=i;
	}
}
int cmp1(nod a,nod b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		han[a[i].x].push_back(a[i].y);
		lin[a[i].y].push_back(a[i].x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!h[a[i].x])
		{
			fid(a[i].x);
			h[a[i].x]=1;
		}
		if(!l[a[i].y])
		{
			tid(a[i].y);
			l[a[i].y]=1;
		}
	}
	cout<<ans;
}
