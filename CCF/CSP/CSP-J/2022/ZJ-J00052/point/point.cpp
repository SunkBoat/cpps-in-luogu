#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
	int x,y,sheng,cnt;
};
queue <node> q;
int n,k,maxx;
int x[503],y[503];
int f[503][503];
node a[503];
bool bol[10001][10001];
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		bol[x[i]][y[i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		q.push((node){x[i],y[i],k,1});
		while(!q.empty())
		{
			node st=q.front();
			q.pop();
			if(st.sheng<f[st.x][st.y]) continue;
			f[st.x][st.y]=st.sheng;
			maxx=max(maxx,st.cnt);
			if(bol[st.x+1][st.y]) q.push((node){st.x+1,st.y,st.sheng,st.cnt+1});
			else if(st.sheng>0) q.push((node){st.x+1,st.y,st.sheng-1,st.cnt+1});
			if(bol[st.x][st.y+1]) q.push((node){st.x,st.y+1,st.sheng,st.cnt+1});
			else if(st.sheng>0) q.push((node){st.x,st.y+1,st.sheng-1,st.cnt+1});
		}
	}
	cout<<maxx;
	return 0;
}
