#include<cstdio>
#include<iostream>
using namespace std;

bool mp[1005][1005];
int k,n,ans,cnt,maxa,maxb;

int dfs(int x,int y,int w,int dis){
    if(w>k) return dis-1;
    if(x>maxa||y>maxb) return dis+k-w;
    int mx=0;
    if(mp[x+1][y]) mx=max(dfs(x+1,y,w,dis+1),mx);
    if(!mp[x+1][y]) mx=max(dfs(x+1,y,w+1,dis+1),mx);
    if(mp[x][y+1]) mx=max(dfs(x,y+1,w,dis+1),mx);
    if(!mp[x][y+1]) mx=max(dfs(x,y+1,w+1,dis+1),mx);
    return mx;
}
struct node{
    int x,y;
}nd[505];

int main(){
    freopen("point.in","r",stdin);
    freopen("point.out","w",stdout);
    cin>>n>>k;
    int mina=1e9,minb=1e9;
    for(int i=1; i<=n; i++){
        int a,b;
        cin>>a>>b;
        mina=min(mina,a);
        minb=min(minb,b);
        maxa=max(maxa,a);
        maxb=max(maxb,b);
        nd[++cnt].x=a;
        nd[cnt].y=b;
    }
    for(int i=1; i<=n; i++){
        nd[i].x-=mina;
        nd[i].y-=minb;
        mp[nd[i].x][nd[i].y]=1;
    }
    maxa-=mina;
    maxb-=minb;
    for(int i=n; i>=1; i--)
        ans=max(ans,dfs(nd[i].x,nd[i].y,0,1));
    cout<<ans;
    return 0;
}


