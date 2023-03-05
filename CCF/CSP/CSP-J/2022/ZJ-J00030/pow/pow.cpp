#include<bits/stdc++.h>
using namespace std;
long long a,b,res=1;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	while(b>=1){
		if(res*a>1e9){
			cout<<"-1";
			return 0;
		}
		res*=a;
		b--;
	}
	cout<<res<<endl;
	return 0;
}