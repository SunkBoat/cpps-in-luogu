#include<bits/stdc++.h>
using namespace std;
long long a,b,t;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	t=a;
	for(int i=1;i<b;i++){
		t*=a;
		if(t>1e9){
			cout<<-1;
			return 0;
		}
	}
	cout<<t;
	return 0;
}
