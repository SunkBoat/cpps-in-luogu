#include<bits/stdc++.h>
using namespace std;
long long a,b,ans=1;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	
	scanf("%lld%lld",&a,&b);
	
	for(long long i=1;i<=b;i++)
	{
		ans*=a;
		if(ans>1e+9)
		{
			ans=-1;
			break;
		}	
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
