#include<bits/stdc++.h>
using namespace std;
int vis[1000][1000];
int sx[1000],sy[1000];
int maxx=0;
void dfs(int x,int y,int t)
{
	maxx=max(maxx,t);
	if (vis[x+1][y]==1)
	{
		dfs(x+1,y,t+1);
	}
	if (vis[x][y+1]==1)
	{
		dfs(x,y+1,t+1);
	}
	
}
int main()
{
	freopen("point.in","r",stdin);freopen("point.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>sx[i]>>sy[i];
		vis[sx[i]][sy[i]]=1;
	}
	for (int i=0;i<n;i++)
	{
		dfs(sx[i],sy[i],1);
	}
	cout<<maxx<<"\n";
	return 0;
}

