#include<bits/stdc++.h>
using namespace std;
long long k;

inline bool check(double x){
	if( x-int(x)>1e-8 )
		return 1;
	return 0;
}

int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	for(int i=1;i<=k;i++){
		long long n,e,d,m,deta,p,q;
		scanf("%lld%lld%lld",&n,&e,&d);
		m=n-e*d+2;
		deta=m*m-4*n;
		if( deta<0 || check(sqrt(deta*1.0)) ){
			printf("NO\n");
			continue;
		}
		deta=sqrt(deta);
		if( (m+deta)&1 || (m-deta)&1 ){
			printf("NO\n");
			continue;
		}
		p=(m-deta)/2;
		q=(m+deta)/2;
		if( p>q )
			swap(p,q);
		printf("%lld %lld\n",p,q);
	}
	return 0;
}
