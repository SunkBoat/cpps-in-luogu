#include<bits/stdc++.h>
using namespace std;
int n,k,ans,f[510][110];
bool u[10010];
struct sss{
	int x,y;
}a[10010];
bool cmp(sss a,sss b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		f[i][0]=1;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j].x>=a[i].x&&a[j].y>=a[i].y){
				int t=a[j].x+a[j].y-a[i].x-a[i].y-1;
				for(int x=t;x<=k;x++){
					f[j][x]=max(f[j][x],max(f[j][x-1],f[i][x-t]+1));
				}
			}
		}
	}
	for(int i=0;i<=k;i++){
		for(int j=i;j<=k;j++){
			for(int kk=1;kk<=n;kk++){
				ans=max(ans,f[kk][j]+j-i);
			}
		}
	}
	cout<<ans;
}
