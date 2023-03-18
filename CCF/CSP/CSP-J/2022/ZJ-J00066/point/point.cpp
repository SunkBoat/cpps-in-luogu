#include<bits/stdc++.h>
using namespace std;typedef long long ll;
struct cspJ{ll x,y;}a[505];
bool cmp(cspJ a,cspJ b){
	if(a.x==b.x)return a.y<b.y;
	else return a.x<b.x;
}
ll n,k,f[505],ans,dp[505][505],diss;
int main(){
freopen("point.in","r",stdin);freopen("point.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
	sort(a,a+n,cmp);
	if(k==0){
		for(int i=0;i<n;i++)f[i]=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++)
				if(((a[i].x==a[j].x)&&(a[i].y-a[j].y==1))||((a[i].y==a[j].y)&&(a[i].x-a[j].x==1)))f[i]=max(f[i],f[j]+1);
			ans=max(ans,f[i]);		
		}
		printf("%lld",ans);
	}
	else{
		for(int i=0;i<n;i++)
			for(int j=0;j<=k;j++)dp[i][j]=j+1;
		for(int i=1;i<n;i++)
			for(int j=0;j<i;j++)
				if(a[i].x>=a[j].x&&a[i].y>=a[j].y){
					diss=a[i].x-a[j].x+a[i].y-a[j].y;
					for(int o=diss-1;o<=k;o++)dp[i][o]=max(dp[i][o],dp[j][o-diss+1]+diss);
				}
		for(int i=0;i<n;i++)
			for(int j=0;j<=k;j++)ans=max(ans,dp[i][j]);
		printf("%lld",ans);
	}
	return 0;
}
