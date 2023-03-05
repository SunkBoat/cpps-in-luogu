#include<bits/stdc++.h>
using namespace std;
int n,k,dp[505],tu[105][105];
struct point{int x,y;}p[505];
bool cmp(point x,point y){
	return x.x==y.x?x.y<y.y:x.x<y.x;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++) dp[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1,x=p[i].x,y=p[i].y;j<i;j++){
			if(x-p[j].x==1&&y-p[j].y==0)
				dp[i]=max(dp[i],dp[j]+1);
			if(x-p[j].x==0&&y-p[j].y==1)
				dp[i]=max(dp[i],dp[j]+1);
		}
		if(dp[i]>dp[0]) dp[0]=dp[i];
	}
	printf("%d",dp[0]+k);
	return 0;
}