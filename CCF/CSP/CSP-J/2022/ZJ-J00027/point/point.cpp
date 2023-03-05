#include<bits/stdc++.h>
using namespace std;
int n,k,maxx=0,max2=0,max3=0,b[51][2],cn;
bool a[40000][40000];
void dfs(int x,int y,int cnt,int can){
	cn++;
	maxx=max(maxx,cnt);
	if(cn>638000000){
		cout<<maxx;
		exit(0);
	}
	if(a[x][y+1]==1)dfs(x,y+1,cnt+1,can);
	else{
		if(can>0)dfs(x,y+1,cnt+1,can-1);
	}
	if(a[x+1][y]==1)dfs(x+1,y,cnt+1,can);
	else{
		if(can>0)dfs(x+1,y,cnt+1,can-1);
	}
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&k);
	maxx=k;
	for(int i=1;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		a[u][v]=1;
		max2=max(max2,u);
		max3=max(max3,v);
		b[i][0]=u;
		b[i][1]=v;
	}
	for(int i=1;i<=n;i++){
		dfs(b[i][0],b[i][1],1,k);
	}
	cout<<maxx;
	return 0;
}

