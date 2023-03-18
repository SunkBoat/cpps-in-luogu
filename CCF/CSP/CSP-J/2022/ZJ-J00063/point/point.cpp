#include<bits/stdc++.h>
using namespace std;
int n,k,ans=-1e9,id;
int f[5005];
struct date
{
	int x,y;
}a[1000005];
bool cmp(date x,date y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y,f[i]=1;
	sort(a+1,a+n+1,cmp);
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(a[i].y==a[j].y+1 && a[j].x==a[i].x || a[i].x==a[j].x+1 && a[i].y==a[j].y && i!=j)
		f[i]=max(f[i],f[j]+1);
		ans=max(ans,f[i]);
	}
	cout<<ans+k;
	return 0;
}
