#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);	
	cin>>n>>m;
	x=n;
	for(int i=1;i<m;i++){
		n*=x;
		if(n>1000000000){
			cout<<-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}