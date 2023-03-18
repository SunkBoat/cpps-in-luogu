#include<bits/stdc++.h>
using namespace std;
long long m,n,p,q;
int g();
int g(){
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			p=i;
			q=n/i;
			if(p+q==m){
				printf("%ld %ld\n",p,q);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	long long k,d,e;
	scanf("%ld",&k);
	while(k--){
		scanf("%ld%ld%ld",&n,&d,&e);
		m=n+2-(e*d);
		g();
	}
	return 0;
}