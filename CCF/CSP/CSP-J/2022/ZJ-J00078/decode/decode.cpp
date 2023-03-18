#include<bits/stdc++.h>
using namespace std;
int k;
long long n,e,d,p,q;
long long read()
{
	char ch=getchar();
	while((ch<'0')||(ch>'9'))
	{
		ch=getchar();
	}
	long long f=0;
	while((ch>='0')&&(ch<='9'))
	{
		f=f*10+(ch-'0');
		ch=getchar();
	}
	return f;
}
int main ()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%d",&k);
	while(k--)
	{
		n=read();e=read();d=read();
		long long a=n-e*d+2,b=n;
		if(a<0)
		{
			printf("NO\n");
			continue;
		}
		long long p=a*a-4*b,q=sqrt(p);
		if(q*q!=p)
		{
			printf("NO\n");
			continue;
		}
		printf("%lld %lld\n",(a-q)/2,(a+q)/2);
	}
}
