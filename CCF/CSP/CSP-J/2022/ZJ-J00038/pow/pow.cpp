#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	if(pow(a,b)<=1e9)
		cout<<int(pow(a,b));
	else
		cout<<-1;
	return 0;
}