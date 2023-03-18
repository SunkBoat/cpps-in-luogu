#include<bits/stdc++.h>
using namespace std;
int a,b;
long long ans=1;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9' || ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	a=read(),b=read();
	for(int i=1;i<=b;i++)
	{
		ans*=a;
		if(ans>1e9)
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
