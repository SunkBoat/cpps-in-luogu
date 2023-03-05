#include<iostream>
#include<stdio.h>
using namespace std;
const long long Max=1e9;
long long a,b;//a^b
void f(long long x){
	if(x>Max){
		printf("-1");
		exit(0);
	}
}
long long fast_pow(long long x){
	if(x==0) return 1;
	if(x==1) return a;
	long long now=fast_pow(x/2);
	f(now);
	now=now*now;
	f(now);
	if(x%2==1) now=now*a;
	f(now);
	return now;
}

signed main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	long long ans=fast_pow(b);
	f(ans);
	printf("%lld",ans);
	return 0;
}
