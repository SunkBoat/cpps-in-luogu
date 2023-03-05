#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	
	scanf("%lld%lld",&a,&b);
	long long ans=1;
	for(int i=1;i<=b;i++){
		ans*=a;
		if(ans>1e9){
			ans=-1;
			break;
		}
	}
	printf("%lld",ans);
}