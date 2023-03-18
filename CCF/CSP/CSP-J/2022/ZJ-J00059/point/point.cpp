#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,x,y,z,ans;
struct node
{
	int x,y;
}a[1000];
bool cmp(node x,node y)
{
	if (x.x==y.x) return x.y<y.y; else return x.x<y.x;
}
void dfs(int now,int add,int sum)
{
	int i,last;
	if ((n-now+sum+add)<=ans) return;
	ans=max(ans,sum+add);
	if (a[now+1].x==a[now].x&&(a[now+1].y-a[now].y-1)<=add) dfs(now+1,add-a[now+1].y+a[now].y+1,sum+a[now+1].y-a[now].y);
	last=a[now].x;
	for (i=now+1;i<=n;i++)
	  if (a[i].x>last&&a[i].y>=a[now].y&&(a[i].x-a[now].x+a[i].y-a[now].y-1)<=add)
	    {
	    	last=a[i].x;
	    	dfs(i,add-a[i].x+a[now].x-a[i].y+a[now].y+1,sum+a[i].x-a[now].x+a[i].y-a[now].y);
		}
	return;
}
int main()
{
    freopen("point.in","r",stdin);
    freopen("point.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
      scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
	ans=0;
	for (i=1;i<=n;i++)
	  dfs(i,m,1);
	printf("%d",ans);
	return 0;
} 
