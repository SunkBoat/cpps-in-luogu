#include<iostream>
using namespace std;
#define ll long long
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	ll a,b,ans=1;
	cin>>a>>b;
	if(a==1)cout<<1;
	else if(b>31)cout<<-1;
	else {
		for(int i=0;i<b;i++){
			ans*=a;
			if(ans>1e9){
				cout<<-1;
				return 0;
			}
		}
		cout<<ans;
	}
	return 0;
}
