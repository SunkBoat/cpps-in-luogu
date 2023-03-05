#include<bits/stdc++.h>
using namespace std;
long long a,b,p;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	p=a;a=1;
	while(b){
		if(b&1) a*=p;
		p*=p,b>>=1;
		if(a>1e9){
			cout<<-1;
			return 0;
		}
	}
	cout<<a;
	return 0;
}