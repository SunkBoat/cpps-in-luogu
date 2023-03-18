#include<bits/stdc++.h>
using namespace std;
long long n,m,t=1,inf=1e9;
long long pw(){
	if(n==1)return 1;
	while(m--){
		t*=n;
		if(t>inf)return -1;
	}
	return t;
}
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",pw());
    return 0;
}