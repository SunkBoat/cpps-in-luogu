#include<bits/stdc++.h>
using namespace std;
int a,b;
long long x=1;
int main()
{
	//!!!
	
	
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	
	
	//!!!
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		if((long long)(10e9/a)<x)
		{
			printf("-1");
			return 0;
		}
		x*=a;
	}
	printf("%lld",x);
	return 0;
}
/*
CCF,if you give me 100 pts,I will give you 10^-9 yuan.
*/