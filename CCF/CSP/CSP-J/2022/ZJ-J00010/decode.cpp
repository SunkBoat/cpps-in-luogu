#include<bits/stdc++.h>
using namespace std;
long long k,n,d,e,m,a;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k--){
		bool ok = false;
		cin>>n>>d>>e;
		a = e*d;
		m = n-a+2;
		for(int i = 1;i*i <= n && i < m;i++){
			if(i*(m-i) == n && (i-1)*(m-i-1)+1 == a){
				ok = true;
				cout<<i<<' '<<m-i<<endl;
				break;
			}
		}
		if(!ok) cout<<"NO"<<endl;
	}
	return 0;
}
