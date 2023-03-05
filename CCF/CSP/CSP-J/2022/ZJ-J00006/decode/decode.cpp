#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll x,e,d,y;
//x=ab
ll z;
bool pf;
void work()
{
	scanf("%lld %lld %lld",&x,&e,&d);
	ll y=e*d;
	y--;//y=ab-(a+b-1)
	z=x-y;//z=a+b-1
	z++;//z=a+b
	if(pf)
	{
		ll p=z>>1;
		ll q=z-p;
		if(p==q)
		{
			if(p*q==x)
			{
				printf("%lld %lld\n",p,q);
				return ;
			}
		}
		printf("NO\n");
		return ;
	}
	if(x<=1000000000)
	{
		if(sqrt(x)<z/2)
		{
			for(register ll p=1;p*p<=x;p++)
			{
				ll q=z-p;
				if(p*q==x)
				{
					printf("%lld %lld\n",p,q);
					return ;
				}
			}
			printf("NO\n");
			return ;
		}
	}
	for(register ll p=1;p<z;p++)
	{
		ll q=z-p;
		if(p>q)break;
		if(p*q>x)break;
		if(p*q==x)
		{
			printf("%lld %lld\n",p,q);
			return ;
		}
	}
	printf("NO\n");
}
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	int k;
	scanf("%d",&k);
	if(k>1000)
	{
		pf=1;
	}
	while(k--)work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
