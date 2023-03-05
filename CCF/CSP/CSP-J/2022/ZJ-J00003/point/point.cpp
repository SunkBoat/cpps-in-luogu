#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool mp[10000][10000];
int gx[2]={1,0};
int gy[2]={0,1};
LL ans=0;
void dfs(int x,int y,LL l){
	for(int i=0;i<2;i++){
		int tx=x+gx[i],ty=y+gy[i];
		if(mp[tx][ty])dfs(tx,ty,l+1);
	}
	ans=l>ans?l:ans;
	return;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	LL n,k,mxx=0,mxy=0;
	scanf("%lld %lld",&n,&k);
	for(LL i=0;i<n;++i){
		LL x,y;
		scanf("%lld %lld",&x,&y);
		mxx=x>mxx?x:mxx,mxy=y>mxy?y:mxy;
		mp[x][y]=1;
	}
	if(k==0)
		for(int i=1;i<=mxx;i++)
			for(int j=1;j<=mxy;j++)dfs(i,j,0);
	else while(k--)
		for(int i=1;i<=mxx;i++)
			for(int j=1;j<=mxy;j++){
				if(mp[i][j])continue;
				mp[i][j]=1;
				dfs(i,j,0);
				mp[i][j]=0;
			}
	printf("%lld\n",ans);
	return 0;
}

