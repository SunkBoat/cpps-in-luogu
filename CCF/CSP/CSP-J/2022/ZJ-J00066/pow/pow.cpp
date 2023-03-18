#include<bits/stdc++.h>
using namespace std;
long long a,b,ans=1;;
int main(){
freopen("pow.in","r",stdin);freopen("pow.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	if(a==1)printf("1");
	else if(b>=30||a>1000000000)printf("-1");
	else {
		for(int i=1;i<=b;i++){
			ans=ans*a;
			if(ans>1000000000){printf("-1");return 0;}
		}
		printf("%lld",ans);
	}
	return 0;
}
