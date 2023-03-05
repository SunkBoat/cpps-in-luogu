#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	long long T;
	cin>>T;
	if(T>100000)
	while(T--)
	{
		long long n,e,d;
		scanf("%lld%lld%lld",&n,&e,&d);
		long long temp=sqrt(n);
		if(temp*temp!=n)
		{
			printf("NO\n");
			continue;
		}
		temp--;
		temp*=temp;
		temp++;
		e*=d;
		if(temp==e)
			printf("%lld %lld\n",temp,temp);
		else
			printf("NO\n");
	}
	else
	while(T--)
	{
		long long n,e,d;
		scanf("%lld%lld%lld",&n,&e,&d);
		long long temp=e*d;
		bool flag=true;
		for(long long i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				long long t1=n/i-1;
				long long t2=i-1;
				t1*=t2;
				t1++;
				if(temp==t1)
				{
					t1=n/i;
					printf("%lld %lld\n",i,t1);
					flag=false;
					break;
				}
			}
		}
		if(flag)
			printf("NO\n");
	}
	return 0;
}