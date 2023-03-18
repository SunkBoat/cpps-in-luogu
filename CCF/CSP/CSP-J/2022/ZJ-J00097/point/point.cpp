#include<bits/stdc++.h>
using namespace std;
int n,k,kk,a[10005][10005],x[505],y[505],dx[2]={1,0},dy[2]={0,1},ans,mx=-2147483647;
void dfs(int x,int y,int kk){
	for(int i=0;i<2;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		int z;
		if(a[xx][yy]==0){
			if(kk>0)z=2;
			else z=0;
		}
		else z=1;
		if(z>0){
			a[xx][yy]=0;
			ans++;
			dfs(xx,yy,(z==2?kk-1:kk));
			if(z!=2)a[xx][yy]=1;
			ans--;
		}
	}
	mx=max(mx,ans);
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		a[x[i]][y[i]]=1;
	}
	for(int i=1;i<=n;i++){
		a[x[i]][y[i]]=0;
		ans=1;
		dfs(x[i],y[i],k);
		cout<<x[i]<<" "<<y[i]<<" "<<mx<<endl;
		a[x[i]][y[i]]=1;
	}
	cout<<mx;
}
