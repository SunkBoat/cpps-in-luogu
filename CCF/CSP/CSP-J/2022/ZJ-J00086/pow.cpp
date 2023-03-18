#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	long long ans=1;
	while(b>0){
		if(b&1){
			ans*=a;
		}
		b/=2;
		a*=a;
		if(ans>1000000000){
			cout<<-1;
			return 0;
		}
	}
	printf("%lld",ans);
	return 0;
}

