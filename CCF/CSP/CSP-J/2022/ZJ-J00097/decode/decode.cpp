#include<bits/stdc++.h>
using namespace std;
int k;
long long n,e,d;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>n>>e>>d;
		long long m=n-e*d+2;
		bool f=0;
		for(long long p=1;p<=m/2;p++){
			if(p>sqrt(n))break;
			if(p*(m-p)==n){
				cout<<p<<" "<<m-p<<endl;
				f=1;
				break;
			}
		}
		if(f==0)cout<<"No\n";
	}
}
