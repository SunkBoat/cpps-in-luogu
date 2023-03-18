#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,x,y,z,t,l,r,mid,ans;
int main()
{
    freopen("decode.in","r",stdin);
    freopen("decode.out","w",stdout);
    scanf("%lld",&t);
    while (t--)
      {
      	scanf("%lld%lld%lld",&n,&x,&y);
      	m=n-x*y+2;
      	l=1;
      	r=m/2;
		while (l<=r)
		  {
		  	mid=(l+r)/2;
			if (mid*(m-mid)<n) 
			  {
			  	l=mid+1;
			  } 
			else 
			  {
			  	ans=mid;
			  	r=mid-1;
			  }
		  } 
		if (ans*(m-ans)==n) printf("%lld %lld\n",ans,m-ans); else printf("NO\n");
	  }
	return 0;
} 
