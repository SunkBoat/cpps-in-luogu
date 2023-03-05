#include<bits/stdc++.h>
using namespace std;
const long long big=1e9;
long long a,b;
long long qpow(int k){
	if(k==1)	return a;
	long long res=qpow(k/2);
	if(res==-1)	return -1;
	res*=res;
	if(res>big)	return -1;
	if(k%2==1){
		res*=a;
		if(res>big)	return -1;
		return res;
	}
	return res;
}
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	cout<<qpow(b);
	return 0;
} //remember to delete "//" of freopen!!!
