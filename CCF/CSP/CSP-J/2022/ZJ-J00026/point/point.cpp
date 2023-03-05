#include<bits/stdc++.h>
using namespace std;
int n,k;
int x,y;
map<pair<int,int>,int>m;
map<pair<int,int>,int>er;
struct note{
	int xx;
	int yy;
};
note a[505];
int vis(int a,int b){
	return er[pair<int,int>(a,b)];
}
int maxx;
void dfs(int x,int y,int stp){
	int q,w;
	q=x+1;
	w=y;
	pair<int,int>u(q,w);
	if(m[u]==1){
		if(vis(q,w)==0){
			dfs(q,w,stp+1);
			er[pair<int,int>(x,y)]=vis(q,w)+1;
		}else{
			er[pair<int,int>(x,y)]=vis(q,w)+1;
		}
	}
	q=x;
	w=y+1;
	pair<int,int>uu(q,w);
	if(m[uu]==1){
		if(vis(q,w)==0){
			dfs(q,w,stp+1);
			er[pair<int,int>(x,y)]=vis(q,w)+1;
		}else{
			er[pair<int,int>(x,y)]=vis(q,w)+1;
		}
	}
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		pair<int,int>r(x,y);
		m[r]=1;
		a[i].xx=x;
		a[i].yy=y;
	}
	for(int i=1;i<=n;i++){
		if(vis(a[i].xx,a[i].yy)==0){
			dfs(a[i].xx,a[i].yy,1);
			maxx=max(maxx,vis(a[i].xx,a[i].yy));
		}else{
			maxx=max(maxx,vis(a[i].xx,a[i].yy));
		}
	}
	cout<<maxx+1;
	return 0;
}