#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,n,d,e,p,q;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)) {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
bool xx(int sum) {
	for(int i=1; i*i<=n; ++i) {
		if(n%i==0&&i+n/i==sum) {
			p=i,q=n/i;
			return 1;
		}
	}
	return 0;
}
signed main() {
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	k=read();
	for(int i=1; i<=k; ++i) {
		n=read(),d=read(),e=read();
		int sum=n+2-e*d;
		if(!xx(sum))puts("NO");
		else printf("%lld %lld\n",p,q);
	}
}
