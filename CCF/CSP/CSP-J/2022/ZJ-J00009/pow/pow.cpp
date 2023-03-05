#include<bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	int mi=pow(a,b);
	if(mi<0||mi>pow(10,9))cout<<-1;
	else cout<<mi;
	return 0;
}