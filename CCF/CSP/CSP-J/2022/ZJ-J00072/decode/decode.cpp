#include<bits/stdc++.h>
using namespace std;
long long t,a,b,c,x,tt;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		x=a-b*c+2;
		if(x<2){
			cout<<"NO"<<endl;
			continue;
		}
		long long l=0,r=x/2,mid;
		bool flag=1;
		while(l<=r){
			mid=(l+r)/2;
			tt=mid*(x-mid);
			if(tt==a){
				flag=0;
				cout<<mid<<" "<<x-mid<<endl;
				break;
			}
			if(tt>a) r=mid-1;
			else l=mid+1;
		}
		if(flag) cout<<"NO"<<endl;
	}
	return 0;
}
