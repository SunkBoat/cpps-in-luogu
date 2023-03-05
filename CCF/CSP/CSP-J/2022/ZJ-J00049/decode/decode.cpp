#include<bits/stdc++.h>
using namespace std;
long long k,n,d,e;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	
	scanf("%lld",&k);
	while(k--){
		scanf("%lld%lld%lld",&n,&d,&e);
		long long ji=n,he=n-e*d+2,l=1,r=he/2;
		bool flag=true;
		while(l<=r){
			long long mid=(l+r)/2;
			long long another=he-mid;
			if(mid*another==n){
				printf("%lld %lld\n",mid,another);
				flag=false;
				break;
			}
			else if(mid*another>n)r=mid-1;
			else l=mid+1;
		}
		if(flag)printf("NO\n");
	}
}