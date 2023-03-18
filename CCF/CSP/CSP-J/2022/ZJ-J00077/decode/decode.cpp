#include<bits/stdc++.h>
using namespace std;
int k;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k--){
		long long n,e,d;
		bool flag=0;
		scanf("%lld %lld %lld",&n,&e,&d);
		if(d*e>n){
			printf("NO\n");
			continue;
		}
		for(long long i=2;i<=sqrt(n);i++)
			if(n%i==0)
				if(n-i-(n/i)+2==e*d)
				{
					printf("%d %d\n",i,n/i);
					flag=1;
					break;
				}
		if(!flag){
			printf("NO\n");
		}
	}
	return 0;
}