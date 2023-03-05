#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b;
ll c;
int f=0;
ll ksm(ll a,ll b){
	if(f==1){
		return -1;
	}
	if(b==1) return a;
	if(b==2) return a*a;
	ll t=ksm(a,b/2);
	if(t>1000000000||t<0){
		f=1;
		return -1;
	}else{
		if(b%2==1){
			return t*t*a;
		}else{
			return t*t;
		}
	}
}
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	cout<<ksm(a,b);
	return 0;
}