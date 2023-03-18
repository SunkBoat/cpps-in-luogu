#include<bits/stdc++.h>
using namespace std;
long long a,b,s=1;
int main ()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	if(a==1)
	{
		printf("1");
		return 0;
	}
	for(int i=1;i<=b;i++)
	{
		s*=a;
		if(s>1e9)
		{
			printf("-1");
			return 0;
		}
	}
	printf("%lld",s);
}
