#include<bits/stdc++.h>
using namespace std;
long long n,k,vis[510][510],len[510],maxn=1;
bool bis[510];
struct f
{
	long long x,y,s;
}a[510];
void bfs(long long k)
{
	long long head,tail;
	head=tail=1;
	f team[510];
	team[1].x=a[k].x;
	team[1].y=a[k].y;
	team[1].s=1;
	bis[1]=true;
	while(head<=tail)
	{
		for(int i=1;i<=len[head];i++)
		{
			if(bis[vis[head][i]]==false)
			{
				bis[vis[head][i]]=true;
				tail++;
				team[tail].x=a[vis[head][i]].x;
				team[tail].y=a[vis[head][i]].y;
				team[tail].s=a[vis[head][i]].s;
				maxn=max(maxn,team[tail].s);
			}
		}
		bis[head]=false;
		head++;
	}
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(a[i].x==a[j].x&&a[j].y-a[i].y==1||a[i].y==a[j].y&&a[j].x-a[i].x==1)
			{
				vis[i][++len[i]]=j;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(bis,false,sizeof(bis));
		bfs(i);
	}
	cout<<maxn;
	return 0;
}
