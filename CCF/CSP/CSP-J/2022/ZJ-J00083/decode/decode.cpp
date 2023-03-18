#include<bits/stdc++.h>
using namespace std;
long long k,n,e,d;
//60pts
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	while(k--){
		scanf("%lld %lld %lld",&n,&e,&d);
		bool flag = 0;
		long long sqr = sqrt(n),res = e*d;
		for(long long i = 1;i<=sqr;i++){
			if(n%i == 0){
				long long b = n/i;
				if(res == (b-1)*(i-1)+1){
					printf("%lld %lld\n",i,b);
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0){
			printf("NO\n");
		}
	}
	return 0;
}
