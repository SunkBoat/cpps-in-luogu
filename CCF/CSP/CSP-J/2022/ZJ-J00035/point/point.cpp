#include<bits/stdc++.h>
using namespace std;
int n,k;
struct g{
	int x,y;
}a[1000];
bool vis[1000];
bool cmp1(g x,g y)
{
	return x.x<y.x;
}
bool cmp2(g x,g y)
{
	return x.y<y.y;
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i].x>>a[i].y;
	int tot=1,maxn=1;
	for(int i=0;i<n-1;i++)
	{
		if(vis[i])
			continue;
		int l=i+1,r,Maxn,xb;
		while(l<n&&vis[l])
			l++;
		r=l+1;
		while(r<n&&vis[r])
			r++;
		Maxn=a[l].y;
		xb=l;
		while(r<n&&a[r].x==a[l].x)
		{
			if(Maxn<a[i].y)
			{
				if(Maxn<a[r].y)
				{
					Maxn=a[r].y;
					xb=r;	
				}	
			}	
			else
				if(a[r].y>=a[i].y&&Maxn>a[r].y)
				{
					Maxn=a[r].y;
					xb=r;
				}
			r++;
		}
		if(a[i].x+1==a[xb].x&&a[i].y<=a[xb].y)
			tot++;
		else
			tot=1;
		maxn=max(maxn,tot);
	}
	tot=1;
	sort(a,a+n,cmp2);
	memset(vis,false,sizeof(vis));
	for(int i=1;i<n;i++)
	{
		if(vis[i])
			continue;
		int l=i+1,r,Maxn,xb;
		while(l<n&&vis[l])
			l++;
		r=l+1;
		while(r<n&&vis[r])
			r++;
		Maxn=a[l].x;
		xb=l;
		while(r<n&&a[r].y==a[l].y)
		{
			if(Maxn<a[i].x)
			{
				if(Maxn<a[r].x)
				{
					Maxn=a[r].x;
					xb=r;	
				}	
			}	
			else
				if(a[r].x>=a[i].x&&Maxn>a[r].x)
				{
					Maxn=a[r].x;
					xb=r;
				}
			r++;
		}
		if(a[i].y+1==a[xb].y&&a[i].x<=a[xb].x)
			tot++;
		else
			tot=1;
		maxn=max(maxn,tot);
	}
	cout<<maxn;
	return 0;
}