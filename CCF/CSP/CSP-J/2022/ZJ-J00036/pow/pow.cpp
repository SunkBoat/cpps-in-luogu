#include <bits/stdc++.h>
using namespace std;

long long a,b,s=1;
bool t=1;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld %lld",&a,&b);
	if(a==1)
	{
		printf("1\n");
	}
	else
	{
		s=1;
		t=1;
		for(int i=1;i<=b;i++)
		{
			s*=a;
			if(s>1e9)
			{
				t=0;
				break;
			}
		}
		if(t==0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n",s);
		}
	}
	return 0;
}
