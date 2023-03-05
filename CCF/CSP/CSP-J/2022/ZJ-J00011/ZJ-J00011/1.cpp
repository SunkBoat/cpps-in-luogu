#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	unsigned long long a,b,ans=1;
	cin>>a>>b;
	if(a==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=b;i++){
		ans*=a;
		if(ans>pow(10,9)){
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
	return 0;
} 
