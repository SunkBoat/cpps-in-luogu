#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	LL a,b;
	scanf("%lld %lld",&a,&b);
	LL p=pow(a,b);
	if(p>2000000000||p<0)puts("-1");
	else printf("%lld\n",p);
	return 0;
}

