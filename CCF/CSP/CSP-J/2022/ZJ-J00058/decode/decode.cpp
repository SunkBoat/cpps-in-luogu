#include<bits/stdc++.h>
using namespace std;
long long k,n,d,e,ans,he,ji,x1,x2,o;
double s;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld%lld%lld",&n,&d,&e);
		ji=n;
		he=n-d*e+2;
		s=he*he-4*ji;
		o=sqrt(s);
		x1=(he+sqrt(he*he-4*ji))/2;
		x2=he-x1;
		if(o!=sqrt(s)||x1*x2!=n||(x1-1)*(x2-1)+1!=d*e)
		{
			printf("NO\n");
			continue;
		}
		else
		printf("%lld %lld\n",x2,x1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
