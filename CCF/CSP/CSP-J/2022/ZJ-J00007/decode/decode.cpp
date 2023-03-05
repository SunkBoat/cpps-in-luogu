#include<bits/stdc++.h>
using namespace std;
long long k,n,e,d,m,mid;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	for(int i=1;i<=k;i++){
		scanf("%lld%lld%lld",&n,&e,&d);
		m=n-e*d+2;
		bool flag=0;
		long long l=1,r=m/2;
		while(l<=r){
			mid=(l+r)/2;
			if(mid*(m-mid)==n){
				printf("%d %d\n",mid,m-mid);
				flag=1;
				break;
			}
			else{
				if(mid*(m-mid)>n)r=mid-1;
				else l=mid+1;
			}
		}
		if(flag==0)printf("NO\n");
	}
}
