#include<bits/stdc++.h> 
using namespace std;

long long a,b,c;

int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	if(a==1){
		cout<<1<<"\n";
		return 0; 
	} 
	c=1;
	for(int i=1; i<=b; i++){
		c=c*a;
		if(c>1e9){
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<c<<"\n";
	return 0;
}
