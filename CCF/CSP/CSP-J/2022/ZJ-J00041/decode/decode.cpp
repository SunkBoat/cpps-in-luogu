#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,e,i,d,a,delta,ge;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k--){
		cin>>n>>e>>d;
		a=2+n-e*d;
		delta=a*a-4*n;
		ge=sqrt(delta);
		if(delta<0){
			cout<<"NO\n";
			continue;
		}
		if(delta!=ge*ge){
			cout<<"NO\n";
			continue;
		}
		if(((a-ge)%2!=0)||((a+ge)%2!=0)){
			cout<<"NO\n";
			continue;
		}
		cout<<(a-ge)/2<<' '<<(a+ge)/2<<'\n';
	}
	return 0;
}
