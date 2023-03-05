#include<bits/stdc++.h>
using namespace std;
long long a,b;
const long long INF=1e9;

long long fast_pow(long long x,long long p){
	long long unit=x,ans=1;
	while( p ){
		if( ans>INF )
			return -1;
		if( p&1 )
			ans*=unit;
		unit*=unit;
		p>>=1;
	}
	if( ans>INF )
		return -1;
	return ans;
}

int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	printf("%lld",fast_pow(a,b));
	return 0;
}
