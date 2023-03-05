#include<bits/stdc++.h>
using namespace std;
long long ans=1,a,b;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	if(a==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=b;i++){
		ans*=a;
		if(ans>1e9){
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}

