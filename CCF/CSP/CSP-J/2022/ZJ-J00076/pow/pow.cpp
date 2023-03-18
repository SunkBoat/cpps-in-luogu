#include<bits/stdc++.h>
using namespace std;
const long long INF=(long long)(1e9);
long long a,b,num=0;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	num=a;
	while(--b){
		num*=a;
		if(num>INF){
			cout<<"-1";
			return 0;
		}
	}
	cout<<num<<endl;
	return 0;
}
