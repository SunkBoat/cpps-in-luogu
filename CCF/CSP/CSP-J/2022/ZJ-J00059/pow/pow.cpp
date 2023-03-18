#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,i,j,k;
int main()
{
    freopen("pow.in","r",stdin);
    freopen("pow.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if (n==1)
      {
      	printf("1");
      	return 0;
	  }
	if (m>10000)
	  {
	  	printf("-1");
	  	return 0;
	  }
    sum=1;
    for (i=1;i<=m;i++)
      {
      	sum=sum*n;
      	if (sum>1000000000)
      	  {
      	  	printf("-1");
      	  	return 0;
		  }
	  }
    printf("%lld",sum);
	return 0;
}
