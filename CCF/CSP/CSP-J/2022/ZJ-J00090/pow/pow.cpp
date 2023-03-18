#include <bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	if (a==1) 
	{
		cout<<1;
		return 0;
	}
	long long ans=a;
	for (int i=2;i<=b;i++)
	{
		ans*=a;
		if (ans>1000000000)
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
}
