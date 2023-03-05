#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b;
unsigned long long ans=1;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	while(b>1)
	{
		if(b%2==0)
		{
			a*=a;		
			b/=2;
		}
		else
		{
			ans*=a;
			b--;
		}
		if(ans*a>1000000000)
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<ans*a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
