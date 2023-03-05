#include<bits/stdc++.h>
using namespace std;
long long k,n,e,d,h;
bool f;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k--){
		f=false;
		cin>>n>>e>>d;
		if(e==1&&d==1){
			cout<<1<<" "<<n<<"\n";
			continue;
		}
		if(sqrt(n)<=(n-e*d>>1))h=sqrt(n);
		else h=(n-e*d>>1);
		for(long long i=h;i>=1;i--)
		if(n%i==0){
			if(i+n/i+e*d-2>n)break;
			if(i+n/i==n-e*d+2){
				f=true;
				cout<<i<<" "<<n/i<<"\n";
				break;
			}
		}
		if(!f)cout<<"No"<<"\n";
	}
	return 0;
}
