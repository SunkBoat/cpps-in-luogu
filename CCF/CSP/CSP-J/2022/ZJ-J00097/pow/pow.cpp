#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	if(a==1){
		cout<<1;
		return 0;
	}
	if(b>50000000){
		cout<<-1;
		return 0;
	}
	long long s=1;
	for(int i=1;i<=b;i++){
		s*=a;
		if(s>1000000000){
			cout<<-1;
			return 0;
		}
	}
	cout<<s;
}
