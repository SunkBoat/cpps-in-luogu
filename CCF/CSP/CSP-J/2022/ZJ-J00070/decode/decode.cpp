#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	int k;
	cin>>k;
	while(k--){
		int n,e,d;
		bool flag=0;
		int p,q;
		cin>>n>>d>>e;
		int m=n-e*d+2;
		for(int i=1;i<=m/2+1;i++){
			p=i;
			q=m-i;
			if(p*q==n){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<p<<" "<<q;
		}
		else{
			cout<<"NO";
		}
		cout<<endl;
	}
	return 0;
}
