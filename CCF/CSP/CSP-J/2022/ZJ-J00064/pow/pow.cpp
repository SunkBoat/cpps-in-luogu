#include<bits/stdc++.h>
using namespace std;
int a,b;
long long ans=1;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin >> a >> b;
	for(int i=1;i<=b;i++){
		ans*=a;
		if(ans > 1e+9){
			cout<< -1 ;
			return 0 ;
		}
	}
	cout << ans ;
	
	return 0;
}
