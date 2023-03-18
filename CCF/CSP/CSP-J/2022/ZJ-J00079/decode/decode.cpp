#include<bits/stdc++.h>
using namespace std;
long long n,e,d;
int _;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%d",&_);
	while(_--){
		scanf("%lld%lld%lld",&n,&e,&d);
		e=n+2-e*d;
		if(e*e<n*4){printf("NO\n");continue;}
		long long p=(e-(long long)sqrt(e*e-n*4))>>1,q=e-p;
		if(p+q!=e||p*q!=n)printf("NO\n");
		else printf("%d %d\n",p,q);
	}
    return 0;
}
