#include<bits/stdc++.h>
using namespace std;
long long a,b;
unsigned long long ans;
const long long N=1e9;
bool p=1;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	ans=1;
	if(a==1) cout<<1;
	else
	{
		for(int i=1;i<=b;i++)
		{
			ans=ans*a;
			if(ans>N)
			{
				cout<<-1;	
				p=0;
				break;
			} 
		}
		if(p) cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
