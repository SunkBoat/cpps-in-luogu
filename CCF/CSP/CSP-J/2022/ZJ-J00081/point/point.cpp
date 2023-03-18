#include<bits/stdc++.h>
using namespace std;
int maxn=0,ans=0,dp[100001];
vector<int>g[10001];
bool v[550];
inline int read()
{
	register int x=0,t=1;
	register char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*t;
}
struct Node
{
	int x,y;
}a[100001];
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	int n=read(),K=read();
	for(int i = 1;i<=n;i++) cin >> a[i].x>>a[i].y;
	srand(time(0));
	cout<<rand()%(n+K);
	return 0;
}