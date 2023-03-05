#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define mkp make_pair
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define R(i,l,r) for(int i=(l);i>=(r);i--)
int n,val,dp[505][105];
struct node{int x,y;}a[505];
bool cmp(node u,node v){return u.x==v.x?u.y<v.y:u.x<v.x;}
int dis(int u,int v){return abs(a[u].x-a[v].x)+abs(a[u].y-a[v].y)-1;}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&val);
	F(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	F(i,1,n) F(j,0,val) dp[i][j]=j+1;
	int res=0;
	F(v,1,n){
		F(i,0,val){
			F(u,1,v-1){
				int t=dis(u,v);
				if(a[u].x<=a[v].x&&a[u].y<=a[v].y){
					if(i>=t)dp[v][i]=max(dp[v][i],dp[u][i-t]+1+t);
				}
			}
		}
	}
	F(i,1,n) F(j,0,val) res=max(res,dp[i][j]);
	printf("%d\n",res);
	return 0;
}