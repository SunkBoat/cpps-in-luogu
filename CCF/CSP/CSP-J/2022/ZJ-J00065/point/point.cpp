#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x,y;
}a[510];
int ms=1;
bool cmp1(node f,node b)
{
	if(f.x!=b.x)
	return f.x<b.x;
	return f.y<b.y;
}
bool cmp2(node f,node b)
{
	if(f.y!=b.y)
	return f.y<b.y;
	return f.x<b.x;
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp1);
	int mx=-1;
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		int p=i;
		while(a[p+1].x==a[p].x)
		{
			p++;
		}
		int f=0;
		for(int j=i;j<=p;j++)
		{
			if(a[j].y==a[p+1].y)
			{
				cnt++;
				f=1;
				break;
			}
		}
		if(!f)
		{
			mx=max(mx,cnt);
			cnt=1;
		}
		else
		i=p;
	}
	ms+=max(mx,cnt);
	sort(a+1,a+n+1,cmp2);
	mx=-1;
	cnt=1;
	for(int i=1;i<n;i++)
	{
		int p=i;
		while(a[p+1].y==a[p].y)
		{
			p++;
		}
		int f=0;
		for(int j=i;j<=p;j++)
		{
			if(a[j].x==a[p+1].x)
			{
				cnt++;
				f=1;
				break;
			}
		}
		if(!f)
		{
			mx=max(mx,cnt);
			cnt=1;
		}
		else
		i=p;
	}
	ms+=max(mx,cnt);
	cout<<ms+k;
	return 0;
}
