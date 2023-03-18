#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	int a,b;
	cin>>a>>b;
	long long s=1;
	for(int i=1;i<=b;i++){
		s*=a;
		if(s>1000000000){
			cout<<-1;
			return 0;
		}
	}
	cout<<s;
	return 0;
}
