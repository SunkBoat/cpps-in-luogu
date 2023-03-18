#include<bits/stdc++.h>
using namespace std;
long long maxn1=-1e9,maxn2=-1e9;
long long a1[100005],b1[100005];
long long a,b;
long long n,k;
long long ans;
long long qianzhui[1000005];
long long sum,sum1;
void solve()
{
	sum=-1e9;
	sum1=-1e9;
	qianzhui[0]=0;
	int h=0;
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			if(b1[j]!=0&&a1[j]==i)
			{
				qianzhui[j]=qianzhui[j-1]+1;
			}
			else if(h+1<=k)
			{
				qianzhui[j]=qianzhui[j-1]+1;
				h++;
			}
			else
			{
				sum=max(sum,qianzhui[j-1]);
				qianzhui[j]=0;
				h=0;
			}
		}
	}
	h=0;
	memset(qianzhui,0,sizeof(qianzhui));
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			if(a1[j]!=0&&b1[j]==i)
				qianzhui[j]=qianzhui[j-1]+1;
			else if(h+1<=k)
			{
				qianzhui[j]=qianzhui[j-1]+1;
				h++;
			}
			else
			{
				sum1=max(sum,qianzhui[j-1]);
				qianzhui[j]=0;
				h=0;
			}
		}
	}
	ans=max(sum,sum1);
	cout<<ans+2;
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		a1[i]=a;
		b1[i]=b;
		maxn1=max(maxn1,a);
		maxn2=max(maxn2,b);
	}
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
