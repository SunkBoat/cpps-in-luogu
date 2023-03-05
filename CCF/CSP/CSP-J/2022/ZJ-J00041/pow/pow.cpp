#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	long long a,b,t;
	cin>>a>>b;
	t=a;
	if(a==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<b;i++){
		a*=t;
		if(a>1000000000){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<a<<endl;
	return 0;
}
