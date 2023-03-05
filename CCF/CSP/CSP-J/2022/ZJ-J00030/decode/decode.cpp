#include<bits/stdc++.h>
#define int long long
using namespace std;
int k;
signed main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	while(k--){
		int n,d,e;
		scanf("%lld%lld%lld",&n,&d,&e);
		int mod=e*d-1;
		bool flag=0;
		for(int i=1;i*i<=n;i++){
			if(n%i==0){
				if((i-1)*(n/i-1)==mod){
					flag=1;
					printf("%lld %lld\n",i,n/i);
					break;
				}
			}
		}
		if(!flag) printf("NO\n");
	}
}