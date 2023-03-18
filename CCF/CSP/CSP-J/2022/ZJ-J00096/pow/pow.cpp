#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	int a,b;
	scanf("%lld %lld",&a,&b);
	int sum=1;
	for(int i=1;i<=b;i++){
		sum*=a;
		if(sum>1e9) {
			printf("-1");
			return 0;
		}
	}
	printf("%lld\n",sum);
	return 0;
}
