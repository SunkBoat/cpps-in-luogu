#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,k;
int f1[501],f2[501],g[501],dis1[501],dis2[501],ans,dis[501][501];
struct point{
	int x,y;
};
point a[1001],b[1001];
bool cmp(point p,point q)
{
	if(p.x!=q.x) return p.x<q.x;
	return p.y<q.y;
}
bool cmp2(point p,point q){
	if(p.y!=q.y) return p.y<q.y;
	return p.x<q.x;
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		b[i].x=a[i].x,b[i].y=a[i].y;
		f[i]=k;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp2);
	memset(dis,127,sizeof(dis));
	memset(dis1,127,sizeof(dis1));
	memset(dis2,127,sizeof(dis2));
	for(int i=1;i<n;i++)
	{
		dis1[i]=a[i+1].x-a[i].x+a[i+1].y-a[i].y-1;
		if(dis1[i]>k){
			dis1[i]=-1;
			dis1[i+1]=a[i+2].x-a[i].x+a[i+2].y-a[i].y-1;
		}
	}
	for(int i=1;i<n;i++)
	{
		dis2[i]=b[i+1].x-b[i].x+b[i+1].y-b[i].y-1;
		if(dis2[i]>k){
			dis2[i]=-1;
			dis2[i+1]=b[i+2].x-b[i].x+b[i+2].y-b[i].y-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		f1[i]=f1[i-1]+1-dis1[i];
		f2[i]=f2[i-1]+1-dis2[i];
	}
	cout<<max(f1[n],f2[n]);
	return 0;
}