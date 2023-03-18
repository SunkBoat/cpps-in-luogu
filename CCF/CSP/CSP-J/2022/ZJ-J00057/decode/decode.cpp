#include<bits/stdc++.h>
using namespace std;
#define ll long long
int k;
ll n,d,e;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%lld%lld%lld",&n,&d,&e);
		ll ans=n-d*e+2;//ans = p + q ; n = p * q ;
		ll l=sqrt(n);// 26
		bool flag=0;// 5 4
		for(ll i=l;i>=1;i--)
		{
			if(n%i==0)
			{
				if(i+n/i==ans)
				{
					flag=1;
					printf("%lld %lld\n",i,n/i);
					break;
				}
				else if(i+n/i>ans){
					printf("NO\n");
					break;
				}
			}
		}
//		if(flag)
	}
}
