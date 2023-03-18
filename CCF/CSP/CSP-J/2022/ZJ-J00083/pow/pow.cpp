#include<bits/stdc++.h>
using namespace std;
const int maxmax = 1e9;
long long a,b;
long long poww(long long a,long long b){
	long long res = 1,base = a;
	while(b>0){
		if(b&1 == 1){
			if(base>maxmax)	return -1;
			res *= base;
		}
		base*=base;
		b/=2;
		if(res>maxmax)	return -1;
	}
	return res;	
}
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	if(b == 1){
		if(a>maxmax){
			printf("-1");
			return 0;
		}
		else{
			printf("%lld",a);
			return 0;
		}
	}
	printf("%lld",poww(a,b));
	return 0;
}
