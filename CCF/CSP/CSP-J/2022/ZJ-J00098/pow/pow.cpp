#include<bits/stdc++.h>
using namespace std;
int s,a,b;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	s=pow(a,b);
	if(s<0) cout<<-1;
	else if(s>1000000000) cout<<-1;
	else cout<<s;
	return 0;
}
