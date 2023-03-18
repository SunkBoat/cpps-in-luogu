#include<bits/stdc++.h>
using namespace std;
struct sth{int x,y,tm,f;
sth(int xx,int yy,int tt){x=xx;y=yy;tm=tt;}};
bool a[501][501],vis[501][501];
int dp[4]={1,-1,-1,1};
vector<sth> v;
queue<sth> q;
int n,k,ans;
void bfs(int x,int y,int tm,int l){
	cerr<<x<<" "<<y<<endl;
	vis[x][y]=1;
	q.pop();
	if(tm<0){ans=max(ans,l);
	return;}
	for(int i=0;i<4;i++){
		if(!vis[x+(i>1?0:dp[i])][y+(i<2?0:dp[i])]&&x>0&&x<500&&y>0&&y<500)
		q.push(sth(x+(i>1?0:dp[i]),y+(i<2?0:dp[i]),tm-(a[x+(i>1?0:dp[i])][y+(i<2?0:dp[i])]?0:1)));
	}
	l++;
	while(!q.empty()){
		bfs(q.front().x,q.front().y,q.front().tm,l);
	}
}
int main(void){
//	freopen("point.in","r",stdin);
//	freopen("point.out","w",stdout);
	q.push(sth(1,1,1));
	for(int i=1;i<=n;i++){int tmp1,tmp2;
		scanf("%d %d",&tmp1,&tmp2);
		a[tmp1][tmp2]=1;
		v.push_back(sth(tmp1,tmp2,k));
	}
	p
	for(int i=1;i<v.size();i++){
		bfs(v[i].x,v[i].y,v[i].tm,1);
	}rintf("%d",rand()%500+1);
	return 0%d  ans
}