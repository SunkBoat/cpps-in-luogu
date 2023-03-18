#include<bits/stdc++.h>
using namespace std;
const int N=509;

struct node{
	int x,y;
}a[N];

int n,m;
int f[N][109]={0};

bool cmp(node xx,node yy)
{
	if(xx.x==yy.x)return xx.y<yy.y;
	return xx.x<yy.x;
}

int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	/*
	for(int i=1;i<=n;i++)
	{
		printf("%d,%d\n",a[i].x,a[i].y);
	}
	*/
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<=m;k++)f[i][k]=1;
		for(int j=1;j<i;j++)
		{
			if(a[j].x>a[i].x||a[j].y>a[i].y)continue;
			int tmp=(a[i].x-a[j].x)+(a[i].y-a[j].y)-1;
			//printf("%d,%d %d,%d %d\n",a[j].x,a[j].y,a[i].x,a[i].y,tmp);
			for(int k=m;k>=tmp;k--)
			{
				f[i][k]=max(f[i][k],f[j][k-tmp]+1+tmp);
				//printf("%d->%d %d:%d %d\n",j,i,k,f[i][k],tmp);
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<=m;k++)
		{
			printf("%d ",f[i][k]);
		}
		printf("\n");
	}
	*/
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<=m;k++)
		{
			mx=max(mx,f[i][k]+(m-k));
		}
	}
	printf("%d\n",mx);
	return 0;
} 