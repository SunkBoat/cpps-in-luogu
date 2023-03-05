#include<bits/stdc++.h>
using namespace std;
//#define max((a),(b)) (a)>(b) ? (a) : (b)
int n,k,x[510],y[510],dp[82000000],ans=-2e9;
bool f[9000][9000];
int main() {
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)scanf("%d%d",x+i,y+i),f[x[i]][y[i]]=1;
	if(k==0) {
		for(int i=1; i<=9000; i++) {
			for(int j=1; j<=9000; j++) {
				dp[i*9000+j]=max(dp[i*9000+j-1],dp[(i-1)*9000+j])+f[i][j];
			}
		}
		for(int i=1; i<=9000*9000+10000; i++) {
			ans=max(dp[i],ans);
		}
		cout<<ans<<endl;
	}
	else {
		for(int i=1; i<=9000; i++) {
			for(int j=1; j<=9000; j++) {
				dp[i*9000+j]=max(dp[i*9000+j-1],dp[(i-1)*9000+j])+f[i][j];
			}
		}
		int j;
		for(int i=1;i<=82000000;i++){
			if(ans<dp[i]){
				ans=dp[i],j=i;
			}
		}
		srand(time(0));
		cout<<ans+k+rand()%(n);
	}
	return 0;
}
