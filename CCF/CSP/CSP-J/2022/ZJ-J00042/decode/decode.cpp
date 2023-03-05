#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL k,n,a,b;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k--){
		scanf("%lld%lld%lld",&n,&a,&b);
		int flag=0;
		LL c=n-a*b+2;
		LL r=c/2,l=1;
		while(l<=r){
			LL mid=(l+r)>>1;
			LL p=c-mid;
			if(p*mid==n){
				flag=1;
				printf("%lld %lld\n",mid,p);
//				cout<<mid<<" "<<p<<endl;
				break;
			}
			else if(p*mid<n) l=mid+1;
			else r=mid-1;
		}
		if(!flag){
			puts("NO");
		}
	}
	return 0;
}

