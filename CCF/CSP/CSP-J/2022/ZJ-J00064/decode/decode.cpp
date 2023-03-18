#include<bits/stdc++.h>
using namespace std;
int k;
long long n,e,d,p,q,ed;
bool tp;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin >> k;
	for(int i=1;i<=k;i++){
		tp = 1;
		cin >> n >> e >> d ;
		ed = e*d;
		for(int j=1;j*j<n;j++){
			if(n%j==0){
				p=j;
				q=n/j;
				if((p-1) * (q-1)+1 == ed){
					cout << p << ' ' << q << endl;
					tp = 0;
				}
			}
		}
		 if(tp) cout << "NO" << endl;
	}
	
	
	return 0;
}
