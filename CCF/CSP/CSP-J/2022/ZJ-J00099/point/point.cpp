#include<bits/stdc++.h>
using namespace std;
struct pt{
	int x,y;
}a[505];
int vis[505][505]={0},s;
int dfs(int x,int y){
	vis[x][y]=0;
	if(vis[x][y+1]){
		s++;
		dfs(x,y+1);
	}
	if(vis[x][y-1]){
		s++;
		dfs(x,y-1);
	}
	if(vis[x-1][y]){
		s++;
		dfs(x-1,y);
	}
	if(vis[x+1][y]){
		s++;
		dfs(x+1,y);
	}
	return s;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	int n,k,ans=0,i;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		vis[a[i].x][a[i].y]=1;
	}
	for(i=1;i<=n;i++){
		if(vis[a[i].x][a[i].y]==0) continue;
		s=1;
		ans=max(ans,dfs(a[i].x,a[i].y));
	}
	cout<<ans;
	return 0;
}