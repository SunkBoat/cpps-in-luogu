#include<bits/stdc++.h>
using namespace std;
int n,k,s;
/*struct POINTS{
	int x,y;
}po[512];*/
//int ljjz[512][512];
int poi[512][512];
int dfs(int x,int y)
{
	int an=0;
	if(poi[x+1][y]==1)
	{
		an=max(an,dfs(x+1,y));
	}
	if(poi[x][y+1]==1)
	{
		an=max(an,dfs(x,y+1));
	}
	if(poi[x+1][y]==0&&k>0)
	{
		k--;
		an=max(an,dfs(x+1,y));
		k++;
	}
	if(poi[x][y+1]==0&&k>0)
	{
		k--;
		an=max(an,dfs(x,y+1));
		k++;
	}
	return an+1;
}
int main()
{
	//!!!
	
	
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	
	
	//!!!
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		//po[i].x=x;
		//po[i].y=y;
		poi[x][y]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(poi[i][j])s=max(s,dfs(i,j));
		}	
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ljjz[i][j]=1e8;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ljjz[i][j]=abs(po[i].x-po[j].x)+abs(po[i].y-po[j].y)-1;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ljjz[i][j]=min(ljjz[i][j],ljjz[i][k]+ljjz[k][j]);
			}
		}
	}*/
	printf("%d",s);
	return 0;
}
/*
CCF,if you give me 100 pts,I will give you 10^-9 yuan.
*/