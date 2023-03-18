#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
struct node
{
	int x,y;
}q[1010];
bool cmp(node x,node y)
{
	return x.x<y.x||(x.x==y.x&&x.y<y.y);
}
int f[1010];
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;ans=1+k;
	for (int i=1;i<=n;i++)
		scanf("%d%d",&q[i].x,&q[i].y);
	sort(q+1,q+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		f[i]=1;
		for (int j=i+1;j<=n;j++)
		if (q[j].y>=q[i].y)
		{
		   for (int jj=i;jj<j;jj++)
		   	if (q[jj].y<=q[j].y) f[j]=max(f[j],f[jj]+1);
		   	if (f[j]+k>=q[j].x-q[i].x+q[j].y-q[i].y+1) ans=max(ans,f[j]+k);
		}
	}
	cout<<ans<<endl;
	return 0;
}
