#include<bits/stdc++.h>
#define int long long
using namespace std;
char c[1000100];
int bh[1000100];
int tot1,tot2;
stack<int> s;
int chuli(int l,int r){
	for(int i=l;i<=r;i++){
		if(c[i]=='|'){
			int x=chuli(l,i-1);
			if(x==1) {
				tot1++;
				return 1;
			}else{
				return x|chuli(i+1,r);
			}
		}
	}
	for(int i=l;i<=r;i++){
		if(c[i]=='&') {
			int x=chuli(l,i-1);
			if(x==0) {
				tot2++;
				return 0;
			}else{
				return x&chuli(i+1,r);
			}
		}
	}
	return c[l]-'0';
}
signed main() {
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>c;
	printf("%lld\n",chuli(0,strlen(c)-1));
	printf("%lld %lld\n",tot2,tot1);
	return 0;
}
