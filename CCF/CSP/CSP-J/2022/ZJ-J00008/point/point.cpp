#include<bits/stdc++.h>
using namespace std;
struct A{
	int x,y;
}a[1000005];
int n,m,f[505][105],s,k,t,l,d[505][505];
int cmp(A u,A v){
	return u.x<v.x||(u.x==v.x&&u.y<v.y);
}
int dfs(int u,int v){
	if(f[u][v]>=0)return f[u][v];
	int b=v;
	for (int i=u+1;i<=n;i++)
		if(d[u][i]>0&&d[u][i]<=v+1)b=max(b,d[u][i]+dfs(i,v-d[u][i]+1));
	return f[u][v]=b;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&k);s=k;
	for (int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	memset(f,-1,sizeof(f));
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if(a[j].x>=a[i].x&&a[j].y>=a[i].y)d[i][j]=a[j].x+a[j].y-a[i].x-a[i].y;
	for (int i=1;i<=n;i++){
		s=max(s,1+dfs(i,k));
	}
	printf("%d\n",s);
}
