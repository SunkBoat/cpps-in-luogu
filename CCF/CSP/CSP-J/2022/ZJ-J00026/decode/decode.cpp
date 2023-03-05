#include<bits/stdc++.h>
#define ll long long
using namespace std;
int k;
ll n,e,d;
ll drt;
ll p,q;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>n>>e>>d;
		//panbieshi
		drt=(e*d-n-2)*(e*d-n-2)-4*n;
		if(drt<0){
			cout<<"NO\n";
			continue;
		}
		drt=sqrt(drt);
		q=((2+n-e*d)+drt)/2;
		if(q<=0){
			cout<<"NO\n";
			continue;
		}
		if(n%q==0){
			p=n/q;
			if(n==p*q&&e*d==(p-1)*(q-1)+1){
				cout<<min(p,q)<<' '<<max(p,q)<<endl;
				continue;
			}
		}
		q=((2+n-e*d)-drt)/2;
		if(q<=0){
			cout<<"NO\n";
			continue;
		}
		if(n%q==0){
			p=n/q;
			if(n==p*q&&e*d==(p-1)*(q-1)+1){
				cout<<min(p,q)<<' '<<max(p,q)<<endl;
				continue;
			}
		}
		cout<<"NO\n";
	}
	return 0;
}