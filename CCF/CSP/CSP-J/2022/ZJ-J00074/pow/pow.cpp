#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL a,b;

int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	if(a==1)
	{
		cout<<1<<endl;
	}else
	{
		LL res=1;
		for(int i=1;i<=b&&res<=1e9;i++)
			res*=a;
		if(res>1e9) cout<<-1<<endl;
		else cout<<res<<endl;
	}
	return 0;
}