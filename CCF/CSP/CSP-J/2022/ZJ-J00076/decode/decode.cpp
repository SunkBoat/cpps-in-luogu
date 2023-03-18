#include<bits/stdc++.h>
using namespace std;
long long k,n,d,e,num;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	for(long long i=1;i<=k;i++){
		cin>>n>>e>>d;
		int t=0;
		for(long long j=1;j*j<=n;j++){
			if(n%j==0&&e*d==(j-(long long)(1))*(n/j-(long long)(1))+(long long)(1)){
				t=1;
				cout<<j<<" "<<n/j<<endl;
				break;
			}
		}
		if(t==0)cout<<"NO"<<endl;
	}
	return 0;
}
