#include <iostream>
#include <cstdio>
using namespace std;
long long a,b,sum=1;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout); 
	scanf("%lld%lld",&a,&b);
	if(a==1)
		printf("1");
	else
	{
		for(int i=1;i<=b;i++)
		{
			sum*=a;
			if(sum>1e9)
			{
				printf("-1");
				return 0;
			}
		}
		printf("%lld",sum);
	}
	return 0;
}
