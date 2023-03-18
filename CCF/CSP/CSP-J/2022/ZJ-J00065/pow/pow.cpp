#include<bits/stdc++.h>
using namespace std;

int p=(int)1e9;

int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==1)
	{
		cout<<"1";
		return 0;
	}
	long long s=1;
	for(int i=1;i<=b;i++)
	{
		s*=a;
		if(s>p)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<s;
	return 0;
}
