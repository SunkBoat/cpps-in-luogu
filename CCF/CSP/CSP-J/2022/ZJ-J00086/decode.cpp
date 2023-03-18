#include<bits/stdc++.h>
using namespace std;
long long k,n,d,e;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	while(k--){
		scanf("%lld%lld%lld",&n,&d,&e);
		long long n1=n-d*e+2,sq=sqrt(n);
		bool flag=false;
		for(long long p=1;p<=(n1>>1)&&p<=sq;p++){
			if(p*(n1-p)==n){
				printf("%lld %lld\n",p,n1-p);
				flag=true;
				break;
			}
		}
		if(!flag){
			printf("NO\n");
		}
	}
	return 0;
}

