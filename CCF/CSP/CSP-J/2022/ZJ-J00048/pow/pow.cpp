#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define ll long long
using namespace std;
ll a,b;
ll quickpow(int a,int b){
	ll u=a,v=1;b--;
	while(b){
		if(b&1){
			b--;
			v*=a;
		}
		else{
			b>>=1;
			u*=u;
		}
		if(u*v>1000000000) return -1;
	}
	return u*v;
}
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	cout<<quickpow(a,b);
	return 0;
}