#include<bits/stdc++.h>
using namespace std;
void suan(long long a,long long b)
{
	long long x=1;
	for (long long i=1;i<=b;i++)
	{
		x*=a;
		if (x>1e9)
		{
			cout<<-1<<"\n";
			return;
		}
	}
	cout<<x<<"\n";
	return;
	
}
int main()
{
	freopen("pow.in","r",stdin);freopen("pow.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	if (b>50)
	{
		if (a==1)
		{
			cout<<1<<"\n";
		}
		else
		{
			cout<<"-1\n";
		}
		return 0;
	}
	else
	{
		suan(a,b);
	}
	return 0;
}
