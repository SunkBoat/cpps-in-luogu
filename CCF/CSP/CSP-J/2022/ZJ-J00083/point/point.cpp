#include<bits/stdc++.h>
using namespace std;
const int maxn = 501;
long long f[maxn],ff[maxn][maxn];
int n,k;
struct P{
	long long x,y;
}a[maxn];
bool cmp(P a, P b){
	return a.x<b.x || (a.x == b.x&& a.y<b.y);
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	if(k == 0){
		for(int i = 1;i<=n;i++)	f[i] = 1;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i == j)continue;
				if((a[i].x-a[j].x == 1&&a[i].y==a[j].y) || (a[i].y-a[j].y == 1 && a[i].x==a[j].x)){
					f[i] = max(f[i],f[j]+1);
				}
			}
		}
		long long ans = 0;
		for(int i = 1;i<=n;i++) ans = max(ans,f[i]);
		printf("%lld",ans);
	}
	else{
		for(int i = 1;i<=n;i++){
			for(int j = 0;j<=k;j++){
				ff[i][j] = j+1;
			}
		}	
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				for(int p = 0;p<=k;p++){
					if(i == j) continue;
					if(a[i].x<a[j].x||a[i].y<a[j].y)	continue;
					int dis = a[i].x-a[j].x+a[i].y-a[j].y;
					if((a[i].x-a[j].x == 1&&a[i].y==a[j].y) || (a[i].y-a[j].y == 1 && a[i].x==a[j].x)){
						ff[i][p] = max(ff[i][p],ff[j][p]+1);
					}
					else if(dis-1<=k-p){
						ff[i][p+dis-1] = max(ff[i][p+dis],ff[j][p]+dis);
					}
				}
			}
		}
		long long ans = 0;
		for(int i = 1;i<=n;i++) {
			for(int j = 0;j<=k;j++){
				ans = max(ans,ff[i][j]);
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
				
