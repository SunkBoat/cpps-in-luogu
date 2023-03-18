#include<bits/stdc++.h>
using namespace std;

long long a,b;
long long sum=1;

int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	if(a==1){printf("1\n");return 0;}
	if(a==0){printf("0\n");return 0;}
	for(int i=1;i<=b;i++)
	{
		sum*=a;
		if(sum>1e9)
		{
			sum=-1;
			break;
		}
	}
	printf("%lld\n",sum);
	return 0;
}