#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define ll long long
using namespace std;
ll k;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	For(i,1,k){
		ll n,e,d;
		cin>>n>>e>>d;
		ll sum=n-e*d+2;
		ll aba=sqrt(n);
		bool is=0;
		ll l=1,r=aba;
		while(l<=r){
			ll i=(l+r)>>1;
			ll j=sum-i;
			if(i*j==n){
				is=1;
				if(i>j) i^=j^=i^=j;
				cout<<i<<" "<<j<<endl;
				break;
			}
			else if(i*j<n) l=i+1;
			else r=i-1;
		}
		if(is==0) cout<<"NO"<<endl;
	}
	return 0;
}