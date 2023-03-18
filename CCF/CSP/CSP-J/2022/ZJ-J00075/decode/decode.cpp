#include<bits/stdc++.h>
using namespace std;
long long k;
unsigned long long n,a,b;
unsigned long long a1[10000005],b1[10000005];
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k--)
	{
		bool r=1;
		memset(a1,0,sizeof a1);
		memset(b1,0,sizeof b1);
		cin>>n>>a>>b;
		long long o=0;
		unsigned long long sum=a*b;
		for(int i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				o++;
				a1[o]=i;
				b1[o]=n/i;
			}
		}
		for(int i=1;i<=o;i++)
		{
			if((a1[i]-1)*(b1[i]-1)+1==sum&&k==1)
			{
				r=0;
				cout<<a1[i]<<" "<<b1[i];
				break;
			}
			else if((a1[i]-1)*(b1[i]-1)+1==sum)
			{
				r=0;
				cout<<a1[i]<<" "<<b1[i]<<endl;
				break;
			}
		}
		if(r) cout<<"NO"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
