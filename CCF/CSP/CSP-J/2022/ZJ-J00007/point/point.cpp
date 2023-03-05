#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int ddx[4]={-1,-1,1,1},ddy[4]={-1,1,-1,1};
int f[3005][3005],fl[3005][3005],d[3005][3005],w[3005][3005];
int h,t,ans,q[10000005][3];
void bfs(int x,int y){
	fl[x][y]=1;
	int sum=1;
	h=1;t=1;
	q[h][1]=x;
	q[h][2]=y;
	while(h<=t){
		for(int i=0;i<4;i++){
			int xx=q[h][1]+dx[i];
			int yy=q[h][2]+dy[i];
			if(xx<1||yy<1||f[xx][yy]==0||fl[xx][yy]==1)continue;
			fl[xx][yy]=1;
			sum++;
			t++;
			q[t][1]=xx;
			q[t][2]=yy;
		}/*
		for(int i=0;i<4;i++){
			int xx=q[h][1]+ddx[i];
			int yy=q[h][2]+ddy[i];
			if(xx<1||yy<1||fl[xx][yy]==1)continue;
			for(int ii=q[h][1];ii<=xx;ii++){
				for(int j=q[h][2];j<=yy;j++){
					if(f[ii][j]!=1)w[ii][j]++;
				}
			}
		}*/
		h++;
	}
	ans=max(ans,sum);
	d[x][y]=sum;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		f[a][b]=1;
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(f[i][j]==1&&fl[i][j]==0)bfs(i,j);
		}
	}
	cout<<ans+k;
}
