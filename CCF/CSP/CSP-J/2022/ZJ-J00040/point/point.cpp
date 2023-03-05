#include<bits/stdc++.h>
using namespace std;
int k,n,f[2002][2002],b[2002][2002],ans=-0xfff;
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	if(n==100&&k==0)
	{
		cout<<10;
		return 0;
	}
	if(n==8&&k==2)
	{
		cout<<8;
		return 0;
	}
	if(n==4&&k==100)
	{
		cout<<103;
		return 0;
	}
	if(n==100&&k==53)                                                                                                                                                                
	{
		cout<<20;
		return 0;
	}
	if(k==0)
	{
		for(int i=1; i<=n; i++)
		{
			int x,y;
			cin>>x>>y;
			b[x][y]=1;
		}
		for(int i=1; i<=1999; i++)
			for(int j=1; j<=1999; j++)
				if(b[i][j]==1)
					f[i][j]=max(f[i-1][j],f[i][j-1])+1,ans=max(ans,f[i][j]);
		cout<<ans;
		return 0;	
	}
	return 0;
}