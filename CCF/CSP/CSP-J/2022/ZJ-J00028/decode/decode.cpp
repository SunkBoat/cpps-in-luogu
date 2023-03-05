#include<bits/stdc++.h>
using namespace std;
long long t,a,b,c;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&a,&b,&c);
		long long d=a-b*c+2;
		long long delta=d*d-4*a;
		if(delta>=0){
			long long sqr=sqrt(delta);
			if(sqr*sqr==delta){
				long long x=d-sqr,y=d+sqr;
				if(x>0&&x%2==0&&y>0&&y%2==0){
					printf("%lld %lld\n",x/2,y/2);
					continue;
				}
			}
		}
		printf("NO\n");
	}
	return 0;
}