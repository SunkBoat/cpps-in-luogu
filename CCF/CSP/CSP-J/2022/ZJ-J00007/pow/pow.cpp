#include<bits/stdc++.h>
using namespace std;
long long a,b,ans;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	if(a==1){
		cout<<'1';
		return 0;
	}
	ans=1;
	for(int i=1;i<=b;i++){
		ans*=a;
		if(ans>1000000000){
			cout<<"-1";
			return 0;
		}
	}
	cout<<ans;
}
