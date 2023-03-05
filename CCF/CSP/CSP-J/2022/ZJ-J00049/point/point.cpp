#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
int n,k,far[505][505],dp[505][205];
node point[505];
bool cmp(node a,node b){
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&point[i].x,&point[i].y);
	sort(point+1,point+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			far[i][j]=abs(point[i].x-point[j].x)+abs(point[i].y-point[j].y)-1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dp[i][j]=j+1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			for(int p=i+1;p<=n;p++)
				if(far[i][p]+j>k||point[p].y<point[i].y)continue;
					else dp[p][far[i][p]+j]=max(dp[i][j]+far[i][p]+1,dp[p][far[i][p]+j]);
	int ans=-1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			ans=max(ans,dp[i][j]+k-j);
	printf("%d",ans);
	return 0;
}