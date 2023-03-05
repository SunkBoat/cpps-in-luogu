#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,k;
int x[N],y[N];
bool vis[N];
int path[N];
int res=0,r=0;
void dfs(int u){
	bool flag=false;
	for(int i=1;i<=k;i++){
		if(!vis[i]){
			if((x[i]-x[i-1]==1&&y[i]==y[i-1])||(y[i]-y[i-1]==1&&x[i]==x[i-1])){
				flag=true;
				vis[i]=1;
				dfs(u+1);
				vis[i]=0;
			}
		}
	}
	if(!flag){
		r++;
		res=max(res,u);
		return ;
	}
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	dfs(0);
	cout<<res+n-r<<endl;
	return 0;
}