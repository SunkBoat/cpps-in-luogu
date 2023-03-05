#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll mi(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
		}
		a*=a;
		b>>=1;
	}
	return ans;
}
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	ll a,b;
	scanf("%lld %lld",&a,&b);
	if(b==1)
	{
		if(a>1000000000)
		{
			cout<<-1;
		}
		else
		{
			cout<<a;
		}
		return 0;
	}
	if(b==2)
	{
		if(a>31622)
		{
			cout<<-1;
		}
		else
		{
			cout<<a*a;
		}
		return 0;
	}
	ll ans=mi(a,b);
	if(ans>1000000000
	||ans<a
	||ans%a!=0
	||ans!=mi(a,b>>1)*mi(a,b-(b>>1)))
	{
		cout<<-1;
	}
	else
	{
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
