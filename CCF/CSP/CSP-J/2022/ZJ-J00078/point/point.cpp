#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}a[505];
int n,k,mx;
int f[505][105];
bool cmp(node x,node y)
{
	if(x.x!=y.x)
	{
		return x.x<y.x;
	}
	return x.y<y.y;
}
int main ()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			f[i][j]=j+1;
			mx=max(mx,f[i][j]);
		}
		for(int j=1;j<i;j++)
		{
			if((a[i].x>=a[j].x)&&(a[i].y>=a[j].y))
			{
				int t=a[i].x-a[j].x+a[i].y-a[j].y-1;
				for(int l=k;l>=t;l--)
				{
					f[i][l]=max(f[i][l],f[j][l-t]+t+1);
					mx=max(mx,f[i][l]);
				}
			}
		}
	}
	printf("%d",mx);
}
