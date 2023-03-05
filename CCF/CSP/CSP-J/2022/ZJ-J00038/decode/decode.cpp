#include<bits/stdc++.h>
using namespace std;
long long m,n[100005],e[100005],d[100005],p,q,j;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&n[i],&d[i],&e[i]);
	for(long long i=1;i<=m;i++)
	{
		for(j=1;j<=sqrt(n[i]);j++)
		{
			if(n[i]%j==0)
				p=j,q=n[i]/j;
			if(e[i]*d[i]==(p-1)*(q-1)+1)
			{
				printf("%lld %lld\n",p,q);
				break;	
			}
		}
		if(j>sqrt(n[i]))
			cout<<"NO"<<endl;
	}
	return 0;
}