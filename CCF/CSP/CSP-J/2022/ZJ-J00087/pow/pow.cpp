#include<bits/stdc++.h>
using namespace std;
long long ans=1,a,b;
bool f;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	if(b>=33&&a!=1)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(a==1)
	{
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<=b;i++)
	{
		ans*=a;
		if(ans>1000000000)
			f=1;
	}
	if(f==1) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
