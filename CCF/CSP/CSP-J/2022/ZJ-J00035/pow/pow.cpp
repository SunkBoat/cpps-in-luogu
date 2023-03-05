#include<bits/stdc++.h>
using namespace std;
const long long MAx__=1000000000;
long long now=1;
long long n,m;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(long long i=0;i<m;i++)
	{
		now*=n;
		if(now>MAx__)
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<now;
	return 0;
}