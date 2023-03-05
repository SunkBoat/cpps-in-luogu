#include<bits/stdc++.h>
using namespace std;
long long k,n,e,d,m,l,r,mid,bj;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	for(int i=1;i<=k;i++){
		scanf("%lld%lld%lld",&n,&e,&d);
		m=n-e*d+2;
		l=1;r=m/2;bj=0;
		while(l<=r){
			mid=(l+r)/2;
			if(mid*(m-mid)==n){
				printf("%d %d\n",mid,m-mid);
				bj=1;
				break;
			}
			if(mid*(m-mid)>n) r=mid-1;
			if(mid*(m-mid)<n) l=mid+1;
		}
		if(bj==0){
			printf("NO\n");
		}
	}
}
