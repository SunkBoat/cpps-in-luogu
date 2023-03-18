#include<iostream>
using namespace std;
long long sum=1,maxx=1000000000;
int n,m;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>n>>m;
	sum=n;
	for(int i=2;i<=m;i++)
	{
		sum*=n;
		if(sum>maxx)
		{
			cout<<-1;
			return 0;
		}
	}
	printf("%lld",sum);
	return 0;
}
