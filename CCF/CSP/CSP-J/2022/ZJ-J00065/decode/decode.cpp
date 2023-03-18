#include<bits/stdc++.h>
using namespace std;

int m;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	int k; 
	scanf("%d",&k);
	for(int s=1;s<=k;s++)
	{
		long long n,e,d;
		scanf("%lld%lld%lld",&n,&e,&d);
		m=n-e*d+2;
		if(n<=(int)1e9)
		{
			int f=0;
			for(long long i=1;i<=sqrt(n);i++)
			{
				if(n%i==0)
				{
					if(n-i-n/i+2==e*d)
					{
						cout<<i<<" "<<n/i<<"\n";
						f=1;
						break;
					}
				}
			}
			if(!f)cout<<"NO"<<"\n";
		}
		else
		{
			int l=1,r=m,best=-1;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(1LL*mid*(m-mid)==n)
				{
					best=mid;
					break;
				}
				else if(1LL*mid*(m-mid)<n)
				{
					l=mid+1;
				}
				else
				{
					r=mid-1;
				}
			}
			if(best!=-1)
			{
				cout<<min(best,m-best)<<" "<<max(best,m-best)<<"\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
	}
	return 0;
}
/*10
37419524665037303 73 512596221121434
11367938665125297 1 11367938440873457
67225338047241216 2 33612668763586009
494290568763036724 89 5553826615228187
34094733495998211 59 577876832089911
24591514588938866 47 523223707207295
31702418064468258 3 10567472562950389
19616506255877370 51 384637370332039
52189091957852837 3 17396363837426503
39041360989577928 4 9760340027619187
*/
