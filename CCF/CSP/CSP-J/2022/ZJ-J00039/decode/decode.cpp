#include<bits/stdc++.h>
using namespace std;
long long n,e,d,p,q,ed;
int K;
/*bool chec()
{
	if(e*d-1==(p-1)*(q-1))return true;
	else return false;
}*/
int main()
{
	
	
	
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	
	
	
	scanf("%d",&K);
	while(K--)
	{
		//int fl=0;
		scanf("%lld%lld%lld",&n,&e,&d);
		/*if(n)
		long long m=sqrt(n);
		for(long long i=1;i<=n;i++)
		{
			p=i;
			q=n/i;
			if(n==p*q)
			{
				if(chec())
				{
					fl=1;
					break;
				}
			}
		}
		if(fl)
		{
			printf("%lld %lld\n",p,q);
		}
		else
		{
			printf("NO\n");
		}*/
		//long long js1,js2,js3;
		ed=e*d;
		if(ed/d!=e||sqrt((n-ed+2)*(n-ed+2)-4*n)*sqrt((n-ed+2)*(n-ed+2)-4*n)!=(n-ed+2)*(n-ed+2)-4*n)
		{
			printf("NO\n");
			continue;
		}
		else
		{
			p=n-ed+2-sqrt((n-ed+2)*(n-ed+2)-4*n);
			if(p%2==1)
			{
				printf("NO\n");
				continue;
			}
			p/=2;
			q=n/p;
			printf("%lld %lld\n",p,q);
		}
	}
	return 0;
} 
/*
CCF,if you give me 100 pts,I will give you 10^-9 yuan.
*/